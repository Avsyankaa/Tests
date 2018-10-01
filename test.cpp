#include<vector>
#include <string>
#include <gtest/gtest.h>
#include "lab05.hpp"

TEST(Task1, Middle) {
    // базовый сценарий
  std::vector<float> v = {11, 2, 36, 47, 5, 53, 56};
  float result = mean(v);
  EXPECT_EQ(result, 30);
    // отрицательные коэфиициенты 
   std::vector<float> v = {-11, -2, -36, -47, -5, -53, -56}; 
  float result = mean(v);
  EXPECT_EQ(result, -30);
}

