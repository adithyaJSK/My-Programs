//math
//combinatrics
//dp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;

ll ncr[2005][1005];

int main() {
       for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= min(1000,i); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                ncr[i][j] = 1;

            // Calculate value using previosly stored values
            else
                ncr[i][j] = (ncr[i-1][j-1]%m + ncr[i-1][j]%m)%m;
        }
    }
    ll k;
    cin>>k;
    vector<ll> ha(k);
    ll ans[k];
   for(ll i=0;i<k;i++)
    { cin>>ha[i];

    }
    ll dp[k];
    dp[0]=1;
    ll prev=ha[0];
    for(int i=1;i<k;i++)
    {

        ll n=ha[i]-1;
        ll baba=ncr[prev+ha[i]-1][ha[i]-1];
        dp[i]=((baba%m)*(dp[i-1]%m))%m;

        prev+=ha[i];
    }
    cout<<dp[k-1]<<endl;


    }
