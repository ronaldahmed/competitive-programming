#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define maxX 10100

using namespace std;
int a[500];
bool dp[maxX][500];

int main(){
	int n,X;
	cin>>n>>X;
	for(int i=0;i<n;++i)	cin>>a[i];

	vector<int> coin;
	for(int k=n-1;k>=0;--k){
		memset(dp,0,sizeof dp);
		swap(a[n-1],a[k]);
		for(int i=0;i<=n;++i)	dp[0][i]=1;
		for(int i=1;i<=X;++i)	dp[i][0]=0;
		
//		cout<<".....................probe para a[i] : "<<a[n-1]<<endl;

		for(int j=1;j<=n-1;++j){
			for(int i=1;i<=X;++i){
				dp[i][j] = dp[i][j-1];
				if( i-a[j-1] >= 0 )
					dp[i][j] = dp[i][j] || dp[ i-a[j-1] ][j-1];

//				if(dp[i][j])
//						printf("..in x:%d  - k: %d\n",i,a[j-1]);				
			}
		}
		if(!dp[X][n-1])	coin.push_back(a[n-1]);
		swap(a[k],a[n-1]);
	}
	cout<<coin.size()<<endl;
	for(int i=0;i<coin.size();++i){
		printf("%d%c",coin[i],i==coin.size()-1?'\n':' ');
	}
	
	return 0;
}
