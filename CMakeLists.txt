cmake_minimum_required(VERSION 3.30)
project(proj)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Myapp)

# исходники
set(sources 
Main.cpp 
MatrixSpiralTraversal.cpp 
MatrixSpiralTraversal.qrc 
MatrixSpiralTraversal.ui
Pseudomatrix.cpp
SpiralTraversalAlgorithm.cpp
stdafx.cpp)

# таргеты
target_sources(Myapp PRIVATE ${sources})
target_link_libraries(Myapp PRIVATE Qt5::Widgets)