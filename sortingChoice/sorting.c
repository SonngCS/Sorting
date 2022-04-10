#include "sorting.h"

void selectionSort(int * v, int n){
    int k, lesser;
    for(int i = 0; i < n-1; i++){
        k = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[k]){
                k = j;
            }
        }
        lesser = v[k];
        v[k] = v[i];
        v[i] = lesser;
    }
}

void permutationSort(int * v, int n){
    int aux;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1;j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void quickSort(int * v, int l, int r){
    int i = l, j = r, x, aux;
    x = v[(i + j)/2];
    do{
        while (v[i] < x) i++;
        while (x < v[j]) j--;
        if(i <= j){
            aux = v[i];
            v[i++] = v[j];
            v[j--] = aux;
        }
    }while (i <= j);
    if (l < j) quickSort(v, l, j);
    if (i < r) quickSort(v, i, r);
}

void merge(int * v, int f, int q, int r){
    int i = f, j = q + 1, k = 0;
    int w[r-f+1];
    while(i <= q && j <= r){
        if(v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i <= q) w[k++] = v[i++];
    while (j <= r) w[k++] = v[j++];
    for(i = f; i <= r; i++){
        v[i] = w[i-f];
    }
}

void mergeSort(int * v, int f, int r){
    if(f < r){
        int q = (f+r)/2;
        mergeSort(v, f, q);
        mergeSort(v, q+1, r);
        merge(v, f, q, r);
    }
}

void heap(int * v, int l, int r){
    int i = l, j = 2*l+1;
    int x = v[l];
    if(j < r && v[j + 1] > v[j]) j++;
    while(j <= r && v[j] > x){
        v[i] = v[j];
        i = j;
        j = 2*i + 1;
        if(j < r && v[j + 1] > v[j]) j++;
    }
    v[i] = x;
}

void heapSort(int * v, int n){
    int e = (n/2), d = n-1, x;
    while(e > 0){
        e--;
        heap(v, e, d);
    }
    while(d > 0){
        x = v[0];
        v[0] = v[d];
        v[d--] = x;
        heap(v, 0, d);
    }
}
