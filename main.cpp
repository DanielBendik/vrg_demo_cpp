#define _USE_MATH_DEFINES
#define CATCH_CONFIG_MAIN
#include <cmath>
#include <iostream>
#include "entt/entt-master/src/entt/entt.hpp"
#include <vector>

struct Position {
    double x, y, z;
};

struct Velocity {
    double vx, vy, vz;
};

struct Bullet {
    double weight;
    double muzzle_velocity;
};

struct SimulationState {
    double time_step;
    bool target_hit = false;
    double angle_of_elevation = 0.0;
};

const double GRAVITY = 9.81;

// Function to calculate the angle of elevation
double calculate_angle_of_elevation(const Position& shooter, const Position& target, double muzzle_velocity) {
    double dx = target.x - shooter.x;
    double dy = target.y - shooter.y;
    double dz = target.z - shooter.z;
    double distance = std::sqrt(dx * dx + dy * dy);
    
    // Projectile motion formula
    double theta = std::atan2(dz, distance);
    return theta * 180 / M_PI; // Convert to degrees
}

void simulate_shooting(entt::registry& registry) {
    auto view = registry.view<Position, Bullet, SimulationState>();
    
    for (auto entity : view) {
        auto& shooter_pos = view.get<Position>(entity);
        auto& bullet = view.get<Bullet>(entity);
        auto& state = view.get<SimulationState>(entity);
        
        auto target_view = registry.view<Position>(entt::exclude<Bullet>);
        for (auto target_entity : target_view) {
            auto& target_pos = target_view.get<Position>(target_entity);
            double angle = calculate_angle_of_elevation(shooter_pos, target_pos, bullet.muzzle_velocity);
            state.angle_of_elevation = angle;
            
            // Collision detection based on distance
            double dx = target_pos.x - shooter_pos.x;
            double dy = target_pos.y - shooter_pos.y;
            double dz = target_pos.z - shooter_pos.z;
            double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
            // sin(2*theta)v2/g; max distance is when the angle is 45 degrees
            double max_distance = (bullet.muzzle_velocity * bullet.muzzle_velocity) / GRAVITY;
            
            if (distance <= max_distance) {
                state.target_hit = true;
            }
        }
    }
}

int main() {
    entt::registry registry;

    // Create shooter entity
    auto shooter = registry.create();
    registry.emplace<Position>(shooter, 0.0, 0.0, 0.0);
    registry.emplace<Bullet>(shooter, 0.0052, 360.0); // Weight in kg, velocity in m/s
    registry.emplace<SimulationState>(shooter, 0.01); // Time step in seconds

    // Create target entity
    auto target = registry.create();
    registry.emplace<Position>(target, 50.0, 50.0, 1000.0); // Position in meters

    // Simulate shooting
    simulate_shooting(registry);

    // Output results
    auto view = registry.view<SimulationState>();
    for (auto entity : view) {
        auto& state = view.get<SimulationState>(entity);
        std::cout << "Angle of Elevation: " << state.angle_of_elevation << " degrees\n";
        if (state.target_hit) {
            std::cout << "Target hit.\n";
        } else {
            std::cout << "Target missed.\n";
        }
    }

    return 0;
}