cmake_minimum_required(VERSION 3.10)

project(function-plotter)

file(GLOB SOURCES *.cpp)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} GL GLU glut)