#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int ar[n], isFound = 0, num, pos;
    for (int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &ar[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        if(ar[i] == num)
        {
            isFound = 1;
            pos = i;
            break;
        }
    }
    if (isFound)
    {
        printf("Number found at index %d", pos);
    }
    else
    {
        printf("Number not found");
    }
}