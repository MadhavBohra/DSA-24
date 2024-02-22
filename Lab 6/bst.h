#ifndef BST_H
#define BST_H


typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst();
Node *new_node(int value) ;
void traverse_in_order(Node *node);
void traverse_pre_order(Node *node);
void traverse_post_order(Node *node);
void insert(BST *bst, int value);
BST* constructBST(int* arr,int length);
int height_of_tree(Node* node);
void printBST(Node* node, int space);

#endif /* BST_H */