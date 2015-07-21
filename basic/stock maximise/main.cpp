#include<iostream>
#include<stack>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
       cin>>a[i];
       stack <int >s;
       s.push(a[n-1]);
       int temp,count,sum,ans;
       temp=a[n-1];
       count=0;
       sum=0;
       ans=0;
       for(int i=n-2;i>=0;i--)
       {
           if(a[i]<=temp)
           {
               s.push(a[i]);
               count++;
               sum=sum+a[i];

           }

           else
           {
               ans=ans+temp*count-sum;
               while(!s.empty())
               {
                   s.pop();
               }
               count=0;
               sum=0;
               s.push(a[i]);
               temp=a[i];
           }

       }
       ans=ans+temp*count-sum;
       cout<<ans<<"\n";

   }
    return 0;
}
