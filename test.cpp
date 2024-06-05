#define CATCH_CONFIG_MAIN
//#include "catch2/Catch2-devel/src/catch2/catch_all.hpp"
#include "entt/entt-master/src/entt/entt.hpp"
#include <cmath>
#include "main.cpp"

/*
TEST_CASE("Target Hit Detection", "[simulation]") 
{
    entt::registry registry;

    auto shooter = registry.create();
    registry.emplace<Position>(shooter, 0.0, 0.0, 0.0);
    registry.emplace<Bullet>(shooter, 10.0, 300.0);
    registry.emplace<SimulationState>(shooter, 0.01);

    auto target = registry.create();
    registry.emplace<Position>(target, 1000.0, 0.0, 100.0);

    simulate_shooting(registry);

    auto view = registry.view<SimulationState>();
    for (auto entity : view) {
        auto& state = view.get<SimulationState>(entity);
        REQUIRE(state.target_hit);
    }
}
*/