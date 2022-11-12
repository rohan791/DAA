#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int l,int mid,int h)
{
    int i=l;
    int j=mid+1;

    int b[h+1];
    int k=l;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }

    }
    if(i>mid)
    {
        while(j<=h)
        {
            b[k++]=a[j++];
        }

    }
    else
    {
        while(i<=mid)
        {
            b[k++]=a[i++];
        }
    }
    for( int z=l;z<=h;z++)
    {
        a[z]=b[z];
    }
}


void merge_sort(int *a,int l,int r)//l is the starting array and r is the upper bound
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);  
        merge(a,l,mid,r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size of an array:");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    printf("Enter elements of an array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printArray(a,n);
}