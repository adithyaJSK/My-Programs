#include <iostream>
#include<string>
#include<string.h>
#include<strings.h>
using namespace std;
void del(char *str)
{
    int low=0,high=0;
    int ch=0
    for(int i=0;i<strlen(str);i++)
    {
        int val =str[i]-'a';
        if((ch&(1<<val))>0)
        else {low++;high++;}
    }
}
bool fun(char str[])
{
    int ch=0;
    for(int i=0;i<strlen(str);++i)
    {
        int val=str[i]-'a';

        if((ch&(1<<val))>0)
        {

            return true;
        }
        ch|=1<<val;
    }
    return false;
}
int main()
{
   char str[90];
    cin>>str;
    cout<<fun(str);
    del(str);
    //cout << "Hello world!" << endl;
    return 0;
}
