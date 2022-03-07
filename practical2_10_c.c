//10.c. Bubble Sort - Program written by Adarsh Pandey CSE3 130

#include <stdio.h>
void main() {
    int n;
    printf("Bubble sort - Program written by Adarsh Pandey CSE3 130\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int ar[n];
    // Taking Input
    printf("Enter the unsorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int i, j, min_index;
    // Sorting using Bubble Sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (ar[j] > ar[j + 1]) {
                // Exchanging the values
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    // Displaying the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
}