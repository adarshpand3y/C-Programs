#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ar[n], isFound=0, num, step=sqrt(n), m = sqrt(n), pos;
    printf("Enter %d sorted elements:-\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &num);
    int prev=0;
    while (ar[min(step, n) - 1] < num)
    {
        printf("%d", prev);
        prev += step;
        step += m;
        if (ar[prev] >= num)
        {
            printf("\nGoing to display\n");
            goto display;
        }
    }
    for (int i = prev-m; i <= prev; i++)
    {
        if(ar[i] == num)
        {
            isFound = 1;
            pos = i;
            break;
        }
    }
    display:
    if (isFound)
    {
        printf("Found at index %d.", pos);
    }
    else
    {
        printf("Not found");
    }
    return 0;
}