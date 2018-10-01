#include "lab05.hpp"
float mean(const std::vector<float>& array) {
    float sum;
    if (array.size()==0) {
        return 0;
    }
for (int i=0; i< array.size(); i++) {
    sum+= array[i];
}
sum= sum/array.size();
return sum;
};

int main() {
    const std::vector<float> v = {11, 2, 36, 47, 5, 53, 56};
  float result = mean(v);
  std::cout<< result<< std::endl;
}
