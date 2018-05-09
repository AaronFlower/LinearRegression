set(Utils_SRC Utils.h Utils.cpp)

add_library(libutils STATIC  ${Utils_SRC})

target_include_directories(libutils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
