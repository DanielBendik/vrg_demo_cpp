# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "c:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-src"
  "c:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-build"
  "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix"
  "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/tmp"
  "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/src/entt-populate-stamp"
  "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/src"
  "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/src/entt-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/src/entt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/xxxfr/Desktop/vrg_demo_cpp/build/_deps/entt-subbuild/entt-populate-prefix/src/entt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
