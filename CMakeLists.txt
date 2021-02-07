cmake_minimum_required(VERSION 3.10)

project(timer)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/Timer.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(c${PROJECT_NAME})
target_sources(c${PROJECT_NAME} PRIVATE src/CTimer.c)
target_include_directories(c${PROJECT_NAME} PUBLIC include)

add_executable(test test/main.cpp)
target_sources(test PRIVATE test/Timer.t.cpp test/CTimer.t.cpp)
target_link_libraries(test PRIVATE ${PROJECT_NAME} c${PROJECT_NAME})
