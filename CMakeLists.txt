cmake_minimum_required(VERSION 3.15)

project(merc VERSION 1.0 DESCRIPTION "An optimization and performance focused ActivityPub server.")

find_package(json-c CONFIG)

file(GLOB_RECURSE source_list "src/*.c" "src/database/*.c")
add_executable(${PROJECT_NAME} ${source_list})

target_include_directories(${PROJECT_NAME} PUBLIC "include" )

target_link_libraries(${PROJECT_NAME} pthread pq json-c::json-c)