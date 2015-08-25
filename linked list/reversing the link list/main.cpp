#include <iostream>
#include<cstdio>
#include<conio.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*start=NULL;
void create()
{

    char ch;
    do{
        struct node *new_node,*current;
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data");
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
            current =new_node;
        }
        printf("Want to continue");
        ch=getche();
    }while(ch!='n');
}
void display()
{
    struct node *new_node=start;

    while(new_node!=NULL)
    {

        printf("%d\n",new_node->data);
        new_node=new_node->next;
    }
}
void revdisp()
{
    struct node *temp1,*temp2,*new_node=start;
    temp1=new_node;
    temp2=new_node->next;

    while(temp2!=NULL)
    {
    temp1->next=temp2->next;
    temp2->next=new_node;

    new_node=temp2;
    temp2=temp1->next;
    }

    while(new_node!=NULL)
    {
        printf("%d\n",new_node->data);
        new_node=new_node->next;
    }
}
int main()
{
create();
display();
revdisp();
return 0;
}
