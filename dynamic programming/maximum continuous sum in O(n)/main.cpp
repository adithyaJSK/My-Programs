#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,a[100],b[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    int max1=b[0],min1=b[n-1];
    for(int i=1,j=n-2;i<=n&&j>=0;i++,j--)
    {
        max1=max(max1,b[i]);
        min1=min(min1,b[j]);
    }
    cout<<max1-min1<<"\n";
        return 0;

}
