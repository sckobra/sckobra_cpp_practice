#include <iostream>
using namespace std;
#include <vector>

void merge(vector<int>& v, vector<int>& left, vector<int>& right){
    auto it1 = left.begin();
    auto it2 = right.begin();
    auto itV = v.begin();

    while(it1 != left.end() && it2 != right.end()){
        if (*it1 < *it2){
            *itV = *it1;
            it1++;
        } else {
            *itV = *it2;
            it2++;
        }
        itV++;
    }
    while (it1 != left.end())
  {
    *itV = *it1;
    it1++;
    itV++;
  }

  while (it2 != right.end())
  {
    *itV = *it2;
    it2++;
    itV++;
  }

}

void mergeSort(vector<int>& v){
    if(v.size() <= 1){
        return;
    }
    int mid = (v.size() - 1)/2;
    vector<int> leftVector(v.begin(), v.begin() + mid + 1); 
    vector<int> rightVector(v.begin() + mid + 1, v.end());
    
    mergeSort(leftVector);
    mergeSort(rightVector);
    merge(v, leftVector, rightVector);

}


int main(){
    vector<int> nums = {38, 27, 43, 2, 3, 9, 82, 10};
    //left {2, 27, 38, 43}, right {3, 9, 10, 82}
    mergeSort(nums);
    for (int e : nums){
        cout << e << ", ";
    }
    return 0;
}