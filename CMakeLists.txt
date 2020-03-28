cmake_minimum_required(VERSION 3.2)

project(lc3-vm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -O3 -Wall -Werror")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(LC3_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LC3_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

include_directories(${LC3_INSTALL_INCLUDE_DIR})

add_subdirectory(src)