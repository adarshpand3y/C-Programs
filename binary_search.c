#include<stdio.h>

int main() {
    int n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ar[n], isFound = 0, pos;
    int left=0, mid, right=n;
    printf("Enter %d elements:-\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &num);
    while(left<=right) {
        mid = (left+right)/2;
        if(ar[mid] == num) {
            isFound = 1;
            pos = mid;
            break;
        }
        else if(num < ar[mid]) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    if(isFound) {
        printf("Number found at index %d.", pos);
    }
    else {
        printf("Number not found");
    }
    return 0;
}