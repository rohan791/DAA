//Fractional Knapsack
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int weight;
    int value;
    float ratio;
    float x;
}item;
int compare(const void *a,const void *b)
{
    item *x=(item*)a;
    item *y=(item *)b;
    if(x->ratio>y->ratio)return -1;
    if(x->ratio<y->ratio)return -1;
    return 0;
}
float fractional_knapsack(item *items,int m,int n)
{
    int i;
    float total_value;
    qsort(items,n,sizeof(item),compare);
    for(i=0;i<n;i++)
    {
        if(items[i].weight<=m)
        {
            m-=items[i].weight;
            total_value+=items[i].value;
            items[i].x=1;
        }
        else{
            items[i].x=(float) m/items[i].weight;
            total_value+=items[i].x * items[i].value;
            break;
        }
    }
    return total_value;
}
int main()
{
    int n,i,j,capacity;
    item *items;
    float total_value=0.0;
    printf("Enter the no of items:");
    scanf("%d",&n);

    printf("Enter the value of each items:");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&items[i].weight,&items[i].value);
        items[i].ratio=(float) items[i].value/items[i].weight;
    }
    printf("Enter capacity of knapsack:");
    scanf("%d",&capacity);
    total_value=fractional_knapsack(items,capacity,n);
    printf("Total value is %f",total_value);
    return 0;
}