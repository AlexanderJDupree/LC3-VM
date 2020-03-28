cmake_minimum_required(VERSION 3.2)
project(lc3-vm)

set(SOURCE_FILES lc3.c trap.c image.c console.c)

add_executable(lc3 ${SOURCE_FILES})
install(TARGETS lc3 DESTINATION ${LC3_INSTALL_BIN_DIR})