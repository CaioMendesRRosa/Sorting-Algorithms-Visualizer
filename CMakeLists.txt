cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O1 -Wall -Wno-missing-braces")


include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)


add_executable(sortView src/main.cpp src/draw.cpp src/SortingAlgorithms/selectionSort.cpp src/SortingAlgorithms/quickSort.cpp src/SortingAlgorithms/mergeSort.cpp 
src/SortingAlgorithms/bubbleSort.cpp src/SortingAlgorithms/insertionSort.cpp)

target_link_libraries(sortView raylib opengl32 gdi32 winmm)