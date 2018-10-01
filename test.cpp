#include<vector>
#include <string>
#include "googletest/gtest.h"
#include "lab05.cpp"

TEST(Task1, Middle) {
    // базовый сценарий
  std::vector<float> v = {11, 2, 36, 47, 5, 53, 56};
  float result = mean(v);
  EXPECT_EQ(result, 30);
}

