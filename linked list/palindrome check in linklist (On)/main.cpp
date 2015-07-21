#include<iostream>
#include<cstdio>
#include<conio.h>
#include<stack>
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
void palindrome()
{
    int flag=1;
    stack <int> s;
    struct node *slow=start,*fast=start;
    while(fast!=NULL)
    {
        s.push(slow->data);
        slow=slow->next;
        fast=fast->next;
        if(!fast)
        {
            s.pop();

             break;
        }

        else
            fast=fast->next;
    }
    while(slow!=NULL)
    {
        if(slow->data!=s.top())
        {
            flag=0;
            break;
        }
        else
        {
            slow=slow->next;
            s.pop();
        }
    }
    if(flag==0)cout<<"false";
    else cout<<"true";


}
int main()

{
    create();
    palindrome();
}
