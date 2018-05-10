#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Matrix.h"
#include <vector>

using testing::ElementsAre;

bool isPrime(int n) {
    if (n <= 1) return false;

    if (n % 2 == 0) return n == 2;

    for (int i = 3;; i += 2) {
        if (i > n / i) break;
        if (n % i == 0) return false;
    }

    return true;
}

// Tests negative input.
TEST(isPrimeTest, Negative) {
  // This test belongs to the isPrimeTest test case.

  EXPECT_FALSE(isPrime(-1));
  EXPECT_FALSE(isPrime(-2));
  EXPECT_FALSE(isPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(isPrimeTest, Trivial) {
  EXPECT_FALSE(isPrime(0));
  EXPECT_FALSE(isPrime(1));
  EXPECT_TRUE(isPrime(2));
  EXPECT_TRUE(isPrime(3));
}

// Tests positive input.
TEST(isPrimeTest, Positive) {
  EXPECT_FALSE(isPrime(4));
  EXPECT_TRUE(isPrime(5));
  EXPECT_FALSE(isPrime(6));
  EXPECT_TRUE(isPrime(23));
}

TEST(GMock, Vector) {
    Matrix x;
    std::vector<int> v = {5, 10, 15};
    std::vector<std::vector<int>> vv = {{5, 10, 15}, {2, 4, 6}};
    int a[] = {1, 2, 3};
    std::vector<int> va;
    va.assign(a, a + 3);
    ASSERT_THAT(va, ElementsAre(1, 2, 3));
    ASSERT_THAT(v, ElementsAre(5, 10, 15));
    ASSERT_THAT(vv,ElementsAre(ElementsAre(5, 10, 15), ElementsAre(2, 4, 6)));
}

TEST(Matrix, Initialization) {
}
