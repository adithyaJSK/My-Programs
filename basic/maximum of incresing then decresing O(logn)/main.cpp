#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int start=0;
    int end=n-1;

    int mid=(start+end)/2;
    while(1)
    {
        if(a[0]>=a[1]){cout<<a[0];break;}
        if(a[n-1]>=a[n-2]){
        cout<<a[n-1];break;}
        if((a[mid]>a[mid+1])&&(a[mid]>a[mid-1]))
        {
            cout<<a[mid];
            break;
        }
        else if(a[mid]<a[mid+1])
        {
            start=mid;
            mid=(start+end)/2;

        }
        else
        {
            end=mid;
            mid=(start+end)/2;
        }
    }
}
