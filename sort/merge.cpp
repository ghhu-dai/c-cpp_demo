// File Path: ~/cpp/sort/merge.cpp
// File Name: merge.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

void merge(std::vector<int> &vec, int left, int middle, int right){
    int i = left, j = middle+1;
    int k = left;
    std::vector<int> temp(vec.size());
    while(i<=middle+1 && j<=right){
        if(vec[i]>vec[j]){
            temp[k++] = vec[j++];
        }else{
            temp[k++] = vec[i++];
        }
    }
    while(i<=middle){
        temp[k++] = vec[i++];
    }
    while(j<=right){
        temp[k++] = vec[j];
    }
    for(i = left; i<=right; ++i){
        vec[i] = temp[i];
    }
}

int merge_sort(std::vector<int> &vec, int left, int right){
    if(left>=right) return 0;
    int middle = left + (right-left)/2;
    merge_sort(vec,left,middle);
    merge_sort(vec,middle+1,right);
    merge(vec,left,middle,right);
}