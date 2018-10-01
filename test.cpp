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
    // положительные и отрицательные коэфиициенты
  std::vector<float> v = {5, -3, -5, 47, -40, 3, 0}; 
  float result = mean(v);
  EXPECT_EQ(result, 1);  
    // вектор из одного элемента
  std::vector<float> v = {456}; 
  float result = mean(v);
  EXPECT_EQ(result, 456);    
    // пустой вектор
  std::vector<float> v = {}; 
  float result = mean(v);
  EXPECT_EQ(result, 0);     
}

