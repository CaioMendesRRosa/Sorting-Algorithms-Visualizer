# Definir a versão mínima do CMake e o nome do projeto
cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms)

# Configurações de compilação
set(CMAKE_CXX_STANDARD 17)       # Define o padrão de C++
set(CMAKE_CXX_FLAGS "-O1 -Wall -Wno-missing-braces")

# Diretórios de include e biblioteca
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Adicionar o executável
add_executable(sortView src/main.cpp src/draw.cpp src/SortingAlgorithms/selectionSort.cpp)

# Ligar as bibliotecas necessárias
target_link_libraries(sortView raylib opengl32 gdi32 winmm)