#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i,j,temp,empty;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        empty=i;
        while(empty>0 && a[empty-1]>temp)
        {
            a[empty]=a[empty-1];
            empty--;
        }
        a[empty]=temp;  
    }
}

void main()
{
    int a[5], i, n;
    n = sizeof(a) / sizeof(a[1]);
    printf("enter the elements in the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the unsorted array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    insertionSort(a, n);
    printf("the sorted array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
