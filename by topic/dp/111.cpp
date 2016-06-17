#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int a[100], order[100], dp[100][100];

int main(){
	int n,tt;
	cin>>n;
	for(int i=1,temp;i<=n;++i){
		cin>>temp;
		order[temp]=i;
	}

	while(cin>>tt){
		a[tt]=1;
		for(int i=2;i<=n;++i){			
			cin>>tt;
			a[tt]=i;
		}		
		memset(dp,0,sizeof dp);	

		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i]==order[j])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

/*		cout<<"----------"<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)	cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
*/
		cout<<dp[n][n]<<endl;
		memset(a,0,sizeof a);
	}
	return 0;
}