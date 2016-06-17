#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define		K	33LL
#define		MAXN	100100
#define		C		5381LL

using namespace std;
typedef unsigned long long hash;
hash T[MAXN], P[MAXN], pow[MAXN];
int lt,lp;

hash calc_hash(int a, int b, hash* A){
	return A[b]-A[a]*pow[b-a];
}

int lcp(int t, int p){
	int s=0, e=lp-p+1;
	while(e-s>1){
		int md=(s+e)>>1;
		if(calc_hash(t,t+md,T) == calc_hash(p,p+md,P) )		s=md;
		else												e=md;
	}
	return s;
}

int main(){
	int tc;cin>>tc;
	string t,p;

	pow[0]=1;
	for(int i=1;i<MAXN;++i)	pow[i]=pow[i-1]*K;

	while(tc--){
		cin>>p>>t;
		hash ans=0LL;	
		lt=t.size();
		lp=p.size();

//cout<<p<<" "<<t<<": "<<lt<<" "<<lp<<endl;

		for(int i=0;i<max(lt,lp)+1;++i)	T[i]=0LL, P[i]=0LL;
		
		T[0]=C;
		P[0]=C;
		for(int i=1;i<lt+1;++i)	T[i]=T[i-1]*K + t[i-1]-'a';
		for(int i=1;i<lp+1;++i)	P[i]=P[i-1]*K + p[i-1]-'a';

		for(int i=0;i<lt-lp+1;++i)
			ans+=lcp(i,0);
		cout<<ans<<endl;
	}
	return 0;
}
