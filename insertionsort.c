#include<stdio.h>

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int ar[size];
    for(int i=0; i<size; i++) {
        scanf("%d", &ar[i]);
    }
    for(int i=0; i<size; i++) {
        int temp = ar[i];
        int j = i-1;
        while(j>=0 && ar[j]>temp) {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = temp;
    }
    printf("The sorted array is: ");
    for(int i=0; i<size; i++) {
        printf("%d ", ar[i]);
    }
    return 0;
}