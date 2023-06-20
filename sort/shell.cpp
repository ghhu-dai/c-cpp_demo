// File Path: ~/cpp/sort/shell.cpp
// File Name: shell.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

int shell_sort(std::vector<int> &vec, int len){
    for(int gap = len/2; gap>=1; gap/=2){
        for(int i = gap; i<len; i++){
            int j = i-gap,temp = vec[i];
            while(j>=0 && temp < vec[j]){
                vec[j+gap] = vec[j];
                j-=gap;
            }
            vec[j+gap] = temp;
        }
    }
    return 0;
}