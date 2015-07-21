#include<iostream>
#include<cstdio>
#include<conio.h>
#include<stack>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *new_node(int n)
{
    struct node *temp =new node;
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
/*void display(struct node *root)
{
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->left->left->data<<" "<<root->left->right->data<<" ";
    cout<<root->right->left->data<<" "<<root->right->right->data;
}*/
int LCA(struct node *root)
{
    if(root==NULL)return 0;
    if(root->data==5)return 1;
    else if(root->data==7)return 1;
    //if((root->data!=4)&&(root->data!=5))return 0;
    int s=LCA(root->left);
    int k=LCA(root->right);
    if(k==1&&s==1)
    {
        cout<<root->data;
        return 1;
    }
    else
    {
        return k|s;
    }
}
int main()
{
    struct node *root=new node;
    root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);
    root->right->left=new_node(6);
    root->right->right=new_node(7);
    //display(root);
    LCA(root);
}
