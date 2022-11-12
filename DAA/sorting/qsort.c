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
    while(1)
    {
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
}
void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int piv=partition(a,l,h);
        quick_sort(a,l,piv);
        quick_sort(a,piv+1,h);
        printf("Pivot element is:%d\n",piv);
    }
    
}
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
    printf("%d ",a[i]);
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
    quick_sort(a,0,n);
    printArray(a,n);
}