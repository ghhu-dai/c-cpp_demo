// File Path: ~/cpp/sort/insert.cpp
// File Name: insert.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

int insert_sort(std::vector<int> &vec, int len){
    for(int i = 0; i<len-1; ++i){
        int j = i, temp = vec[i+1];
        while(j>=0 && temp < vec[j]){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = temp;
   }
    return 0;
}