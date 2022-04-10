#include <stdio.h>
#include <stdbool.h>
#include "print.h"

void printVector(int * v, int n){
    printf("\n|");
    for(int i = 0; i < n; i++){
        printf(" %d |", v[i]);
    }
    printf("\n");
}

void printSpaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

void printHeap(int * h, int n){
    int left_child, right_child;
    printf("| %d | ", h[0]);

    for(int i = 0; i < n/2; i++){
        left_child = 2*i + 1;
        right_child = 2*i + 2;
        if(left_child < n){
            printf("%d | ", h[left_child]);
        }
        if(right_child < n){
            printf("%d | ", h[right_child]);
        }
    }
    printf("\n");
}