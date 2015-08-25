#include<iostream>
#include<string>
using namespace std;

int main()
{
    int max1=-1;
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
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            max1=max(max1,b[j]-b[i-1]);
        }
    }
    cout<<max1<<"\n";
        return 0;

}
