// File Path: ~/cpp/introduction_algorithm/linked_list/linked_list.cpp
// File Name: linked_list.cpp
// Directory: ~/cpp/introduction_algorithm/linked_list
// Date: 2023-06-27

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "linked_list.h"

list_node::list_node(){

    this->key = 0;
    this->next = nullptr;
    this->prev = nullptr;
}

list_node::list_node(int key){
    this->key = key;
    this->next = nullptr;
    this->prev = nullptr;
}


list_node* list::list_search(list *L, int key){
    list_node *root = L->head;
    while(root != nullptr && root->key != key ){
        root = root->next;
    } 
    return root;
}

list_node* list::insert_forward(list *L, list_node *x){
    list_node *head = L->head;
    if(L->head != nullptr){
        L->head->prev = x;
    }
    L->head = x;
    x->prev = nullptr;
}

void list::delete_node(list *L, list_node *x){
    
    // 比起判断是否为表头表尾元素，直接判断前后元素是否为空更直接简单
    if(x->prev != nullptr){
        x->prev->next = x->next;
    }else{
        L->head = x->next;
    }

    if(x->next != nullptr){
        x->next->prev = x->prev;
    }
}