#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    char s[50];
    cin>>s;
    int a=strlen(s);
        int count =1;
        for(int i=0;i<strlen(s);)
        {
            if(s[i]==s[i+1])
            {
                count++;
                i++;
            }
            else if(count >1)
            {
                cout<<s[i]<<count;
                count=1;
                i++;
            }
            else
            {
                cout<<s[i];
                count=1;
                i++;
            }
        }

    return 0;

}
