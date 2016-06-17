#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int cut[100];
int memo[110][110];

int dp(int p, int r){
	if(p==r || p==r-1)						return 0;
	if(memo[p][r] != -1)		return memo[p][r];
	
	int mn=(1<<30);
	int cost = cut[r]-cut[p];
	
	for(int i=p+1,temp;i<=r-1;++i){
		temp = dp(p,i) + dp(i,r) + cost;
		mn = min(mn,temp);
	}

//cout<<"min entre "<<cut[p]<<" - "<<cut[r]<<" es  "<<mn<<endl;
//cout<<"----------- cost: "<<cost<<endl;	
	return memo[p][r] = mn;
}

int main(){
	int l,n;
	while(scanf("%d\n",&l) , l){
		memset(memo,-1,sizeof memo);
		scanf("%d\n",&n);

		for(int i=0; i<n; ++i)
			scanf("%d",&cut[i+1]);
		cut[0]=0;
		cut[n+1]=l;

		for(int i=0;i<n+1;++i)
			memo[i][i+1]=cut[i+1]-cut[i];
		
//		for(int i=0;i<n+2;++i)	cout<<cut[i]<<" ";
//		cout<<endl;
		
		
		printf("The minimum cutting is %d.\n",dp(0,n+1));

//cout<<endl;		
	}
	return 0;
}
