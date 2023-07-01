#ifndef LIST_FORWARD_H_
#define LIST_FORWARD_H_ 

// 单向链表

// 单身链表节点类定义
class LF_node{
public:
    LF_node(){
        next = nullptr;
    }    

    LF_node(int x, LF_node *ptr = 0){ // 内联？
        this->info = x;
        this->next = ptr;
    }

    int info;
    LF_node *next;
}; // 节点类成员声明为公有是为了链表类可以访问相关信息


// 单向链表类定义
class list_forward{
public:
    list_forward(){
        head = tail = 0;
    }

    ~list_forward();

    int isEmpty(){
        return head == nullptr;
    }

    void add_to_head(int );
    void add_to_tail(int );
    int delete_from_head();
    int delete_from_tail();     // 删除尾节点，并返回info
    void delete_node(int);      // 删除指定Info节点
    bool isin_list(int) const;  // 判断该值是否存在于链表中   

private:
    LF_node *head, *tail;

};

#endif 