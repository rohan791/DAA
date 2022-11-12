#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int low, int high)
{
    int i = low - 1, j = high + 1;
    int pivot = arr[low];
    while (1)
    {
        do
        {
            j--;
        } while (arr[j] > pivot);

        do
        {
            i++;
        } while (arr[i] < pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
        {
            swap(&arr[low], &arr[j]);
            return j;
        }
    }
}
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot);
        quickSort(arr, pivot + 1, high);
    }
    return;
}
