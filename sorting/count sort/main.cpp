#include <iostream>
using namespace std;

int main() {
	int n,i,max;
	cin>>n;
	int a[n];
	int b[1000]={0};
	max=-1;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		max=max>a[i]?max:a[i];
	}
	for(i=0;i<n;i++)
	{
		b[a[i]]++;
	}
	for(i=0;i<=max;i++)
	{
		while(b[i]!=0)
		{
			cout<<i<<" ";
			b[i]--;
		}
	}
	return 0;
}
