cmake_minimum_required(VERSION 3.0.0)
project(ppm_view VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ppm_view src/main.cpp src/window.cpp src/window.h "src/ppm.cpp" "src/ppm.h" "src/log.h")

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(ppm_view PRIVATE SDL2::SDL2 SDL2::SDL2main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
