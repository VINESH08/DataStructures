//sorting an unsorted array and then removing the duplicate elements from it.
#include <stdio.h>
void sortarr(int arr[], int n);
void swap(int *a, int *b);
int removedup(int arr[], int n, int temp[]);
//bubble sort for an arraÿ
void sortarr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int removedup(int arr[], int n, int temp[])
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];
    return j + 1;
}
int main()
{
    int n, k;
    printf("enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortarr(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    k = removedup(arr, n, temp);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", temp[i]);
    }
}