#include <cstdio>
#include <iostream>
#include <cstring>
#define	mod	100

using namespace std;

int fast(int b, int e){
	int res=1;
	while(e){
		if(e&1)	res = (res*b)%mod;
		e>>=1;
		b = (b*b)%mod;
	}
	return res;
}

int main(){
	int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans = 0;
		for(int i=1;i<=n;++i)
			ans = (ans + fast(i,m))%mod;
		if(ans<10)	printf("0");
		printf("%d\n",ans);
	}
	return 0;
}
