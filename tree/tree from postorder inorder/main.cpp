#include <iostream>//Construct a Tree using Pre order and In order
#include <vector>
#include<queue>
using namespace std;
//int n;
struct node
{
    int data;
    struct node *left, *right;
};
int k=2;//assumed k=2 for n=3, i.e. k=n-1
struct node * tree(int a[],int b[],int j,int n)
{
            int h;

            if(j>n)return NULL;
            struct node *root=new node;
            //int k=n;
            root->data=b[k--];
            root->left=NULL;
            root->right=NULL;
            if(j==n){return root;}
            for( h=n;h>=j;h--)
            {if(a[h]==b[k+1])break;}
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
    int i;
    cout<<"Enter Elements of Array:  ";
    //cin>>n;
    int a[3],b[3];
    cout<<"Enter Inorder:  ";
    for(i=0;i<3;i++)
        cin>>a[i];
    cout<<"Enter Postorder:   ";
    for(i=0;i<3;i++)
        cin>>b[i];
        static int x=3;
    levelorder(tree(a,b,0,2));
    return 0;
}
