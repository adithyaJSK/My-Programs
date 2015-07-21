#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
    if(x==0)return y;
    if(y==0)return x;
    else
    {
        return gcd(y,x%y);
    }
}
int main()
{
    cout<<gcd(10,20);
   // }
   return 0;
}
