#include <iostream>//path of the node;
#include <vector>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
};
node * newNode(int k)
{
    node *temp=new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
bool findPath(node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL) return false;
    path.push_back(root->key);
    if (root->key == k)
        return true;

    if ( (root->left && findPath(root->left, path, k)) ||(root->right && findPath(root->right, path, k)) )
        return true;
        path.pop_back();
    return false;
}
void PATH(node *root, int n)
{
    vector<int>path1;
    findPath(root,path1,n);
    for(int i=0;i<path1.size();i++)
    cout<<path1[i]<<" ";
}
int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root-> left->left->left= newNode(7);
    PATH(root,4);

    return 0;
}
