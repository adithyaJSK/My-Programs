#include <iostream>
#include<cstdio>
using namespace std;
void mysubstr(char str[], int low, int high)
{
    printf("%.*s", high-low+1, (str+low));//%.*is a width specifier
}

int main ()
{
    char str[100],x,y;
    scanf("%s",str);
    mysubstr(str, 1,6);
    return 0;
}
