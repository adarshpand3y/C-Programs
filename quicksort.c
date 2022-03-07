#include<stdio.h>

void merge(int ar[], int low, int mid, int high) {
    int i=low, j=mid+1, k=0;
    int size = high-low + 1;
    int temp[size];
    while(i<=mid && j<=high) {
        if(ar[i]<ar[j]) {
            temp[k] = ar[i]; i++;
        }
        else {
            temp[k] = ar[j]; j++;
        }
        k++;
    }
    while(i<=mid) {
        temp[k] = ar[i]; i++;
    }
    while(j<=high) {
        temp[k] = ar[j]; j++;
    }
    for(int i=low; i<=high; i++) {
        ar[i] = temp[i-low];
    }
}

void mergesort(int ar[], int low, int high) {
    if(low<high) {
        int mid = (low+high)/2;
        mergesort(ar, low, mid);
        mergesort(ar, mid+1, high);
        merge(ar, low, mid, high);
    }
}

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int ar[size];
    for(int i=0; i<size; i++) {
        scanf("%d", &ar[i]);
    }
    mergesort(ar, 0, size);
    printf("The sorted array is: ");
    for(int i=0; i<size; i++) {
        printf("%d ", ar[i]);
    }
    return 0;
}