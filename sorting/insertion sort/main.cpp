#include<iostream>
#include<cstdio>
//#define for(i,a,b) for(i=a;i<b;i++)
//#define for'(i,a,b) for(i=a;i>b;i--)
#define max(a,b) b>a?b:a
#define min(a,b) a>b?b:a
using namespace std;
void sorting(int a[], int n)
{
    int i,j;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(a[i]<a[j])swap(a[i],a[j]);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
   int n,i;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
    cin>>a[i];
    sorting (a,n);
    return 0;
}
