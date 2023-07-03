#ifndef LIST_H_
#define LIST_H_

template<class T>
class list_node{
public:
    list_node(){
        this->prev = 0;
        this->next = 0;
    }

    list_node(const T &val, list_node *prev = 0, list_node *next = 0 ){
        this->info = val;
        this->prev = prev;
        this->next = next;
    }


    T info;
    list_node *prev;
    list_node *next;

};


template <class T>
class list {
public:
    list(){
        head = 0;
        tail = 0;
    }
    
    void add_to_tail(const T &);
    T delete_from_tail();
/*                                      */

    list_node *head;
    list_node *tail;
};

template<class T>
void list::add_to_tail(const T &val){
    if(tail != 0){
        tail =  new list_node(val, tail, 0);
        tail->prev->next = tail;
    }else {
        tail = head = new list_node(val);
    }
}


template<class T>
T list::delete_from_tail(){
    if(head == 0) return;
    
    T val = tail->info;

    if(head == tail){
        delete head;
        head = tail =0;
    }else{
        tail = tail->prev;
        delete teil->next;
        tail->next = 0;
    }

    return val;
}

#endif