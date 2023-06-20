#include<iostream>
#include<vector>

#ifndef HEADER_H
#define HEADER_H

void print(std::vector<int> &vec);
int bubble_sort(std::vector<int> &vec, int len);
int select_sort(std::vector<int> &vec, int len);
int insert_sort(std::vector<int> &vec, int len);
int shell_sort(std::vector<int> &vec, int len);
int merge_sort(std::vector<int> &vec, int left, int right);
int quick_sort(std::vector<int> &vec, int left, int right);
int heap_sort(std::vector<int> &vec, int len);
int kmp(std::string &text, std::string &pattern);
#endif