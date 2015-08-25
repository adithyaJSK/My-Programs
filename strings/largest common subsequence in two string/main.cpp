#include<iostream>
#include<string>
using namespace std;
int s[50][50];
char x[50],y[50];
void LCString()
{
    int k=strlen(x);
    int l=strlen(y);
//int s[k+1][l+1];
    for(int i=0;i<=k;i++)
        s[i][0]=0;
    for(int j=0;j<=l;j++)
        s[0][j]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(x[i-1]==y[j-1])
                s[i][j]=max(max(s[i-1][j],s[i][j-1]),s[i-1][j-1]+1);
            else
                s[i][j]= max(s[i-1][j],s[i][j-1]);
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=l;j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void search()
{
    int k=strlen(x);
    int l=strlen(y);
//int s[k+1][l+1];
    char d[50]={0};
    int g=0;

    for(int i=k;i>=1;)
    {
        for(int j=l;j>=1;)
        {
           if(x[i-1]==y[j-1])
           {

               d[g]=y[j-1];
               g++;
                i--;j--;
           }
           else
           {
               if((s[i-1][j]>s[i][j-1])||(s[i-1][j]==s[i][j-1]))
               i--;
                else
               j--;
           }
           if(j<0||i<0)break;
           }
    }
    for(int i=strlen(d)-1;i>=0;i--)
    {
        cout<<d[i];
    }
}
int main()
{
    cin>>x;
    cin>>y;
    LCString();
    cout<<"Largest Common Sub Sequence\n";
    search ();
    return 0;
}
