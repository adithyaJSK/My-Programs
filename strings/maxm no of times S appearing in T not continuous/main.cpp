#include<iostream>
#include<string>
using namespace std;
int Table[1024][1024];
int main()
{
    char S[20],T[20];
    cin>>T;
    cin>>S;
    int k=strlen(T);
    int l=strlen(S);
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=k;j++)
        {

            if(j==0)
                Table[i][j]=0;
                else if(i==0)
                Table[i][j]=1;
            else
            {
                if(S[i]==T[j])
                    Table[i][j]=Table[i-1][j-1]+Table[i][j-1];
                else Table[i][j]=Table[i-1][j];
            }
        }
    }
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cout<<Table[i][j]<<" ";
        }
        cout<<"\n";
    }
    //last value in Table[][] gives the result
    return 0;
}
