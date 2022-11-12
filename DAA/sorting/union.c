
#include <stdio.h>
#include<stdlib.h>
void unionset(int a[],int b[],int m,int n)
{
    int c[m+n],i=0,j=0,k=0;
    while(i<=m && j<=n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else{
            c[k++]=b[j++];
        }
    }
    for(int i=0;i<=m+n;i++)
    {
        a[i]=c[i];
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
     int n,m;
    printf("Enter size of an array 1:");
    scanf("%d",&m);
    printf("Enter size of an array 2:");
    scanf("%d",&n);
    int *a=(int*)malloc(m*sizeof(int));
    int *b=(int*)malloc(n*sizeof(int));
    printf("Enter elements of an array 1:");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter elements of an array 1:");
      for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    unionset(a,b,m,n);
    printArray(a,m+n);
    return 0;
}
