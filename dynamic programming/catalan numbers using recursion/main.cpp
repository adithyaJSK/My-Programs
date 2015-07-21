#include <iostream>
using namespace std;
long long int T(int n)
{
     if(n==0)return 1;
     int count=0;
     for(int i=1;i<=n;i++)
     {
         count+=T(i-1)*T(n-i);
     }
     return count;
}
int main()
{
    long long int n=1,t,k;
    cin>>t;
    while(t--)
        {
            k=T(n++);
            cout<<k<<"\n";
        }
    return 0;
}
