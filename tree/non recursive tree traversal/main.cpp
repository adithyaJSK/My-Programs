#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
struct node
{
    int data;
    struct node*left,*right;
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
void preorder(struct node *root)
{
    stack <struct node*>s;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();
        if(root->right);
        root=root->right;
    }
}
void inorder(struct node *root)
{
    stack<struct node*>s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
        root=root->right;

    }
}
/*void postorder(struct node* root)
{
    stack <struct node * >s;
    while(1)
    {
        while(root)
        {
            if(root->right)
                s.push(root->right);
            s.push(root);
            root=root->left;
        }
        //else
            {
                if(s.empty())
                    return;
                else if(s.top()->right==NULL)
                {
                    root=s.top();
                    s.pop();
                    cout<<root->data<<" ";
                    //root=s.top();
                    if(root==s.top()->right)
                    {
                        cout<<s.top()->data<<" ";
                        root=s.top();
                        s.pop();
                    }
                }

                    if(s.empty())
                        root=s.top()->right;
                    else root=NULL;



            }
    }
}*/
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
    cout<<"Preorder Traversal   ";
    preorder(root);
    cout<<"\nInorder Traversal    ";
    inorder(root);
    cout<<"\nPostordertraversal   ";
    //postorder(root);
    return 0;
}
