#include <bits/stdc++.h>
using namespace std;

int t, dp[12], n;
char c[12];
int main()
{
	scanf("%d", &t);
	dp[0] = dp[1] = 1;
	while(t--)
	{
		scanf("%s", c);
		n = strlen(c);
		for(int i=2; i<=n; i++)
		{
			dp[i] = dp[i-1];
			if((c[i-2]-'0')*10+c[i-1]-'0' <=26)
				dp[i] += dp[i-2];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
