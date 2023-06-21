// File Path: ~/cpp/sort/bubble.cpp
// File Name: bubble.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

int bubble_sort(std::vector<int> &vec,int len){
    for(int i = 0; i<len-1; ++i){
        for(int j = 0; j<len-1-i; ++j){
            if(vec[j]>vec[j+1]){
                std::swap(vec[j],vec[j+1]);
            }

        }
    }
    return 0;
}