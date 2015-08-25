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
        b[i]=max(a[i],b[i-1]+a[i]);
    }
    int max1=b[0];
    for(int i=1;i<n;i++)
    {
        max1=b[i]>max1?b[i]:max1;
    }
    cout<<max1<<"\n";
}
