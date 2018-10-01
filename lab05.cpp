#include "lab05.hpp"
float mean(std::vector<float>& array) {
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
    
};
