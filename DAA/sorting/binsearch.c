#include<stdio.h>
#include<stdlib.h>
int binsearch(int a[],int l,int h,int item)
{
    if(l==h)
    {
        if(item==a[l])
        return l;
        else
        return -1;
    }
    else{
        int m=(l+h)/2;
        if(item==a[m])
        return m;
        else if(item<a[m]) 
        return binsearch(a,l,m-1,item);
        else
        return binsearch(a,m+1,h,item);
        
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
    int item=5;
    int k=binsearch(a,0,n,item);
    printf("%d",k);
}