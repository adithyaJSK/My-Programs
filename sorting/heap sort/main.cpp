#include<iostream>
#include<cstdio>
using namespace std;
void heapify(int a[],int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(2*i+1<=n-1&&2*i+2<=n-1)
            {
            if(a[i]<a[2*i+1])
                swap(a[i],a[2*i+1]);
            if(a[i]<a[2*i+2])
                swap(a[i],a[2*i+2]);
            }
        if(2*i+1<=n-1)
           if(a[i]<a[2*i+1])
                swap(a[i],a[2*i+1]);
    }
}
void heapsort(int a[],int n)
{
    int c[n];
    for(int i=n;i>=1;i--)
        {
    heapify(a,i);
    c[i-1]=a[0];
    a[0]=a[i-1];
    a[i-1]=-1000;
    }
    for(int i=0;i<n;i++)cout<<c[i]<<"\n";
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    return 0;
}
