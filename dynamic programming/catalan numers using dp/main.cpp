#include <iostream>
long long int Table[10024]={0};
using namespace std;
void  T(int n)
{
    //if(Table[n]!=0)return Table[n];//return prevoius table
        for(int i=1;i<=n;i++)
        {
            Table[n]=Table[n]+Table[i-1]*Table[n-i];//use of previous tables
        }
    Table[n]=Table[n];
}
void dp()
{
    for(int i=1;i<1009;i++)
    {
        T(i);
    }
}
int main()
{
    int t;
    cin>>t;
    Table[0]=1;
    dp();
    while(t--)
    {
        int n;
        cin>>n;
        cout<<Table[n-1]<<"\n";
    }
    return 0;
}
