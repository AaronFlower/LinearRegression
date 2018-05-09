set(Matrix_SRCS matrix.h matrix.cpp)

add_library(libmatrix STATIC  ${Matrix_SRCS})

target_include_directories(libmatrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
