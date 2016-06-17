#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define	MAXN	100100
#define	oo		(1<<30)

using namespace std;
int T[4*MAXN], a[MAXN];

void init(int node, int l,int r){
	if(l==r){
		T[node]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	init(2*node+1,l,mid);
	init(2*node+2,mid+1,r);
	T[node] = min(T[2*node+1],T[2*node+2]);
}

int query(int node, int l, int r, int x, int y){
	if(x>r || y<l)		return oo;
	if(x<=l and r<=y)	return T[node];
	int mid=(l+r)>>1;
	return min( query(2*node+1,l,mid,x,y),query(2*node+2,mid+1,r,x,y) );
}

int main(){
	int t,n,q;
	scanf("%d\n",&t);
	for(int k=0;k<t;++k){		
		memset(T,0,sizeof T);
		scanf("%d %d\n",&n,&q);
		for(int i=0;i<n;++i)	scanf("%d",a+i);
		init(0,0,n-1);
		
//		for(int i=0;i<n;++i)	cout<<a[i]<<" ";
//		cout<<endl;
		
//		cout<<"..."<<query(0,0,n-1,0,2)<<endl;
		
		printf("Scenario #%d:\n",k+1);
		for(int i=0,u,v;i<q;++i){
			scanf("%d %d\n",&u,&v);
			printf("%d\n",query(0,0,n-1,u-1,v-1));
		}
	}
	
	return 0;
}
