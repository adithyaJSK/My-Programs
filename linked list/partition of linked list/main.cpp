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
    int n;
    cin>>n;
    while(n--)
    {
        struct node *new_node=new node,*current;
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
    }
}
void display(struct node *low)
{
    struct node *temp=low;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
void search()
{
    struct node *low=NULL,*high=NULL, * current=start;//*current=new node;

    int val;
    cin>>val;
    while(current!=NULL)
    {
        if(current->data>val)
        {
            struct node *temp=new node;
            temp->data=current->data;
            temp->next=high;
            high=temp;
        }
        else if(current->data<val)
        {
            struct node *temp=new node;
            temp->data=current->data;
            temp->next=low;
            low=temp;
        }
        current=current->next;
    }
    struct node *cur=low;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=high;
    display(low);
}
int main()
{
    create();
    search();
}
