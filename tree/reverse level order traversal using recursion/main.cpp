#include<iostream>
#include<queue>
#include<math.h>
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
void level_recursive( struct node *root,int level)
{
    if(root==NULL)
    return;
    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else
    {
        level_recursive(root->left,level-1);
        level_recursive(root->right,level-1);
    }
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
    int h=log2(n)+1;
    for(int i=h;i>=1;i--)
    {
        level_recursive(root,i);
    }
    return 0;
}
