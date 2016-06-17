#include <iostream>
#include <cstring>
#define	MAXN	100000
using namespace std;
int p[MAXN+1], A[MAXN+1], pc=0;

void sieve(){
	memset(A,0,sizeof A);
	for(int i=2;i<=MAXN;++i){
		if(!A[i])	p[ A[i]=++pc ]=i;
		for(int j=1; j<=A[i] && i*p[j]<=MAXN ;++j)
			A[ i*p[j] ] = j;
	}
}

int main(){

	sieve();
	
	for(int i=0;i<100;++i)	cout<<p[i]<<" ";
	cout<<endl;
	
	return 0;
}
