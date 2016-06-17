#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define REP(i,a,b)  for(int i=a;i<(int)b;i++)
#define FOR(it,A)   for(typeof A.begin() it=A.begin();it!=A.end();it++)
#define all(x)      (x).begin(),(x).end()
#define pb          push_back
#define clr(x,y)    memset(x,y,sizeof x)
#define oo          (1<<30)
#define INF             (1LL<<40)
#define bit(x)      __builtin_popcount(x)
#define mp          make_pair
#define fst         first
#define snd         second
#define MAXN        10000005
#define mod         1000000007
#define max2		100005

int p[max2], A[MAXN+1], pc=0;
int ccount[max2];
int acum[max2];

void sieve(){
	for(int i=2;i<=MAXN;++i){
		if(!A[i])	p[ A[i]=++pc ]=i;
		for(int j=1; j<=A[i] && i*p[j]<=MAXN ;++j)
			A[ i*p[j] ] = j;
	}
}

int main(){
	sieve();
	int n,m;
	cin>>n;
	REP(i,0,n){
		int x;
		cin>>x;
		while(x>1){
			ccount[A[x]]++;
			x /= A[x];
		}
	}
	acum[0] = ccount[0];
	REP(i,1,max2){
		acum[i] = acum[i-1] + ccount[i];
	}
	
	cin>>m;
	REP(i,0,m){
		long long l,r;
		cin>>l>>r;
		int* lp = lower_bound(p,p+max2,l);
		int* rp = lower_bound(p,p+max2,r);
	}
	
	return 0;
}
