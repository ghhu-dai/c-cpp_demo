// File Path: ~/cpp/sort/print.cpp
// File Name: print.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

void print(std::vector<int> &vec){
    for(int i = 0; i<vec.size();++i){
        std::cout<<vec[i]<<" ";
    }
}