cmake_minimum_required(VERSION 3.14)
project(autoware_behavior_velocity_traffic_light_module)

find_package(autoware_cmake REQUIRED)
autoware_package()
pluginlib_export_plugin_description_file(autoware_behavior_velocity_planner plugins.xml)

ament_auto_add_library(${PROJECT_NAME} SHARED
  src/debug.cpp
  src/manager.cpp
  src/scene.cpp
)

ament_auto_package(INSTALL_TO_SHARE config)

install(PROGRAMS
  scripts/dilemma_zone_plotter.py
  DESTINATION lib/${PROJECT_NAME}
)
