#include<bits/stdc++.h>
//#include"tree.h"
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
node *newNode(int key)
{
    struct node *temp =new node;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
bool find_path(node *root,int key,vector<int> &path)
{
    if(root==NULL)
    return false;

    path.push_back(root->data);
    if(root->data==key)
        return true;
    if((root->left&&find_path(root->left,key,path))||root->right&&find_path(root->right,key,path))
        return true;
    path.pop_back();
    return false;
}
void Kth_ancestor(node *root,int key,int i)
{
    vector<int>path1;
    find_path(root,key,path1);
    cout<<path1[path1.size()-1-i];
}
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int a,b;
    printf("Enter the key and kth ancestor  ");
    cin>>a>>b;
    Kth_ancestor(root,a,b);
    return 0;
}
