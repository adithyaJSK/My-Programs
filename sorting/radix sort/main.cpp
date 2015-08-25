#include <iostream>
using namespace std;
void sorting(int a[],int x,int exp)
{
    int b[10]={0};
    int c[x];
    for(int i=0;i<x;i++)
	b[(a[i]/exp)%10]++;
		for(int i=1;i<x;i++)
			b[i]=b[i]+b[i-1];
		for(int i=x-1;i>=0;i--)
			{
			    c[b[(a[i]/exp)%10]-1]=a[i];
                b[(a[i]/exp)%10]--;
            }
		for(int i=0;i<x;i++)
			a[i]=c[i];
}
void print(int a[],int x)
{
    for(int i=0;i<x;i++)
        cout<<a[i]<<" ";
}
int main() {
    int x,max=-1;
    cin>>x;
    int a[x],c[x],b[10]={0};
    for(int i=0;i<x;i++)
    {
        cin>>a[i];
        max=max>a[i]?max:a[i];
    }
    for(int exp=1;max/exp>0;exp=exp*10)
    {
	sorting(a,x,exp);
    }
    print(a,x);
return 0;

}
