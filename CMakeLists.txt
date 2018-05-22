cmake_minimum_required(VERSION 2.8)

project(soci)
add_definitions(-lsoci_core -lsoci_mysql)
add_executable(${PROJECT_NAME} "main.cpp")
include_directories(/home/zhang/code/soci/include/soci)
include_directories(/usr/include/mysql)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} soci_core)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} soci_mysql)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} soci_sqlite3)
