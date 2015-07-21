//it can also be done by sorting the array and save it in different array
//then take the longest common subsequence
//done in other folder to consult
#include<iostream>//longest increasing subsequence problem
#include<string>
using namespace std;
int Table[128];
int LIS(int a[],int n)
{
    int max1=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((Table[i]<Table[j]+1)&&(a[i]>a[j]))
                Table[i]=Table[j]+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        max1=max1>Table[i]?max1:Table[i];
    }
    int max2=max1;
    for(int i=n-1;i>=0;i--)
    {
        if(Table[i]==max1)
        {
            cout<<a[i]<<" ";
            max1--;
        }
    }
    cout<<"\n";
    return max2;
}
int main()
{
   int a[128],n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
    {
        Table[i]=1;
    }
   cout<<"Length "<<LIS(a,n);
   return 0;
}

