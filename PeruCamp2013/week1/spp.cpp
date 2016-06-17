#include <iostream>
#include <cstring>
#include <cstdio>
#define	MAXN	20

using namespace std;

long long b[MAXN], c[MAXN],p;
long long sum[MAXN];

struct matrix{
	int f,c;
	long long mat[MAXN][MAXN];

	void init(int a, int b){
		memset(mat,0LL,sizeof mat);
		f=a;
		c=b;
	}
	void identity(){
		for(int i=0;i<f;++i)	mat[i][i]=1LL;
	}
};

matrix operator * (matrix const& a, matrix const& b){
	matrix res;
	res.init(a.f,b.c);
	for(int i=0;i<a.f;++i){
		for(int j=0;j<b.c;++j){
			for(int k=0;k<a.c;++k){
				res.mat[i][j] = ( res.mat[i][j] + (a.mat[i][k]*b.mat[k][j])%p + p)%p;
			}
		}
	}
	return res;
}

matrix A,B;

matrix expo(long long y, matrix x){
	matrix res;
	res.init(x.f,x.c);

	res.identity();
	while(y>0LL){
		if(y&1)	res = res*x;
		y>>=1;
		x = x*x;
	}
	res.f = x.f;
	res.c = x.c;
	return res;
}

int main(){
/*	p = 1000;
	matrix aa,bb,dd;
	aa.init(3,3);
	aa.identity();

	bb.init(3,1);
	bb.mat[0][0]=2LL;
	bb.mat[1][0]=3LL;
	bb.mat[2][0]=2LL;
	
	dd = aa*bb;
//	dd = expo(4,bb);
	
	for(int i=0;i<dd.f;++i){
		for(int j=0;j<dd.c;++j)	cout<<dd.mat[i][j]<<" ";
		cout<<endl;
	}
*/	
	int t,k;
	long long m,n;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&k);
		
		for(int i=0;i<k;++i)	scanf("%lld",b+i);
		for(int i=0;i<k;++i)	scanf("%lld",c+i);
		scanf("%lld %lld %lld\n",&m,&n,&p);

		
		A.init(k+1,k+1);
		B.init(k+1,1);

		A.mat[k][0]=0LL;
		A.mat[0][0]=1LL;
		B.mat[0][0]=0LL;
		for(int i=0;i<k;++i){
			A.mat[k][i+1]=c[k-i-1];
			A.mat[i][i+1]=1LL;
			B.mat[i+1][0]=b[i];
		}
				
		matrix sumN = expo(n,A)*B;
		matrix sumM = expo(m-1,A)*B;
		
//cout<<sumM.mat[0][0]<<" "<<sumN.mat[0][0]<<endl;
		
		printf("%lld\n",(sumN.mat[0][0]-sumM.mat[0][0] +p)%p);
	}
	return 0;
}
