#include<stdio.h>
#include<stdlib.h>

struct node
{
    int n;
    struct node *next;
    struct node *pre;
}*start=NULL;

typedef struct node node;

int end=1;

void insert(int data,int pos)
{
    if(start==NULL && pos!=1)
    {
        printf("S\norry wrong position entered3");
        return;
    }

    node *ptr=(node *)malloc(sizeof(node));
    ptr->n=data;
    ptr->next=NULL;
    ptr->pre=NULL;

    if(pos==1)
    {
        ptr->next=start;
        if(start!=NULL)
            start->pre=ptr;
        start=ptr;
    }
    else
    {
        node *p=start;
        while(pos>2)
        {
            if(p->next==NULL)
            {
                printf("\nSorry wrong position entered");
                return;
            }
            p=p->next;
            pos--;
        }
        ptr->next=p->next;
        ptr->pre=p;
        p->next=ptr;
        if(p->next!=NULL)
            p->next->pre=ptr;
    }
    end++;
}

void traverse()
{
    node *ptr=start;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->n);
        ptr=ptr->next;
    }
}

int main()
{
    // int n;
    // while(1)
    // {
    //     printf("\nEnter your choice");
    //     printf("\n1.Insert at start");
    //     printf("\n2.Insert at end");
    //     printf("\n3.Insert at at a position");
    //     printf("\n4.Insert at after a element");
    //     printf("\n5.Traverse");
    //     printf("\n6.exit");
    //     scanf("%d",&n);
    //     switch(n)
    //     {
    //         case 1:insert(5,)
    //     }
    // }  
    insert(2,1);
    insert(5,1);
    insert(8,2);
    insert(4,3);
    insert(1,end);
    insert(1,9);
    traverse();
    return 0;
}