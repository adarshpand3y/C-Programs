#include <stdio.h>
void sel_sort(int[]);
void main()
{
    int num[5], count;
    printf("SELECTION SORT\n");
    printf("Enter the five elements to sort: ");
    for (count = 0; count < 5; count++)
        scanf("%d", &num[count]);
    sel_sort(num); /*function call*/
    printf("Elements after sorting: ");
    for (count = 0; count < 5; count++)
        printf("%d ", num[count]);
}
// Called Function
void sel_sort(int num[])
{
    int i, j, min, temp;
    for (j = 0; j < 5; j++)
    {
        min = j;
        for (i = j; i < 5; i++)
            if (num[min] > num[i])
                min = i;
        if (min < 5)
        {
            temp = num[j];
            num[j] = num[min];
            num[min] = temp;
        }
    }
}