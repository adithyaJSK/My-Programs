#include<iostream>
using namespace std;
int no_of_str(int n)
{
    if(n==1)return 2;
    if(n==2)return 3;
    else
    {
        return no_of_str(n-1)+no_of_str(n-2);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<no_of_str(n);
    return 0;
}
