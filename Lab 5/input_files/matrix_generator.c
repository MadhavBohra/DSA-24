#include <stdio.h>
#include <stdlib.h>

int* matrix_generator(int n)
{
    // Asks user for n as input and creates a square matrix of size nxn populating it with random integers
    // int n;
    // printf("Enter n: ");
    // scanf("%d", &n);
    int* matrix = malloc(n*n*(sizeof(int)));

    for (int i = 0; i < n*n; i++)
    {

            matrix[i] = rand() % 100;

    }
    return matrix;
}


void print_matrix(int* matrix,int n) {
    for (int i = 0; i < n*n; i++) {

        printf("%d ", matrix[i]);
        if(i%n == n-1)
        printf("\n");
    }
}

int* matrix_row_wise_addn(int* arr1,int* arr2,int n)
{
    int* arr = malloc(n*n*(sizeof(int)));
    for(int i =0;i<n*n;i++)
    {
        arr[i] = arr1[i]+arr2[i];
    }
    return arr;
}

// int* matrix_column_wise_addn(int* arr1,int* arr2,int n)
// {
//     int* arr = malloc(n*n*(sizeof(int)));
//     for(int j = 0;j<n;j++)
//     {
//         for(int i =0;i<n*n;i=i+n)
//         {
//         arr[i+j] = arr1[i+j]+arr2[i+j];
//         }
//     }

//     return arr;
// }