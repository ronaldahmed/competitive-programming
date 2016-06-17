#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;
const int maxn = 100005;

ll dp[maxn][2];
ll gen[maxn];
int tests[maxn][2];

int main(){
	int t,k;
	int mx = 0;
	
	cin >> t >> k;
	for(int i=0;i<t;++i){
		cin >> tests[i][0] >> tests[i][1];
		mx = max(mx,tests[i][1]);
	}
	
	dp[0][0] = 0LL;
	dp[0][1] = 1LL;
	gen[0] = 0LL;
	for (int i=1;i<=mx;++i){
		dp[i][0] = i>=k?((dp[i-k][1] + dp[i-k][0]) % MOD): 0LL;
		dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % MOD;
		gen[i] = ((dp[i][0] + dp[i][1]) % MOD + gen[i-1]) % MOD;
	}

	/*	
	for (int i=0;i<=mx;++i)
		cout << gen[i] << " ";
	cout << endl;
	*/
	for(int i=0;i<t;++i){
		cout << (gen[tests[i][1]] - gen[tests[i][0]-1] +MOD) % MOD<< endl;
	}
	
	return 0;
}
