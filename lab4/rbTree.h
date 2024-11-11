#ifndef RB_TREE_H
#define RB_TREE_H

typedef struct rb_node {
    enum { RED, BLACK } color;
    int key;
    struct rb_node *left, *right, *parent;
} t_rb_node;

typedef struct {
    t_rb_node *root;
} t_rb_arbore;

t_rb_node* MAKE_ROOT(t_rb_arbore *T, int key);

t_rb_node* CREATE_NODE(int key);

void INORDER_WALK(t_rb_node *root);

t_rb_node* TREE_SEARCH(t_rb_node *root, int key);

void RB_INSERT(t_rb_arbore *a, t_rb_node *z);

void LEFT_ROTATE(t_rb_arbore *a, t_rb_node *x);

void RIGHT_ROTATE(t_rb_arbore *a, t_rb_node *x);

void RB_INSERT_FIXUP(t_rb_arbore *a, t_rb_node *z);

#endif
