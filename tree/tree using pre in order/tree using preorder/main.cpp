#include <iostream>//Construct a Tree using Pre order and In order
#include <vector>
#include<queue>
using namespace std;
int count1=0,count2=0;
struct node
{
    int data;
    struct node *left, *right;
};
static int s=0;
struct node * tree(int a[],int b[],int j,int n)
{
            int h;
            if(j>n)
                return NULL;
            struct node *root=new node;
            root->data=b[s++];
            root->left=NULL;root->right=NULL;
            if(j==n){return root;}
            for( h=j;h<=n;h++)
            {if(a[h]==b[s-1])break;}
            root->left=tree(a,b,j,h-1);
            root->right=tree(a,b,h+1,n);
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
    cout<<"Enter Elements of Array:  ";
    cin>>n;
    int a[n],b[n];
    cout<<"Enter Inorder:  ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter Preorder:   ";
    for(i=0;i<n;i++)
        cin>>b[i];
    levelorder(tree(a,b,0,n-1));
    return 0;
}
