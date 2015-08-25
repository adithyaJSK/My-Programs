#include<iostream>
#include<string>
using namespace std;
int Table[1024][1024];
int A[1024];
int Keep[1024][1024]={0};
void Knapsack(int n,int size )
{
    int i,j;
    for( i=0;i<=n;i++)
    {
        for( j=0;j<=size;j++)
        {
            if(i==0||j==0)
                Table[i][j]=0;
            else
            {
                if(A[i-1]<=j)
                {
                    Table[i][j]=max(Table[i-1][j],(Table[i-1][j-(A[i-1])]+A[i-1]));//main algorithm in Table Building
                    if(Table[i][j]==Table[i-1][j-(A[i-1])]+A[i-1])
                        Keep[i][j]=1;
                }
                else Table[i][j]=Table[i-1][j];
            }
        }
    }
    j=size;
    for(i=n;i>=1;)
    {
        for(;j>=1;)
        {
            if(Keep[i][j]==1)
                {
                    cout<<A[i-1]<<" ";
                    j=j-A[i-1];
                    i--;
                    break;
                }
                else if (Keep[i][j]==0)
                {
                    i--;
                    break;
                }
        }
    }
}
int main()
{
    cout<<"Numbers:\n";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int size;
    cout<<"Sum Required\n";
    cin>>size;
    Knapsack(n,size);
    return 0;
}
