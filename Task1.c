#include <stdio.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void InsertionSort(struct person* arr,int size)
{
    for(int i = 1;i<size;i++)
    {
        struct person temp = arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            // 1,2,3,5,6,4
            // 0 1 2 3 4 5
            if(arr[j].height>temp.height)
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

void PrintStruct(struct person* arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("%d %s %d %d %d \n",arr[i].id,
        arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
    }
}

int main()
{
    struct person arr[] = {
        {1,"Sokka",15,150,45},
        {2,"Aang",112,137,35},
        {3,"Zuko",16,160,50},
        {4,"Katara",14,145,38},
        {5,"Toph",12,113,30}
    };

    PrintStruct(arr,5);
    InsertionSort(arr,5);
    printf("\n \n \n \n");
    PrintStruct(arr,5);


    
    return 0;
}