#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define	maxn	500100
#define	INF	(1<<30)

using namespace std;

int sum[4*maxn], bestL[4*maxn], bestR[4*maxn], best[4*maxn];
int a[maxn];

struct seg{
	int best, L, R, S;
	seg(int b,int l,int r,int s){
		best=b;
		L=l;
		R=r;
		S=s;
	}
};


void init(int node, int l, int r){
	if(l==r){
		sum[node] = a[l];
		bestL[node] = a[l];
		bestR[node] = a[l];
		best[node] = a[l];
		return;
	}
	int mid=(l+r)>>1;
	init(2*node+1,l,mid);
	init(2*node+2,mid+1,r);
	sum[node] = sum[2*node+1] + sum[2*node+2];
	best[node] = max( max(best[2*node+1],best[2*node+2]),bestR[2*node+1]+bestL[2*node+2] );
	bestL[node] = max( bestL[2*node+1],sum[2*node+1]+bestL[2*node+2] );
	bestR[node] = max( bestR[2*node+2],sum[2*node+2]+bestR[2*node+1] );
}

seg query(int node, int l, int r, int x, int y){
	if(x>r || y<l)			return seg(-INF,-INF,-INF,0);
	if( x<=l and r<=y ){
//printf("llego a %d - %d: con %d - %d\n",l,r,x,y);
		return seg( best[node],bestL[node],bestR[node],sum[node] );
	}
	
	int best_qL = -INF;
	int best_qR = -INF;
	int bestR_qL = -INF;
	int bestL_qR = -INF;
	int mid=(l+r)>>1;	

	seg segL = query(2*node+1,l,mid,x,y);
	seg segR = query(2*node+2,mid+1,r,x,y);
	
	seg res=seg(0,0,0,0);
	res.S = segL.S + segR.S;
	res.best = max( max(segL.best,segR.best),segL.R + segR.L );
	res.L = max( segL.S + segR.L, segL.L );
	res.R = max( segR.S + segL.R, segR.R );

/*	
	cout<<"Nodo reconstruido: ("<<l<<"-"<<r<<"): con "<<x<<" - "<<y<<endl;
	printf(".... best:  %d\n",res.best);
	printf(".... bestL: %d\n",res.L);
	printf(".... bestR: %d\n",res.R);
	printf(".... suma:  %d\n",res.S);
	printf(".... ............\n");
*/	
	return res;
}

int main(){
	int n,q;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i)	scanf("%d",a+i);
	scanf("%d\n",&q);

	init(0,0,n-1);
	
	for(int i=0,a,b;i<q;++i){
		scanf("%d %d\n",&a,&b);
		seg res = query(0,0,n-1,a-1,b-1);
		printf("%d\n",res.best);
	}
	return 0;
}
