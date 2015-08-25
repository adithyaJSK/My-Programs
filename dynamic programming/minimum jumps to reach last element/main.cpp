#include <iostream>
#include<algorithm>
using namespace std;
int Jumps(int *A,int n)
{
    int Table[100],temp[100]={0};
    for(int i=0;i<n;i++)Table[i]=INT_MAX;
    int k=0;
    Table[0]=0;
    if(n==0||A[0]==0)return 0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]>=(i-j))
            {
                if((Table[j]+1)<Table[i])
                    Table[i]=Table[j]+1;
            }
        }
    }
    cout<<"Jumps From\n";
    int i=n;
        while(Table[i-1]!=0)
        {
            i=Table[i-1];
            cout<<A[i-1]<<" ";
        }
        cout<<"\nTable required\n";
    for(int i=0;i<n;i++)
        cout<<Table[i]<<" ";
    cout<<"\n";
    return Table[n-1];
}
int main()
{
    int n,A[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<Jumps(A,n);
    return 0;
}
