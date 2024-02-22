#include <stdio.h>
#include "bst.h"


int main()
{
    int arr[] = {25,52,42,1,53,65,23};
    BST* bst = constructBST(arr,7);
    printBST(bst->root,0);
    traverse_in_order(bst->root);
    printf("\n%d",height_of_tree(bst->root));


    // Reading from the text file... 
}