#include<iostream>
#include<cstdio>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*start=NULL;
void create()
{

char ch;

 do
    {
    struct node *new_node,*current;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data : \n");
    scanf("%d",&new_node->data);
    new_node->next=NULL;

    if(start==NULL)
    {
        start=new_node;
        current=new_node;
    }
    else
    {
        current->next=new_node;
        current=new_node;
    }
    printf("Do you want to create another : \n");
    ch=getche();
    }while(ch!='n');
}
void display()
{
struct node *new_node;
 printf("\nThe Linked List :\n");
 new_node=start;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL\n\n\n");
}
int main()
{
create();
display();
return 0;
}
//----------------------------------------------------
