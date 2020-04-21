cmake_minimum_required(VERSION 3.15)
project(RTv1 C)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(includes)

add_executable(RTv1 src/main.c
        src/main.c
        src/alg.c
        src/init_vec.c
        src/rotate.c
        src/vec_dot.c
        src/vec_norm.c
        src/vec_sum.c
        src/vec_sub.c
        src/vec_scale.c
        src/sphere.c
        src/light.c
        src/plane.c
        src/cylinder.c
        src/cone.c
        src/init_color.c)

target_link_libraries(RTv1 ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2)