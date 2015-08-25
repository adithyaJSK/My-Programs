#include<iostream>
#include<string>
using namespace std;

int main()
{
    long long int a[5005],n;
    a[0]=0;a[1]=1;
    for(int i=2;i<5005;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=1;i<80;i++)
    {
        cout<<i<<" "<<a[i]<<"\n";
    }
}
