#include <iostream>//print the kth distance from given node in O(n) order
#include <vector>
using namespace std;
int count1=0,count2=0;
struct node
{
    int data;
    struct node *left, *right;
};
node * newNode(int k)
{
    node *temp=new node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}
void simple(node *root,int k)
{
    if(root==NULL)return;
    if(k==0){cout<<root->data<<" ";return;}
    simple(root->left,k-1);
    simple(root->right,k-1);
}
int trvrs_down(node *root,int  Node, int k)
{
    if(root==NULL){return INT_MIN;}
    if(root->data==Node){simple(root,k);return NULL ;}
    count1=trvrs_down(root->right,Node,k);
    if(count1>=NULL)
        {
            count1++;
    if(count1 ==k){cout<<root->data<<" ";return count1 ;}
    else{simple(root->left,k-count1-1);return count1;}
    }
    count2=trvrs_down(root->left,Node,k);
    if(count2>=NULL)
        {count2++;
    if(count2 ==k){cout<<root->data<<" ";return count2;}
    else{simple(root->right,k-count2-1);return count2;}}
    return INT_MIN;
}
int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root-> right->right= newNode(7);
    struct node * Node;
    cout<<"For Given Tree\n";
    cout<<"      "<<root->data<<"\n";
    cout<<"   "<<root->left->data<<"     "<<root->right->data<<"\n";
    cout<<"  "<<root->left->left->data<<" "<<root->left->right->data<<"   "<<root->right->left->data<<" "<<root->right->right->data<<"\n\n\n";
    //Node=root->right->right;
    cout<<"Enter The Node And Position  ";
    int N ,P;
    cin>>N>>P;
    trvrs_down(root,N,P);
    return 0;
}
