
// Path:   /home/dai/cpp/mai.cp
// File:   mai.cpp
// Author: Gh_
// Date:   2023-06-19
// Brief:  说点什么吧 ？

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "header.h"

int main(){
    std::cout<<std::endl;
    std::cout<<"hello world,hello"<<std::endl;
    std::cout<<"today is good day"<<std::endl;
    std::vector<int> vec = {10,9,8,7,6,5,4,3,2,1};
    std::cout<<std::endl;
    std::cout<<"befort_sort："<<std::endl;
    print(vec);
    std::cout<<std::endl;

    #if 0
    bubble_sort(vec,vec.size());
    select_sort(vec,vec.size());
    insert_sort(vec,vec.size());
    shell_sort(vec,vec.size());
    merge_sort(vec,0,vec.size()-1);
    quick_sort(vec,0,vec.size()-1);
    #else
    heap_sort(vec,vec.size());
    #endif

    std::cout<<"after_sort：   "<<std::endl;
    print(vec);
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"kmp : "<<std::endl;
    std::string text = "123456789";
    std::string pattern = "5";
    int pos = kmp(text,pattern);
    std::cout<<text<<std::endl;
    std::cout<<pattern<<std::endl;
    std::cout<<pos<<std::endl;
    std::cout<<std::endl;
    return 0;
}

