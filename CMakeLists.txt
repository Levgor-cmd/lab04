cmake_minimum_required(VERSION 3.10)
project(lab04)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем библиотеку print
add_library(print STATIC sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Собираем пример (если есть)
add_executable(example examples/example.cpp)
target_link_libraries(example print)

# Установка
install(TARGETS print ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

