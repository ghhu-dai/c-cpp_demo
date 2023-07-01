// File Path: ~/cpp/introduction_algorithm/linked_list/linked_list.h
// File Name: linked_list.h
// Directory: ~/cpp/introduction_algorithm/linked_list
// Date: 2023-06-27

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class list_node
{
private:
    /* data */
public:

    int key;
    list_node *prev;
    list_node *next;
    list_node(/* args */);
    list_node(int key);
    ~list_node();
};


class list{

private:

public:

    list_node *head;
    list_node *list_search(list *L, int key);
    list_node *insert_forward(list *L, list_node *x);
    void delete_node(list *L, list_node *x);
    
};

#endif