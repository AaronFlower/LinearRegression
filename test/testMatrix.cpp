#include "gtest/gtest.h"

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

