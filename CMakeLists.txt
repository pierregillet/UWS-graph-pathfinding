cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

project(pathfinding_assignment)

add_executable(pathfinding_assignment
        main.cpp
        UndirectedGraphHelper.cpp UndirectedGraphHelper.h
        IDAStar.cpp IDAStar.h)

find_package(Boost REQUIRED COMPONENTS graph)

target_link_libraries(pathfinding_assignment PRIVATE Boost::graph)

add_custom_command(
        TARGET pathfinding_assignment
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/random64_4_1485816605.dot
        ${CMAKE_CURRENT_BINARY_DIR}/random64_4_1485816605.dot
)
