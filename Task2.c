#include <stdio.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void InsertionSort(struct person* arr, int size) {
    printf("bruh");
}

int main(int argc, char *argv[]) {
    // argc means the number of arguments passed in CLI
    if (argc != 2) {
        printf("Please provide exactly one CSV file.\n");
        return 1;
    }

    printf("%s\n", argv[1]);

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1000];

    // Read one line from the file
    if (fscanf(file, " %[,]", line) == 1) {
        printf("%s\n", line);
    } else {
        printf("Error reading file.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
