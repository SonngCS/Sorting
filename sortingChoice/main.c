#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"
#include "sorting.h"

void error(void);

int main(void){
    int max_value, size_data;
    size_data = max_value = 0;

    printf("Choose a positive integer for the number of elements in the vector: ");
    while(size_data <= 0) scanf("%d", &size_data);
    printf("Choose a positive interval for the value of the elements in the vector: ");
    while(max_value <= 0) scanf("%d", &max_value);

    int dataStructure[size_data];
    srand(time(NULL));
    for(int i = 0; i < size_data; i++){
        dataStructure[i] = rand() % (max_value+1);
    }
    int sortchoice = 0;
    printVector(dataStructure, size_data);
    printf("Choose a sorting algorithm:\n1 - Selection sort\n2 - Permutation sort (bubble sort)\n3 - Quick sort\n4 - Merge sort\n5 - Heapsort\n");
    scanf("%d", &sortchoice);
    clock_t start = clock(), diff;
    switch(sortchoice){
        case 1: 
            selectionSort(dataStructure, size_data);
            break;
        case 2: 
            permutationSort(dataStructure, size_data);
            break;
        case 3: 
            quickSort(dataStructure, 0, size_data);
            break;
        case 4: 
            mergeSort(dataStructure, 0, size_data);
            break;
        case 5:
            heapSort(dataStructure, size_data);
            break;
        default: error();
    }
    diff = clock() - start;
    if(sortchoice != 5) printVector(dataStructure, size_data);
    else printHeap(dataStructure, size_data);
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Execution time: %d seconds and %d milliseconds\n", msec/1000, msec%1000);
    
    return 0;
}

void error(void){
    fprintf(stderr, "Option not recognized, shutting down the program\n");
    exit(1);
}
