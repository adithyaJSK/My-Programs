#include <iostream>//Construct a Tree using LevelOrder and Inorder
#include <vector>
#include<queue>
using namespace std;
int lo[7]={1,2,3,4,5,6,7};
struct node
{
    int data;
    struct node *left, *right;
};
void preorder(node *root)
{
   if(!root)return;
   cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
struct node *tree(int IN[],int LO[],int first,int last)
{
    int count1,t=first,k=first;
    if(first>last)return NULL;
    struct node *root=new node;
    root->data=LO[t];
    root->left=NULL;root->right=NULL;
    if(first==last){return root;}
    for( count1=first;count1<= last;count1 ++)
    {if(IN [count1]==LO[t])break;}
    //int lo[10];
    //for(int i=first;i<=count1-1;i++)lo[i]=LO[i];
    int LO_new[10];
    for(int i=0;i<7;i++)
    {
        for(int j=first;j<=count1-1;j++)
            if(lo[i]==IN[j]){
                LO_new[k++]=lo[i];break;}

    }
    root->left=tree(IN,LO_new,first,count1-1);
    int h=count1+1;
    for(int i=0;i<7;i++)
    {
        for(int j=count1+1;j<=last;j++)
            if(lo[i]==IN[j]){
                LO_new[h++]=lo[i];break;}
    }
    root->right=tree(IN,LO_new,count1+1,last);
    return root;
}
int main()
{
    struct node *root=new node ;
    int IN[7]={4,2,5,1,6,3,7};
    int LO[7]={1,2,3,4,5,6,7};
    //struct node *root;
    root=tree(IN,LO,0,6);
    preorder(root);
}
