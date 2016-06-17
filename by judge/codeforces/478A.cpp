#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

#define	mp 	make_pair
#define	REP(i,x,y)		for(int (i)=(x); i < (y); ++i)
#define	DEBUG(x)			cout << (x) << endl;
#define	inf						(1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn	= 	1000001;

int main(){
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int sum = a + b + c + d + e;
	if(sum%5 == 0 && sum!=0)
		cout << sum/5 << endl;
	else
		cout << -1 << endl;
	return 0;
}
