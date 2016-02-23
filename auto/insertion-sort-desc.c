#include <stdio.h>

void insertionSortDesc(int array[], int n)
{
    int i, j, key;

    for (i = 0; i < n; i++) {
        j = i - 1;
        key = array[i];

        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    int list[] = {3, 5, 2, 7, 9, 14, -1, 4, 2, 5, -5, 1, 0, 38};

    int size = sizeof(list) / sizeof(list[0]);

    insertionSortDesc(list, size);

    printArray(list, size);

    return 0;
}
