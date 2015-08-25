#include<iostream>
#include<string>
using namespace std;
int Table[1024][1024];
int A[1024][1024];
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
                if(A[i-1][1]<=j)
                {
                    Table[i][j]=max(Table[i-1][j],(Table[i-1][j-(A[i-1][1])]+A[i-1][0]));//main algorithm in Table Building
                    if(Table[i][j]==Table[i-1][j-(A[i-1][1])]+A[i-1][0])
                        Keep[i][j]=1;
                }
                else Table[i][j]=Table[i-1][j];
            }
        }
    }
    //print Table
    for( i=0;i<=n;i++)
    {
        for(j=0;j<=size;j++)
        {
            cout<<Table[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    //print Keep
    for( i=0;i<=n;i++)
    {
        for(j=0;j<=size;j++)
        {
            cout<<Keep[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    j=size;
    for(i=n;i>=1;)
    {
        for(;j>=1;)
        {
            if(Keep[i][j]==1)
            {
                cout<<A[i-1][0]<<"/"<<A[i-1][1]<<" ";
                j=j-A[i-1][1];
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
    int size;
    cout<<"Size Of Knapsack\n";
    cin>>size;
    cout<<"No. of items\n";
    int items;
    cin>>items;
    for(int i=0;i<items;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(j==0)cout<<"Value\n";
            else cout<<"Weight\n";
            cin>>A[i][j];
        }
    }
    Knapsack(items,size);
    return 0;
}
