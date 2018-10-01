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
    // вектор из одинаковых элементов 
   std::vector<float> v5 = {5, 5, 5, 5, 5, 5, 5}; 
  index_max = argmax(v5);
  EXPECT_EQ(index_max, 0); 
    // вектор из одного элемента
   std::vector<float> v4 = {456};  
   index_max = argmax(v4);
   EXPECT_EQ(index_max, 0);   
    // пустой вектор
  std::vector<float> v6 = {};  
  index_max = argmax(v6);
  EXPECT_EQ(index_max, -1);   
}

TEST(Task5, delete_first_minus) {
    // базовый сценарий
  std::vector<float> v1 = {11, -2, 36, -47, 5, 53, 56};
  std::vector<float> result1 = {11, 36, -47, 5, 53, 56};
  float deleting_element = delete_first_minus(v1);
  EXPECT_EQ(result1, v1);
  EXPECT_EQ(deleting_element, -2);
    // только неотрицательные элементы
  std::vector<float> v2 = {11, 2, 0, 47, 5, 53, 56};
  std::vector<float> result2 = {11, 2, 0, 47, 5, 53, 56};
  deleting_element = delete_first_minus(v2);
  EXPECT_EQ(result2, v2);  
  EXPECT_EQ(deleting_element, 0);  
    // один отрицательный элемент
  std::vector<float> v3 = {-111};
  std::vector<float> result3 = {};
  deleting_element = delete_first_minus(v3);
  EXPECT_EQ(result3, v3);  
  EXPECT_EQ(deleting_element, -111); 
    // пустой массив 
  std::vector<float> v4 = {};
  std::vector<float> result4 = {};
  deleting_element = delete_first_minus(v4);
  EXPECT_EQ(result4, v4);  
  EXPECT_EQ(deleting_element, 0);   
}

TEST(Task7, split) {
  // базовый случай   
 std::string str1 = "Hello! Do you like programming?";
 std::vector<std::string> result1 = {"Hello!", "Do", "you", "like", "programming?"};
 std::vector<std::string> v1 = split(str1, char sep = ' ');
 EXPECT_EQ(result1, v1);  
   // строка не содержит пробелов
 std::string str2 = "Hello!";  
 std::vector<std::string> result2 = {"Hello!"};
 std::vector<std::string> v2 = split(str2, char sep = ' '); 
 EXPECT_EQ(result2, v2);
    // строка пустая
 std::string str3 = "";  
 std::vector<std::string> result3 = {};
 std::vector<std::string> v3 = split(str3, char sep = ' '); 
 EXPECT_EQ(result3, v3);   
    // строка состоит только из пробельного символа
 std::string str4 = " ";
 std::vector<std::string> result4 = {"", ""};
 std::vector<std::string> v4 = split(str4, char sep = ' ');
 EXPECT_EQ(result4, v4);    
}
