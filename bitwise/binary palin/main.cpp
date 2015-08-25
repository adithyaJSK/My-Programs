#include <iostream>//Check if binary representation of a number is palindrome
using namespace std;

int main() {
	int x,flag=1,k;
	int a[1000];
	cin>>x;
	for(int i=0;x>0;i++)
	{
		a[i]=x%2;
		//cout<<a[i]<<" ";
		k=i;
		x=x/2;
	}
	for(int j=0;j<k;)
	{
		if(a[j++]==a[k--])
		continue;
		else
		flag=0;
	}
	if(flag==0)cout<<"False";
	else cout<<"True";
	return 0;
}
