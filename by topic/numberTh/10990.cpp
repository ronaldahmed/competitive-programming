#include <iostream>
#include <cstring>
#define	MAXN	2000001

using namespace std;
int p[MAXN+1], A[MAXN+1], phi[MAXN+1], pc=0;
int step[MAXN+1];
long long sum[MAXN +1];

void sieve(){
	memset(A,0,sizeof A);
	for(int i=2;i<=MAXN;++i){
		if(!A[i])	p[ A[i]=++pc ]=i;
		for(int j=1; j<=A[i] && i*p[j]<=MAXN ;++j)
			A[i*p[j]] = j;
	}
}

void phi_sieve(){
	phi[1]=1;
	for(int i=2;i<=MAXN;++i){
		if(i==p[A[i]])
			phi[i] = i-1;
		else{
			int px = p[A[i]];
			int aux= i / px;
			if(aux % px==0)		phi[i] = px * phi[aux];
			else				phi[i] = (px-1) * phi[aux];
		}
	}
}

int memo(int u){
	int c=0,m=u;
	while(u!=1){
		u=phi[u];
		c++;
		if(step[u]!=0){
			c+=step[u];
			break;
		}
	}
	return step[m]=c;
}

int main(){
	sieve();
	phi_sieve();
	memset(step,0,sizeof step);

	step[1]=0;
	sum[0]=0;
	sum[1]=0;

	for(int i=2;i<=MAXN;++i)
		sum[i]=sum[i-1] + memo(i);
	
	int n,a,b;
		
	cin>>n;
	while(n--){
		cin>>a>>b;
		cout<<sum[b]-sum[a-1]<<endl;
	}
	
	return 0;
}
