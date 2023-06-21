// File Path: ~/cpp/sort/select.cpp
// File Name: select.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

int select_sort(std::vector<int> &vec, int len){
    for(int i = 0; i<len-1; i++){
        int minIndex = i;
        for(int j = i+1; j<len; ++j){
            if(vec[minIndex]>vec[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            std::swap(vec[i],vec[minIndex]);
        }
    }
    return 0;
}