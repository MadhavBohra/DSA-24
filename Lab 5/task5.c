#include <stdio.h>
#include <sys/time.h>


int* matrix_generator(int n);
void print_matrix(int* arr,int n);
int* matrix_row_wise_addn(int* arr1,int* arr2,int n);
int* matrix_column_wise_addn(int* arr1,int* arr2,int n);
int main()
{
    // LIST myList = createNewList();
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int* arr1 = matrix_generator(n);
    int* arr2 = matrix_generator(n);
    
    // print the matrix

    printf("Printing First Array \n \n \n");
    print_matrix(arr1,n);
    printf("Printing Second Array \n \n \n");
    print_matrix(arr2,n);
    // int n = 100000;
    // int arr[n];
    // int i;
    // for (i = 0; i < n; i++)
    // {
    //     arr[i] = i;
    // }
    // for (i = 0; i < n; i++)
    // {
    //     NODE myNode = createNewNode(arr[i]);
    //     insertAfter(i - 1, myNode, myList);
    // }
    struct timeval start, end;
    int* arr3;
    gettimeofday(&start, NULL);
    arr3 = matrix_row_wise_addn(arr1,arr2,n);
    gettimeofday(&end, NULL);
    printf("Time taken for rowise addition on array: %ld microseconds\n",
           ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 +
                                                    start.tv_usec)));
    
    print_matrix(arr3,n);
    // gettimeofday(&start, NULL);
    // NODE temp = myList->head;
    // while (temp != NULL)
    //     temp = temp->next;
    // gettimeofday(&end, NULL);
    // printf("Time taken for sequential scan on linked list: %ld microseconds\n",
    //        ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 +
    //                                                 start.tv_usec)));
}