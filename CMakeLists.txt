cmake_minimum_required(VERSION 3.25)
project(chip8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # wichtig für clangd

find_package(SDL2 REQUIRED)

add_executable(chip8
    src/main.cpp
    src/chip8.cpp
)

target_link_libraries(chip8 PRIVATE SDL2::SDL2)

target_compile_options(chip8 PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow
    -Wconversion -Wsign-conversion
    -Wold-style-cast -Wnull-dereference
)

# Sanitizer fangen Speicherfehler und undefiniertes Verhalten zur Laufzeit
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
      chip8 PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer
    )
  target_link_options(chip8 PRIVATE -fsanitize=address,undefined)
endif()
