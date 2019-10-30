//Quick Sort

#include<stdio.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int l,int r)
{
    int pi=arr[l];
    int d=l+1;
    int u=r;
    while(1)
    {
        while(arr[d]<=pi && d<u)
        {
            d++;
        }
        while(arr[u]>pi)
        {
            u--;
        }
        if(d<u)
        {
            swap(&arr[d],&arr[u]);
        }
        else
        {
            swap(&arr[u],&arr[l]);
            break;
        }
    }
    return u;
}

void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p=partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}

int main()
{
    int n;
    printf("\nEnter the No of Elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the Elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nAfter Sorting the elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}