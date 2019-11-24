cmake_minimum_required(VERSION 3.0.0)

include_directories(
    include
)

file(GLOB SRCS src/*.cc)
add_executable(supowit ${SRCS})
