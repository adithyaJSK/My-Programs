#include<iostream>
using namespace std;
int Longest_Palin_Substring(int n, char *String)
{
    int max1=0;
    int max2=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        int k=i;
        count=0;
        while( j>=0&&k<n)
        {
            if(String[j]==String[k])
            {
                count++;
                j--;k++;
            }
            else break;
        }
        if(count>max1)max1=count;
        j=i;
        k=i+1;
        count=0;
        while(j>=0&&k<n)
        {
            if(String[j]==String[k])
            {
                count++;
                j--;k++;
            }
            else break;
        }
        if(count>max2)max2=count;
    }
    if(max1>max2)
        return max1*2-1;
    else return max2*2;
}
int main()
{
    char String[100];
    cin>>String;
    int k=strlen(String);
    cout<<Longest_Palin_Substring(k,String);
    return 0;
}
