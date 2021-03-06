#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Matrix.h"
#include <vector>

using testing::ElementsAre;
using testing::DoubleEq;

TEST(Matrix, Initializer_list_ctor) {
    Matrix m1{1,2,3};
    Matrix m2{{1,2,3}, {4, 5, 6}};
    const Matrix m3{{0,-2,3}, {-4, 5, 6}};
    // Using Matrix(initializer_list<initializer_list<double>> constructor
    const Matrix m4 = {{2, 3, 5}, {7, 11, 17}}; 

    ASSERT_THAT(m1.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m2.flatten(), ElementsAre(1, 2, 3, 4, 5, 6)); 
    ASSERT_THAT(m3.flatten(), ElementsAre(0, -2, 3, -4, 5, 6)); 
    ASSERT_THAT(m4.flatten(), ElementsAre(2, 3, 5, 7, 11, 17));
}

TEST(Matrix, Vecotr_ctor) {
    Matrix m1 = Matrix::vec{1,2,3};
    Matrix m2 = Matrix::vvec{{1,2,3}, {4, 5, 6}};
    const Matrix m3 = Matrix::vvec{{0,-2}, {-4, 5}};
    const Matrix m4 = Matrix::vvec{{2, 3, 5}, {7, 11, 17}}; 

    ASSERT_THAT(m1.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m2.flatten(), ElementsAre(1, 2, 3, 4, 5, 6)); 
    ASSERT_THAT(m3.flatten(), ElementsAre(0, -2, -4, 5)); 
    ASSERT_THAT(m4.flatten(), ElementsAre(2, 3, 5, 7, 11, 17));


    ASSERT_THAT(m1.shape(), testing::Pair(3, 1));
    ASSERT_THAT(m2.shape(), testing::Pair(2, 3));
    ASSERT_THAT(m3.shape(), testing::Pair(2, 2));
    ASSERT_THAT(m4.shape(), testing::Pair(2, 3));
}
TEST(Matrix, Initializer_list_assign) {
    Matrix m1, m2, m3;
    m1  = {1, 2, 3};
    m2  = {{1, 2, 3}};
    m3  = {{2, 3, 5}, {7, 11, 17}};

    ASSERT_THAT(m1.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m2.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m3.flatten(), ElementsAre(2, 3, 5, 7, 11, 17));

    ASSERT_THAT(m1.shape(), testing::Pair(3, 1));
    ASSERT_THAT(m2.shape(), testing::Pair(1, 3));
    ASSERT_THAT(m3.shape(), testing::Pair(2, 3));
}

TEST(Matrix, Assign_ctor) {
    Matrix m1, m2, m3, m4;
    m1  = {1, 2, 3};
    m2 = m1;
    m3  = {{2, 3, 5}, {7, 11, 17}};
    m4 = m3;
    m4 = m4;
    ASSERT_THAT(m1.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m2.flatten(), ElementsAre(1, 2, 3)); 
    ASSERT_THAT(m3.flatten(), ElementsAre(2, 3, 5, 7, 11, 17)); 
    ASSERT_THAT(m4.flatten(), ElementsAre(2, 3, 5, 7, 11, 17)); 
    

    ASSERT_THAT(m1.shape(), testing::Pair(3, 1));
    ASSERT_THAT(m2.shape(), testing::Pair(3, 1));
    ASSERT_THAT(m3.shape(), testing::Pair(2, 3));
    ASSERT_THAT(m4.shape(), testing::Pair(2, 3));
}

TEST(Matrix, Copy_ctor) {
    Matrix m1 = {1, 2, 3};
    Matrix m2 = m1;
    Matrix m3 = {{2, 3, 5}, {7, 11, 17}};
    Matrix m4 = m3;

    EXPECT_THAT(m1.flatten(), ElementsAre(1, 2, 3)); 
    EXPECT_THAT(m2.flatten(), ElementsAre(1, 2, 3)); 
    EXPECT_THAT(m3.flatten(), ElementsAre(2, 3, 5, 7, 11, 17)); 
    EXPECT_THAT(m4.flatten(), ElementsAre(2, 3, 5, 7, 11, 17)); 
    

    EXPECT_THAT(m1.shape(), testing::Pair(3, 1));
    EXPECT_THAT(m2.shape(), testing::Pair(3, 1));
    EXPECT_THAT(m3.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m4.shape(), testing::Pair(2, 3));
}

TEST(Matrix, Shape_size) {
    Matrix m1{1,2,3};
    Matrix m2{{1,2,3}, {4, 5, 6}};
    const Matrix m3{{0,-2,3}, {-4, 5, 6}, {99, 100, 0}, {5, 9, 10}};
    
    Matrix::size s = m1.shape();
    ASSERT_THAT(s, testing::Pair(3, 1));
    ASSERT_THAT(m2.shape(), testing::Pair(2, 3));
    ASSERT_THAT(m3.shape(), testing::Pair(4, 3));
}

TEST(MatrixSelfOperation, Add) {
    Matrix m1{{1, 2, 3}, {4, 5, 6}};
    Matrix m2{{2, 3, 0}, {4, 4, 4}};
    m1 += m2;

    EXPECT_THAT(m1.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m1.flatten(), ElementsAre(3, 5, 3, 8, 9, 10)); 
}

TEST(MatrixSelfOperation, Minus) {
    Matrix m1{{1, 2, 3}, {4, 5, 6}};
    Matrix m2{{2, 3, 0}, {4, 4, 4}};
    m1 -= m2;

    EXPECT_THAT(m1.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m1.flatten(), ElementsAre(-1, -1, 3, 0, 1, 2)); 
}

TEST(MatrixSelfOperation, MultiplyScalar) {
    Matrix m1{{-1, 2, -3}, {4, 5, 6}};
    m1 *= -1;

    EXPECT_THAT(m1.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m1.flatten(), ElementsAre(1, -2, 3, -4, -5, -6)); 
}

TEST(MatrixSelfOperation, Power) {
    Matrix m1{{-1, 2, -3}, {4, 5, 6}};
    Matrix m2 = m1 ^ 3;
    m1 ^= 2;

    EXPECT_THAT(m1.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m1.flatten(), ElementsAre(1, 4, 9, 16, 25, 36)); 
    EXPECT_THAT(m2.flatten(), ElementsAre(-1, 8, -27, 64, 125, 216)); 
}

TEST(MatrixOperation, MultiplyBySclare) {
    Matrix m1{{-1, 2, -3}, {4, 5, 6}};
    Matrix m2 = m1 * -1;

    EXPECT_THAT(m1.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m1.flatten(), ElementsAre(-1, 2, -3, 4, 5, 6)); 
    EXPECT_THAT(m2.flatten(), ElementsAre(1, -2, 3, -4, -5, -6)); 

    Matrix m3 = -1 * m2;
    EXPECT_THAT(m3.shape(), testing::Pair(2, 3));
    EXPECT_THAT(m3.flatten(), ElementsAre(-1, 2, -3, 4, 5, 6)); 
}

TEST(GMock, Vector) {
    Matrix y{1,2,3};
    Matrix r{{1,2,3}, {4, 5, 6}};

    std::vector<int> v = {5, 10, 15};
    std::vector<std::vector<int>> vv = {{5, 10, 15}, {2, 4, 6}};
    int a[] = {1, 2, 3};
    std::vector<int> va;
    va.assign(a, a + 3);
    ASSERT_THAT(va, ElementsAre(1, 2, 3));
    ASSERT_THAT(v, ElementsAre(5, 10, 15));
    ASSERT_THAT(vv,ElementsAre(ElementsAre(5, 10, 15), ElementsAre(2, 4, 6)));
}
