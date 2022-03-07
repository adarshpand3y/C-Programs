#include <stdio.h>

void bubble_sort(int a[], int n) {
    int i = 0, j = 0, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[100], n, i, d, swap;
    printf("BUBBLE SORT\n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, n);
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}