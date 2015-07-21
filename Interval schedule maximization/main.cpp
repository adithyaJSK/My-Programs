//Interval schedule Maximization
//Order O(nlogn)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar
#define mp make_pair
#define pb push_back
inline ll in()
{
char temp;
	ll x=0;
	temp=gc();
	while(temp<48)temp=gc();
	x+=(temp-'0');
	temp=gc();
	while(temp>=48){
		x=x*10;
		x+=(temp-'0');
		temp=gc();
	}
	return x;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		ll n;
		scanf("%lld",&n);
		vector<pair<ll,ll> > v;
		for(ll i=0;i<n;i++)
		{
			ll n1,n2;
			n1=in();
			n2=in();
			v.pb(mp(n2,n1));
		}
		sort(v.begin(),v.end());
		ll end=-1;
		ll count=0;
		vector<pair<ll,ll> >::iterator it1=v.begin();
		for(;it1!=v.end();it1++)
		{
			if((it1->second)>end)
			{
				count++;
				end=it1->first;
			}
		}
		printf("%lld\n",count);
		v.clear();
	}
}
