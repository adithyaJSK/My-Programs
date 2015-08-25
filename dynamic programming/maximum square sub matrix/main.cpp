#include<iostream>
using namespace std;
int Table[1024][1024];
int A[1024][1024]={0};
void Maximum_Square_SubMatrix(int n, int m)
{
    int min1,max=0,max1,max2;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            Table[i][j]=A[i][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(A[i-1][j-1]==1&&A[i-1][j]==1&&A [i][j-1]&&A[i][j]==1)
            {
                 min1=min(Table[i-1][j-1],Table[i-1][j]);
                Table[i][j]=Table[i][j]+min(Table[i][j-1],min1);
                int max3=Table[i][j];
                if(max3>max){max=max3;max1=i;max2=j;}
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<Table[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Coordinates Are "<<max1-1<<","<<max2-1<<"  "<<max1-max<<","<<max2-max;


}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++ )
    {
        for(int j=1;j<=m;j++)
        {
            cin>>A[i][j];
        }
    }
    Maximum_Square_SubMatrix( n, m);
    return 0;
}
