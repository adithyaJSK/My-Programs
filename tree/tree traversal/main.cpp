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
void inorder(node * root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node * root)
{
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(node *root)
{
   if(!root)return;
   cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void levelorder(node *root)
{
    queue <struct node *> r;
    r.push(root);
    while(!r.empty())
    {
        root=r.front();
        cout<<root->data<<" ";
        r.pop();
        if(root->left)
        r.push(root->left);
        if(root->right)
        r.push(root->right);
    }
}
void zigzag()
{
    int flag=0;
    stack <struct node *> r,s;
    r.push(root);
    while(1)
    {
        if(flag==0)
        {//printf("hello");
            while(!r.empty())
            {
                root=r.top();
                cout<<root->data<<" ";
                r.pop();
                if(root->left)
                s.push(root->left);
                if(root->right)
                s.push(root->right);
            }
            flag=1;
        }
        if((r.empty())&&(s.empty()))
        return;
        if(flag==1)
        {
            while(!s.empty())
            {
                root=s.top();
                cout<<root->data<<" ";
                s.pop();
                if(root->right)
                r.push(root->right);
                if(root->left)
                r.push(root->left);
            }
            flag=0;
        }
        if((r.empty())&&(s.empty()))
        return;
    }
}
void distance(node *Node, int *temp1, int *temp2, int head)
{
    if ( Node == NULL ) return;
    if ( head < *temp1 )  *temp1 = head;
    else if ( head > *temp2 ) *temp2 = head;
    distance( Node->left, temp1, temp2, head-1 );
    distance( Node->right, temp1, temp2, head+1 );
}
void print(node *Node, int i, int head)
{
    if (Node==NULL) return;
    if (head == i)
    cout << Node->data << " ";
    print(Node->left,i, head-1);
    print(Node->right,i, head+1);
}
void vertorder(node *root)
{
    int temp1 =0, temp2= 0;
    distance(root, &temp1, &temp2,0);
    for (int i = temp1;i <=temp2;i++)
    {
        print(root,i,0);
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
    printf("Inorder Traversal    ");
    inorder(root);
    printf("\nPostorder Traversal  ");
   postorder(root);
   printf("\nPreorder Traversal   ");
   preorder(root);
   printf("\nLevelorder Traversal ");
    levelorder(root);
    printf("\nZigzag Traversal     ");
    zigzag();
    printf("\nVertical Traversal   ");
    vertorder(root);
    return 0;
}
