// File Path: ~/cpp/sort/kmp.cpp
// File Name: kmp.cpp
// Directory: ~/cpp/sort
// Date: 2023-06-20

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

void make_next(std::vector<int> &next, std::string &pattern){
    int i ,j;
    next[0] = 0;
    for(i=1, j=0; i<pattern.size();++i){
        while(j>0 && pattern[i] != pattern[j]){
            j = next[j-1];
        }
        if(pattern[i] == pattern[j]) ++j;
        next[i] = j;
    }
}


int kmp(std::string &text, std::string &pattern){
    int i,j;
    std::vector<int> next(pattern.size());
    make_next(next,pattern);
    for(i=0,j=0; i<text.size(); ++i){
       while(j>0 && text[i] != pattern[j]){
            j = next[j-1];
       } 
      if(text[i] == pattern[j]){
            ++j;
       }
       if(j==pattern.size()){
        break;
       }
    }
    return i-j+1;
}