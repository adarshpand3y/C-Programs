// 10.b. Selection sort - Program written by Adarsh Pandey CSE3 130

#include <stdio.h>
void main() {
    int n;
    printf("Selection sort - Program written by Adarsh Pandey CSE3 130\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int ar[n];
    // Taking Input
    printf("Enter the unsorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int i, j, min_index;
    // Sorting using Selection Sort
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (ar[j] < ar[min_index]) {
                min_index = j;
            }
        }
        int temp = ar[min_index];
        ar[min_index] = ar[i];
        ar[i] = temp;
    }
    // Displaying the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
}