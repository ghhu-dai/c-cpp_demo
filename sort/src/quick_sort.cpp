// File Path: ~/cpp/sort/quick.cpp
// File Name: quick.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

int quick_sort(std::vector<int> &vec, int left, int right){
    if(left>=right) return 0;
    int i = left, j = right;
    int key =  vec[left];
    while(i!=j){
        while(i<j && key < vec[j]){
            --j;
        }
        vec[i] = vec[j];
        while(i<j && key > vec[i]){
            ++i;
        }
        vec[j] = vec[i];
    }
    vec[i] = key;
    quick_sort(vec,left,i-1);
    quick_sort(vec,i+1,right);
}