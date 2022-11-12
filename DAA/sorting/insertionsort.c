#include<stdio.h>
#include<stdlib.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void quicksort(int a[],int l,int n)
{
    int i,j,item;
    for(i=1;i<n;i++)
    {
        item=a[i];
        j=i-1;
        while(a[j]>item && j>0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=item;
    }
}
int main()
{
    int n;
    printf("Enter size of an array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of an array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n);
    printArray(a,n);
}