#include <iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;

int count=0;
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1;
        ++i;
    }
}

void SieveOfEratosthenes(int n)
{

    if (n >= 2)
    {

        bool arr[n];
        memset(arr, 0, sizeof(arr));

        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                count++;
                printf("%d,", i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        count=0;
        //printf("Following are the prime numbers below %d\n", n);
        SieveOfEratosthenes(n);
        cout<<count<<"\n";
    }

}
