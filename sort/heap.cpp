// File Path: ~/cpp/sort/heap.cpp
// File Name: heap.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

void make_max_heap(std::vector<int> &vec, int len, int index){
    int left = 2*index+1;
    int right = 2*index +2;
    int maxIndex = index;
    if(left<len && vec[maxIndex]<vec[left]) maxIndex = left;
    if(right<len && vec[maxIndex]<vec[right]) maxIndex = right;
    if(maxIndex != index){
        std::swap(vec[index],vec[maxIndex]);
        make_max_heap(vec,len,maxIndex);
    }
}

int heap_sort(std::vector<int> &vec, int len){
    for(int i = len/2-1; i>=0; i--){
        make_max_heap(vec,len,i);
    }
    for(int i = len-1; i>=1; --i){
        std::swap(vec[0],vec[i]);
        make_max_heap(vec,i,0);
    }
    return 0;
}