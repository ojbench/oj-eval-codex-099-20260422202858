cmake_minimum_required(VERSION 3.10)
project(problem_099_code CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code main.cpp)

# Optimize for speed and enable reasonable warnings (avoid static link for portability)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(code PRIVATE -O2 -pipe -s -Wall -Wextra)
endif()
