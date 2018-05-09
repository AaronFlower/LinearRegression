set(SRCS main.cpp)

add_executable(linearReg ${SRCS})

target_link_libraries(linearReg libutils libmatrix)
