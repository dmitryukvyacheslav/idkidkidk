#pragma once
#include <string>
#include <graphviz/gvc.h>
typedef enum rb_color {
    red,
    black
} rb_color;

typedef struct rb_node {
    rb_node* parent;
    int key;
    rb_color color;
    rb_node* left_child;
    rb_node* right_child;
} rb_node;

class RedBlackTree {
public:
    rb_node* m_root;
    RedBlackTree();
    rb_node* add(int key);
    rb_node* lookup(int key);
    rb_node* remove(int key);
    rb_node* min();
    rb_node* min(rb_node* node);
    rb_node* max();
    void rb_free();
    void* render_dfs();
    void free_renderdata();
    char* m_renderdata;
    unsigned int m_rd_len;
private:
    GVC_t* m_gvc;
    graph_t* m_g;
    bool m_requireUpdate;
    rb_node* rb_createnode(int key);
    void rb_leftrotate(rb_node* x);
    void rb_rightrotate(rb_node* x);
    void rb_addfixup(rb_node* node);
    void rb_delfixup(rb_node* node);
    void printPreorder(rb_node* node, std::string* dotstr);
    void rb_free(rb_node* node);
    void printNode(rb_node* node, std::string* dotstr);
    void rb_transplant(rb_node* node, rb_node* vtx);
};




