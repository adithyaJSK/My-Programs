#include<bits/stdc+.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;

void construct(int n)
{
    queue <struct node *> r;
    node *temp=new node;
    temp->data=n;
    temp->left=NULL;temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *temp2;
        r.push(root);
        while(!r.empty())
        {
            temp2=r.front();
            r.pop();
            if(temp2->left==NULL)
            {
                temp2->left=temp;
                break;
            }
            else if(temp2->right==NULL)
                {
                    temp2->right=temp;
                    break;
                }
                else
                {
                   r.push(temp2->left);
                    r.push(temp2->right);
                }
        }
        return;
    }
}
struct node *BSTdel(struct node *root,int min,int max)
{

    if(root==NULL)
    {
        return NULL;
    }
    root->left=BSTdel(root->left,min,max);
    root->right=BSTdel(root->right,min,max);
    if((root->data)<min)
    {
        node *root1=root->right;
        delete root;
        return root1;

    }
    else if((root->data)>max)
    {
        node *root2=root->left;
        delete root;
        return root2;
    }
    return root;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        construct(x);
    }
    int min,max;
    cin>>min>>max;
    BSTdel(root,min,max);
    preorder(root);
    return 0;

}
