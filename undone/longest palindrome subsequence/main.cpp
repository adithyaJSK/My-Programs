#include<iostream>
#include<string>
using namespace std;
int Table[1024][1024]={0};
int Long_Pal_SubSeq(int k,char A[])
{
    int count=0;
    for(int i=1;i<k;i++)
    {
        Table[i][i]=1;
        count=1;
        if(A[i+1]==A[i]){
            Table[i][i+1]=1;
            count=2;
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
           //int  l=i+j-1;
            if(A[i]==A[j])
            {
                Table[i][j]=Table[i+1][j-1]+2;
            }
            else
            Table[i][j]=max(Table[i+1][j-1],Table[i][j-1]);
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cout<<Table[i][j]<<" ";
        }
        cout<<"\n";
    }
    return count;
}
int main()
{
    char A[100];
    cin>>A;
    int k=strlen(A);
    cout<<Long_Pal_SubSeq(k,A);
    return 0;
}
