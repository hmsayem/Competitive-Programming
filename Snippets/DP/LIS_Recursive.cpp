#include <bits/stdc++.h>
using namespace std;
#define mx 1000
int n=7;
int value[]={INT_MIN,5,0,9,2,7,3,4};
int dp[mx],dir[mx];
int longest(int u)
{
	if(dp[u]!=-1) return dp[u];
	int maxi=0;
	for(int v=u+1;v<=n;v++)
	{
		if(value[v]>value[u])
		{
			if(longest(v)>maxi)
			{
			      maxi=longest(v);
                              dir[u]=v;
			}
		}
	}
	dp[u]=1+maxi;
	return dp[u];
}


void solution(int start)
{
	while(start!=-1)
	{
		printf("index %d value %d\n",start,value[start]);
		start=dir[start];
	}
}

int main()
{
	memset(dp,-1,sizeof dp);
        memset(dir,-1,sizeof dir);
	int LIS=0,start;

	for(int i=1;i<=n;i++)
	{
		printf("longest path from node %d is : %d\n",i,longest(i));
		if(longest(i)>LIS)
		{
			LIS=longest(i);
			start=i;
		}
	}

	printf("LIS = %d Starting point %d\n",LIS,start);
	solution(start);

	return 0;
}
