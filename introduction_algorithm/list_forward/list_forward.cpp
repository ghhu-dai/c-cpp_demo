// File Path: ~/M_Y/introduction_algorithm/list_forward/list_forward.cpp
// File Name: list_forward.cpp
// Directory: ~/M_Y/introduction_algorithm/list_forward
// Date: 2023-07-01

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "list_forward.h"

list_forward::~list_forward(){
    for(LF_node *p; !isEmpty(); ){
        p = head->next;                 // 临时存放head节点的下一个节点,p = head->next; 
        delete head;
        head = p;   
    }
}


/*
    * 头增
    * 1。创建一个节点，设置info,next;其中next指向head(创建的时候其实已经指明了位置)
    * 2. 更新head
*/
void list_forward::add_to_head(int val){
    head = new LF_node(val, head);
    if(tail == nullptr){ // 链表为空时
        tail = head;
    }
}

/*
    * 尾增
    * 1。 创建一个节点，设置info,next；其中next指向null(创建节点时未指明位置，所以多一步)。
    *       （且用到tail->next,需要提前判断 tail != null）
    * 2。 将创建的节点链接在tail->next;
    * 3。 更新tail
*/
void list_forward::add_to_tail(int val){
    if(tail != nullptr){
        tail->next = new LF_node(val);
        tail = tail->next;
    }else{
        tail = head = new LF_node(val); // 链表为空时
    }
}


// 表头表尾的删除函数 默认不为空 !isEmpty()，在调用前先行判断


/*
    * 链表的头删：
    * 定义一个temp = head->next; 防止找不到链表
    * 情况1：链表只有一个元素
    * 情况2：链表有多个元素
*/
int list_forward::delete_from_head(){
    assert(! isEmpty()); // 如果链表为空，(! isEmpty)为假，程序退出

    int ret = head->info;
    LF_node *temp = head;

    // if/else语句 要么都有返回值 ，要么都没有返回值
    if(head == tail){               // 链表只有一个元素
        head = tail = nullptr;
    }else{                          // 链表有多个元素
        head = head->next;
    }

    delete temp;
    return ret;
}

/*
    * 链表尾删，分为两种情况
    * 情况1，链表只有一个元素：直接删除
    *                        再将链表头尾指针重赋为0/null即可
    * 
    * 情况2，链表元素超过一个：找到tail的前一个节点prev
    *                        然后删除并重新赋值tail 
    *                        最后设置tail->next=0即可
*/

int list_forward::delete_from_tail(){

    int ret = tail->info;

    LF_node *prev = head;

    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        for(prev; prev->next != tail; prev = prev->next);
        delete tail;
        tail = prev;
        tail->next = 0;
    }
    return ret;
}

/*
    * 特定值 节点的删除
    * 情况一：只有一个元素，且该元素的值与val匹配
    * 情况二：多个元素，要删除的元素是头节点
    * 情况三：多个元素，删除的元素不是头节点
*/

void list_forward::delete_node(int val){
    if(isEmpty()) return ;

    // 情况一
    if(head == tail && val == head->info ){

        delete head;
        head = tail = 0;

    // 情况二
    }else if(val == head->info){

        delete_from_head();

    // 情况三
    }else{

        LF_node *prev = head, *temp = head->next;   //
        for(; temp != 0 && temp->info != val; prev = temp,temp = temp->next);
        if(temp!=0){
            prev->next = temp->next;
            if(temp == tail){
                tail = prev;
            }
            delete temp;
        }

    }
}



bool list_forward::isin_list(int val)const{
    LF_node *temp;
    for(temp = head; temp!=0 && temp->info != val; temp = temp->next);
    return temp != 0;
}