#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define	MAXN	1011

using namespace std;

int dp[MAXN][MAXN];

int main(){
	string a,b;
	while(getline(cin,a)){		
		getline(cin,b);
		memset(dp,0,sizeof dp);

		for(int i=1;i<=a.size();++i)
			for(int j=1;j<=b.size();++j){
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		printf("%d\n",dp[a.size()][b.size()]);
	}
	return 0;
}