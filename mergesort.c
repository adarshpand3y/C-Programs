#include<stdio.h>

int partition(int ar[], int low, int high) {
    int pivot = ar[low];
    int i=low, j=high;
    while(i<j) {
        while(ar[i]<=pivot) i++;
        while(ar[j]>pivot) j--;
        if(i<j) {
            int temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }
    }
    int temp = ar[low];
    ar[low] = ar[j];
    ar[j] = temp;
    return j;
}

void quicksort(int ar[], int low, int high) {
    if(low<high) {
        int pivot = partition(ar, low, high);
        quicksort(ar, low, pivot-1);
        quicksort(ar, pivot+1, high);
    }
}

int main() {
    printf("Enter the size: ");
    int size;
    scanf("%d", &size);
    int ar[size];
    for(int i=0; i<size; i++) {
        scanf("%d", &ar[i]);
    }
    quicksort(ar, 0, size-1);
    printf("The sorted array is: ");
    for(int i=0; i<size; i++) {
        printf("%d ", ar[i]);
    }
    return 0;
}