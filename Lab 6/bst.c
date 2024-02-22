#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}


// Function to determine the height of a BST :

int height_of_tree(Node* node)
{
    if(node == NULL)
    return -1;
    int left_height = height_of_tree(node->left);
    int right_height = height_of_tree(node->right);
    //return max
    if (left_height>right_height)
    return 1+left_height;
    else
    return 1+right_height;

}

BST* constructBST(int* arr,int length)
{
    BST* bst = new_bst();
    for(int i = 0;i<length;i++)
    {
        // Node* node = new_node(arr[i]);
        insert(bst,arr[i]);
    }
    return bst;
}

void printBST(Node* node, int space) {
    if (node == NULL) {
        return;
    }

    int count = 5;
    space += count;

    printBST(node->right, space);
    printf("\n");
    for (int i = count; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->value);
    printBST(node->left, space);
}


// // Driver program to test the above functions (feel free to play around with this)
// int main()
// {
//     BST *bst = new_bst();
//     insert(bst, 2);
//     insert(bst, 1);
//     insert(bst, 3);
//     insert(bst, 4);
//     insert(bst, 5);
//     insert(bst, 6);
//     insert(bst, 7);
//     insert(bst, 8);
//     traverse_in_order(bst->root);
//     printf("\n");
//     printf("Max = %d\n", find_max(bst));
//     printf("Min = %d\n", find_min(bst));
//     printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
//     printf("Successor of root = %d\n", successor(bst->root)->value);
//     delete(bst, bst->root->left);
//     traverse_in_order(bst->root);
//     printf("\n");
//     delete(bst, bst->root->right);
//     traverse_in_order(bst->root);
//     printf("\n");
//     delete(bst, bst->root);
//     traverse_in_order(bst->root);
//     printf("\n");
//     return 0;
// }