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

TEST(Task3, Argmax) {
    // базовый сценарий
  std::vector<float> v1 = {11, 2, 36, 47, 5, 53, 56};
  int index_max=argmax(v1);
  EXPECT_EQ(index_max, 6);  
    // отрицательные коэфиициенты 
  std::vector<float> v2 = {-11, -2, -36, -47, -5, -53, -56}; 
  index_max = argmax(v2);
  EXPECT_EQ(index_max, 1);
    // положительные и отрицательные коэфиициенты
  std::vector<float> v3 = {5, -3, -5, 47, -40, 3, 0}; 
  index_max = argmax(v3);
  EXPECT_EQ(index_max, 3);  
    // вектор из одного элемента
   std::vector<float> v4 = {456};  
   index_max = argmax(v4);
   EXPECT_EQ(index_max, 0);   
    // пустой вектор
  std::vector<float> v5 = {0};  
  index_max = argmax(v5);
  EXPECT_EQ(index_max, -1);   
}
