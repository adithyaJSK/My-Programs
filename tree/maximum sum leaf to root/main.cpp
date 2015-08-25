#include<iostream>
#include<cstdio>
#include<queue>
#include<queue>
#include<vector>
#include<stack>
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
int sumofpath(struct node * root)
{
    if(root==NULL)return 0;
    int max1=sumofpath(root->left);
    int max2=sumofpath(root->right);
    root->data=root->data+(max1>max2?max1:max2);
    return root->data;
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
    cout<<sumofpath(root);
}
