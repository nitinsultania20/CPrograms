#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
}*top = NULL;

typedef struct node node;

void push(int data)
{
  node* p = (node*) malloc(sizeof(node));
  p->next = top;
  p->data = data;
  top = p;
}

int pop()
{
  if(top == NULL)
    return 0;
  node *p = top;
  top = p->next;
  int data = p->data;
  free(p);
  return data;
}

void traverse()
{
  node *p = top;
  while(p != NULL)
  {
    printf("%d\n",p->data);
    p = p->next;
  }
}

int main()
{
  int op;
  start:
  printf("Enter Choice: 1. Push 2. Pop 3. Traverse 4. Exit");
  scanf("%d",&op);
  while(op != 4)
  {
    switch(op)
    {
      case 1: printf("Enter Data : ");
	      int data;
              scanf("%d",&data);
              push(data);
              break;
      case 2: printf("Popped Data : %d\n",pop());
	      getchar();
              break;
      case 3: traverse();
	      getchar();
	      break;
      default: printf("Enter correct choice.\n");
              getchar();
              break;
    }
    goto start;
  }
  while(top != NULL)
  {
    node* p = top;
    top = p->next;
    free(p);
  }
  return 0;
}
