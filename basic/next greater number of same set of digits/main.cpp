#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
            char s[100];
    cin>>s;
    int k=strlen(s);
    int i;
    for(i=k-1;i>=0;i--)
    {
        if(s[i]>s[i-1])
        {
            break;
        }
    }
    //cout<<i;
    if(i<0)
    {
        cout<<"Not Possible\n";
    }
    else
    {
        int temp;
        temp=s[i-1];
        s[i-1]=s[k-1];
        s[k-1]=temp;
        //sort(s+i,s+k);
        //cout<<s;
        for(int j=0;j<i;j++)
        {
            cout<<s[j];
        }
        for(int j=k-1;j>=i;j--)
        {
            cout<<s[j];
        }
        cout<<"\n";
        }
    }
return 0;
}
