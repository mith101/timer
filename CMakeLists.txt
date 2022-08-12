cmake_minimum_required(VERSION 3.10)

project(timer VERSION 0.1.0)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/Timer.cpp)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(c${PROJECT_NAME})
target_sources(c${PROJECT_NAME} PRIVATE src/CTimer.c)
target_include_directories(c${PROJECT_NAME} PUBLIC include)

add_executable(test test/main.cpp)
target_sources(test PRIVATE test/Timer.t.cpp test/CTimer.t.cpp)
target_link_libraries(test PRIVATE ${PROJECT_NAME} c${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
        DESTINATION lib
        EXPORT  ${PROJECT_NAME}Targets
)
install(DIRECTORY include/mith TYPE INCLUDE)
install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION lib/cmake/${PROJECT_NAME}
)
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION "lib/cmake/${PROJECT_NAME}"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_NAME}_VERSION
  COMPATIBILITY AnyNewerVersion
)
install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION
    lib/cmake/${PROJECT_NAME}
)
export(EXPORT ${PROJECT_NAME}Targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake"
)
