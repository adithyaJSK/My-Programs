#include<iostream>
#include<string>
#include<cstdio>
#include<string>
using namespace std;
char temp[50];
struct TSTNode
{
    char data;
    int is_End_Of_String;
    struct TSTNode *left,*eq,*right;
}*root=NULL;
struct TSTNode *InsertInTST(struct TSTNode *root,char *word)
{
    if(root==NULL && *word)
    {
        struct TSTNode *root=new TSTNode;
        root->data=*word;
        if(*(word+1))
        {root->is_End_Of_String=0;}
        else
            {root->is_End_Of_String=1;}
        root->left=NULL;
        root->right=NULL;
        root->eq=NULL;
        if(*(word+1)){
        root->eq=InsertInTST(root->eq,(word+1));}
        return root;
    }
   else
        if (*word)
         {
            if(*word<root->data)
            {
                root->left=InsertInTST(root->left,word);

            }
            else if(*word==root->data)
            {
                if(*(word+1))
                {
                    root->eq=InsertInTST(root->eq,(word+1));
                }
                else
                {
                        root->is_End_Of_String=1;
                        return root;
                }
            }
            else root->right=InsertInTST(root->right,word);
            return root;

    }
}
int search(TSTNode *root,char *word)
{
    if(!root)
    {
        return -1;
    }
    else
    {


        if(*word<root->data)
        {
            return search(root->left,(word+1));
        }
        else if(*word>root->data)
        {
            return search(root->right,(word+1));
        }
        else
        {
            if(root->is_End_Of_String==1&&*(word+1)==0)return 1;
             return  search(root->eq,(word+1));
        }
    }
}
void printttree(TSTNode * root,int n)
{
    if(!root)
    {
        return;
    }
    else
    {
        printttree(root->left,n);
        temp[n]=root->data;
        if(root->is_End_Of_String==1)
        {
                temp[n+1]=NULL;
                cout<<temp<<"\n";
        }
        printttree(root->eq,n+1);
         printttree(root->right,n);
    }
}
int delword(TSTNode **root,char *word,int n)
{
    if(!*root)
    {
        return 0;
    }
    else
    {//root->exist
        if(*word<(*root)->data)
        {
            delword(&((*root)->left),word,n);
            return 1;
        }
        else if(*word==(*root)->data && n!=1)
        {
            int l=0,e=0,r=0;
            if((*root)->left)l=1;
            if((*root)->right)r=1;
                e=delword(&((*root)->eq),(word+1),n-1);
            if(l==0 && r==0 && e==0)
            {

                if((*root)->is_End_Of_String==0)
                {
                    *root=NULL;
                    return 0;}
                else return 1;
            }
            else return 1;

        }
        else if(*word==(*root)->data && n==1)
        {
            int l=0,e=0,r=0;
            if((*root)->left)l=1;
            if((*root)->right)r=1;
            if((*root)->eq)e=1;
            if(l==0 && r==0 && e==0)
            {
                *root=NULL;
                return 0;
            }
            else
                {
                    (*root)->is_End_Of_String=0;
                    return 1;
                }
        }
        else if(*word>(*root)->data)
        {
            delword(&((*root)->right),word,n);
            return 1;
        }
    }
}
int main()
{
    char temp[56],word[50],word_search[40],word_delete[40],word1[30];
   int t,t2,t1;
   cout<<"No of Words :\n";
   cin>>t;
    while(t--)
        {
            cin>>word;
            root=InsertInTST(root,word);
        }
       /* cout<<"\nResulted Words\n";
        printttree(root,0);
        cout<<"Numbers Of Search Word\n";
        cin>>t2;
        while(t2--)
            {
                cout<<"Word:\n";
                cin>>word1;
                cout<<search(root,word1);
                 cout<<"\nResulted Words\n";
                printttree(root,0);
            }
            */
        cout<<"Number of Delete word\n";
        cin>>t1;
        while(t1--)
        {
            cout<<"Word:\n";
            cin>>word;
            int len=strlen(word);
            delword(&root,word,len);
            //cout<<"\nResulted Words\n";
            //printttree(root,0);
        }
    return 0;
}
