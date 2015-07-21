#include<iostream>
using namespace std;
#include<string>
#include<cstdio>

int main()
{
    string s,p;
    int flag=0,i,j;
    cin>>s>>p;
    for(i=0;s[i]!='\0';i++)
    {
        if(p[0]==s[i])
        {
            for(j=1;p[j]!='\0';j++)
            {
                if(p[j]!=s[i+j])
                {
                    flag=0;break;
                }
                else flag=1;

            }
        }
    }
    if(flag==0)cout<<"Not Found";
    else cout<<"Found";
    return 0;
}
