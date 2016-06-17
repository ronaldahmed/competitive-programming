#include <iostream>
#include <cstdio>
#include <cstring>
#define	INF	(1<<30)
#define	MAXN	110000

using namespace std;
long long sum[4*MAXN], childs[4*MAXN];

void update(int node, int l, int r, int x, int y, int val){
	if(x>r || y<l)		return;
	if(x<=l && r<=y)	sum[node]+=val;
	else{
		int mid=(l+r)>>1;
		update(2*node+1,l,mid,x,y,val);
		update(2*node+2,mid+1,r,x,y,val);
		
		childs[node]=childs[2*node+1] + childs[2*node+2] + (mid-l+1)*sum[2*node+1] + (r-mid)*sum[2*node+2];
	}
}

long long query(int node,int l, int r, int x, int y){
	if( x>r || y<l )	return 0LL;
	long long res = (min(y,r)-max(x,l)+1)*sum[node];
	if( x<=l && r<=y )	res+=childs[node];
	else{
		int mid=(l+r)>>1;
		res+= query(2*node+1,l,mid,x,y) + query(2*node+2,mid+1,r,x,y);
	}
	return res;
}

int main(){
	int t,n,c;
	scanf("%d\n",&t);
	while(t--){
		memset(sum,0,sizeof sum);
		memset(childs,0,sizeof childs);
		
		scanf("%d %d\n",&n,&c);
		int opc,x,y,val;
		for(int i=0;i<c;++i){
			scanf("%d %d %d",&opc,&x,&y);
			if(opc==0){
				scanf("%d",&val);
				update(0,1,n,x,y,val);
			}else
				printf("%lld\n",query(0,1,n,x,y) );
		}
	}
	return 0;
}
