#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int t;
	long long n,m;
	scanf("%d\n",&t);
	while(t--){
		scanf("%lld %lld\n",&n,&m);
		long long temp=__gcd(n,m);
		long long res=2, sq=sqrt(temp);
		for(int i=2;i<(int)sq+1;++i)
			if(temp%i==0 )
				if(temp==i*i)	++res;
				else			res+=2;
		printf("%lld\n",res);
	}	
	return 0;
}
