#include <stdio.h>
#include "bst.h"

// BST* constructBST(int* arr,int length)
// {
//     BST* bst = new_bst();
//     for(int i = 0;i<length;i++)
//     {
//         // Node* node = new_node(arr[i]);
//         insert(bst,arr[i]);
//     }
//     return bst;
// }

int main()
{
    int arr[] = {2,1,3,4,5,6,7,8};
    BST* bst = constructBST(arr,8);
    printf("In-Order Traversal \n");
    traverse_in_order(bst->root);
    printf("\n");
    printf("Post-Order Traversal \n");
    traverse_post_order(bst->root);
    printf("\n");
    printf("Pre-Order Traversal \n");
    traverse_pre_order(bst->root);
}