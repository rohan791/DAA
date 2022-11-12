#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int h)
{
    int i=l-1;
    int j=h+1;
    int piv=a[l];
    do{
        j--;
    }while(a[j]>piv);
    do{
        i++;
    }while(a[i]<piv);
    if(i<j)
    {
        swap(&a[i],&a[j]);
    }
    else{
        swap(&a[l],&a[j]);
        return j;
    }
}
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    int random = low + rand() % (high - low);
  
    // Swap A[random] with A[high]
    swap(&arr[random],&arr[high]);
  
    return partition(arr, low, high);
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=partition(a,l,h);
        quicksort(a,l,p);
        quicksort(a,p+1,h);
    }
}
int main()
{
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n);
    printf("Updated array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}