#include <cstdio>
#include <iostream>
#include <algorithm>
#define	MAXN	101010

using namespace std;

int p[MAXN],P=1;
void sieve(){
	p[0]=2;
	for(int i=3;i<MAXN;i+=2){
		bool isp=1;
		for(int j=1; isp and j<P and p[j]*p[j]<=i;++j)
			if(i%p[j]==0)	isp=0;
		if(isp)	p[P++]=i;
	}
}

int main(){
	sieve();
	
	int n,m,t;
	scanf("%d\n",&t);
	
	for(int k=0;k<t;++k){
		scanf("%d %d\n",&m,&n);
		for(int i=m;i<=n;++i){
			bool isp=1;
			for(int j=0;isp and j<P and p[j]*p[j]<=i;++j){
				if(i % p[j]==0)	isp=0;
			}
			if(isp and i!=1)	printf("%d\n",i);
		}

		if(k!=t-1)	printf("\n");
	}
	
	return 0;
}
