#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double x,y;
    double sucess=0,thrown=0;
    //cout<<double(RAND_MAX);
    for(long long int i=0;i<100000000;i++)
    {
       x=double(rand())/double(RAND_MAX);
       y=double(rand())/double(RAND_MAX);
       thrown++;
       if(    (  (x*x) + (y*y)  ) <=1   )
       {
           sucess++;
       }
    }
    double h=sucess/thrown;
    cout<<4*h<<"\n";
  return 0;
}
