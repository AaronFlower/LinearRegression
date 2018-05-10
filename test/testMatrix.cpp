#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Matrix.h"
#include <vector>

using testing::ElementsAre;
using testing::DoubleEq;

TEST(Matrix, Initializer_list) {
    Matrix y{1,2,3};
    Matrix r{{1,2,3}, {4, 5, 6}};
    y.flatten();   
    r.flatten();   
    ASSERT_THAT(y.flatten(), ElementsAre(1, 2, 3)); 
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
