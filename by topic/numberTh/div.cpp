#include <iostream>
#include <cstring>
#include <algorithm>
#define	MAXN	10000

using namespace std;
int p[MAXN+1],A[MAXN+1], f[MAXN], d[MAXN],D=0, pc=0;

void sieve(){
	memset(A,0,sizeof A);
	for(int i=2;i<=MAXN;++i){
		if(!A[i])	p[ A[i]=++pc ]=i;
		for(int j=1; j<=A[i] && i*p[j]<=MAXN ;++j)
			A[i*p[j]] = j;
	}
}

int fact(int n){
	memset(f,0,sizeof f);
	int F=0;
	while(p[A[n]]){
		f[F++] = p[A[n]];
		n/=p[A[n]];
	}
//	f[F++] = n;
	return F;
}

void div(int cur,int s, int e){
	if(s==e)	d[D++] = cur;
	else{
		int m;
		for(m=s+1; m<e && f[s]==f[m] ;m++);
		for(int i=s; i<=m ;++i){
			div(cur,m,e);
			cur*=f[s];
		}
	}
}

int main(){
	sieve();
	int fp=fact(30);
	sort(f,f+fp);

	cout<<fp<<endl;	
	for(int i=0;i<fp;++i)		cout<<f[i]<<" ";
	cout<<endl;
	
	div(1,0,fp);
	cout<<D<<endl;
	sort(d,d+D);
	for(int i=0;i<D;++i)	cout<<d[i]<<" ";
	cout<<endl;
	
	return 0;
}
