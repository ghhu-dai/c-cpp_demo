#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// b树的结构定义
#define DEGREE      3
typedef int KEY_VALUE;

typedef struct _btree_node{
    KEY_VALUE *keys;
    struct _btree_node **childrens;
    int num;
    int leaf;
} btree_node;

typedef struct _btree{
    btree_node *root;
    int t; // t 是度数，表示 节点最小的子树数量(M/2) 

} btree;

btree_node *btree_cerate_node(int t, int leaf){
    btree_node *node = (btree_node*)alloc(1,sizeof(btree_node));
    if(node == NULL) assert(0); // assert(0) 是一个强制断言失败的语句

    node->leaf = leaf;
    node->num = 0;
    node->keys = (KEY_VALUE)calloc(1,(2*t-1)*sizeof(KEY_VALUE));
    node->childrens = (btree_node**)calloc(1,(2*t)*sizeof(btree_node*));
    return node; 
}

void btree_destroy_node(btree_node *node){
    assert(node); // 这是一个断言语句，条件为真（node不为空）程序继续执行，否则断言失败终止并输出错误信息
    
    free(node->childrens);
    free(node->keys);
    free(node);
}

void btree_create(btree *T, int t){
    T->t = t;
    btree_node * x = btree_cerate_node(t, 1);
    T->root = x;

}

