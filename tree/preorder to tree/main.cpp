#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
#define max(a,b)(if(a>b)return a;else return b;)
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
int i=0;
struct node *preorder(int a[],int n)
{
    struct node *root = new node, *temp;
    if(i>=n)return NULL;
    root->data=a[i];
        if(a[i]==1)
            {
                root->right=NULL;
                root->left=NULL;
                i++;
                return root;
            }
        i++;
        root->left= preorder(a,n);
        root->right=preorder(a,n);
        return root;


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
int main()
{
    int n,i;
    struct node * root=new node;
    printf("Enter No of Elements Of Array:   ");
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
   root= preorder(a,n);
   printf("The Sorted Levelorder Tree is:   ");
   levelorder(root);
   printf("\n\n\n");
    return 0;
}
