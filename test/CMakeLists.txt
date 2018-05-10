# gtest_SOURCE_DIR is availalbe, Because we include gtest library 
# which has project(gtest) above.

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(../matrix)

message (STATUS "Kidding me ${gmock_SOURCE_DIR}")

add_executable(testMatrix testMatrix.cpp)

# Standard linking to gtest stuff
target_link_libraries(testMatrix gtest_main gmock_main libmatrix)

# This is so you can do 'make test' to see all your tests run,
# instead manually running the executable testMatrix to see those specifice tests.

add_test(Linear-Reg-Test testMatrix)
