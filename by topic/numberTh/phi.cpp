#include <iostream>
#include <cstring>
#define	MAXN	100001

using namespace std;
int p[MAXN+1], A[MAXN+1], phi[MAXN+1], pc=0;

void sieve(){
	memset(A,0,sizeof A);
	for(int i=2;i<=MAXN;++i){
		if(!A[i])	p[ A[i]=++pc ]= i;
		for(int j=1; j<=A[i] && i*p[j]<=MAXN ;j++)
			A[i*p[j]]=j;
	}
}

void phi_sieve(){
	phi[1]=1;
	for(int i=2;i<=MAXN;++i){
		if(i==p[A[i]])
			phi[i]=i-1;
		else{
			int px = p[A[i]];
			int aux = i / px;
			if( aux%px==0 )		phi[i] = px*phi[aux];
			else				phi[i] = (px-1)*phi[aux];
		}
	}
}

int main(){
	sieve();
	phi_sieve();
	
	for(int i=0;i<100;++i)	cout<<phi[i]<<" ";
	cout<<endl;
	return 0;
}
