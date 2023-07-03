
// 循环单向链表，设置一个tail即可 

void add_to_tail(int val){
    if(tail == 0){
        tail = new list_node(val);
        tail->next = tail;
    }else {
        tail->next = new list_node(val,tail->next);
        tail = tail->next;
    }
}