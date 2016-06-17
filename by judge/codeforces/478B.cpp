#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define	mp 	make_pair
#define	REP(i,x,y)		for(int (i)=(x); i < (y); ++i)
#define	DEBUG(x)			cout << (x) << endl;
#define	inf						(1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn	= 	1000001;

int main(){
	ll n,m;
	cin >> n >> m;
	ll mn,mn1,mn2, mx;
	
	if(n==m){
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	
	mx = (n-m)*(n-m+1)/2LL;
	ll fc = n/m;
	ll ch = n%m;
	ll R = (n - ch * (fc+1)) / (m-ch);

	
	mn = ch*(fc+1LL)*fc/2LL + (m-ch)*R*(R-1LL)/2LL;

	cout << mn << " " << mx << endl;
	return 0;
}
