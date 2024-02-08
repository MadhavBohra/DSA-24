1. Sorting

a. Insertion Sort - 

Time complexity - O(n^2)
Space Complexity - O(n)
Auxillary Space - O(1)
Total Space = Auxillary Space + Space Complexity


code :
``` C
void InsertionSort(int* arr,int size)
{
    for(int i = 1;i<size;i++)
    {
        int temp = arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            // 1,2,3,5,6,4
            // 0 1 2 3 4 5
            if(arr[j]>temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }

        }
        arr[j+1] = temp;

    }
}
```


b. Merge Sort 


Top down approach is easier to understnad
Iterative Approach
Reccursive Approach

Merging algorithm that is very effective - 
Using two pointer.... 