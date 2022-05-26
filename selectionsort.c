#include <stdio.h>

void selectionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void main()
{
    int i, n;
    int a[10];
    n = sizeof(a) / sizeof(a[0]);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the unsorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    selectionSort(a, n);
    printf("the sorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
