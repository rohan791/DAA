#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int start;
    int finish;
}activity;

int compare(const void *a, const void *b) {
    activity *x = (activity *)a;
    activity *y = (activity *)b;
    if (x->finish < y->finish) return -1;
    if (x->finish > y->finish) return 1;
    return 0;
}
void asp(activity *activities,int n)
{
    int i,j,count=1;
    qsort(activities,n,sizeof(activity),compare);
    printf("Selected activities:");
    printf("(%d %d)",activities[0].start,activities[0].finish);
    j=0;
    for(i=1;i<n;i++)
    {
        if(activities[i].start>=activities[j].finish)
        {
            printf("(%d %d)",activities[i].start,activities[i].finish);
            j=i;
            count++;
        }
    }
    printf("\nThe maximum no of activities that can be executed by a single person is %d",count);
}
int main()
{
    int n,i,j,count=0;
    activity *activities;
    printf("Enter no of activitites:");
    scanf("%d",&n);
    activities=(activity *)malloc(n*sizeof(activity));
    printf("Enter the start and finish time of each activity:");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&activities[i].start,&activities[i].finish);
    }
    asp(activities,n);
    return 0;
}