cmake_minimum_required ( VERSION 3.10 )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

project( LinearReg )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

message(STATUS "Check flags ${CMAKE_CXX_FLAGS}")

# todo add test check
enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(matrix)
add_subdirectory(utils)
