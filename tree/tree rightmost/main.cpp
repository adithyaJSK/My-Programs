#include<iostream>//Right most elements of the tree
#include<vector>
using namespace std;
int temp=0;
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

void right_most(node *root,int l)
{
    if(root==NULL)return;
    if(l>temp)
    {
        cout<<root->data;temp=l;
    }
    right_most(root->right,l+1);
    right_most(root->left,l+1);

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
    root-> left->left->left= newNode(7);
    int a,b;
    cout<<"The right most elements in the tree ";
    right_most(root,1);

    return 0;
}
