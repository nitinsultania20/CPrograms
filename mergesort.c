//Merge Sort

#include<stdio.h>

void merge(int arr[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    int a[r-l+1];
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            a[k++]=arr[i];
            i++;
        }
        else
        {
            a[k++]=arr[j];
            j++;
        }
    }
    while(i<=m)
    {
        a[k++]=arr[i];
        i++;
    }
    while(j<=r)
    {
        a[k++]=arr[j++];
    }

    for(int t=0;t<k;t++)
    {
        arr[l+t]=a[t];
    }
}

void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid =(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main()
{
    int n;
    printf("\nEnter the nunmber of Elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the Elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergesort(arr,0,n);
    printf("After Sorting the Elemnts are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}