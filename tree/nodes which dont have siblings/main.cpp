#include <iostream>//Print all nodes which dont have siblings
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
node *newNode(int k)
{
    node *temp=new node;
    temp->data=k;
    temp->left=temp->right=NULL;
}
int sibling(node *root)
{
    int i=0,j=0;
    if(root==NULL)return INT_MIN;
    //cout<<"a";
    i=sibling(root->left);
    j=sibling(root->right);
    if(i<0&&j==0){cout<<root->right->data<<" ";}
    else if (j<0&&i==0){cout<<root->left->data<<" ";}
    return 0;

}
int main()
{
    int x;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    x=sibling (root);
}
