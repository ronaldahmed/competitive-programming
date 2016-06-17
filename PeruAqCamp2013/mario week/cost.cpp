#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define	REP(i,x,y)	for(int i=x;i<y;++i)
#define	MAXN	100100
#define	mp		make_pair
#define	pb		push_back
#define	fst		first
#define	snd		second
#define	MOD		1000000000

using namespace std;

int unionF[MAXN], rank[MAXN], parent[MAXN];
long long acumW[MAXN];

vector<pair<int,pair<int,int> > > edges;

int main(){
	int n, m; scanf("%d %d\n",&n,&m);
	int u,v,w;
	if(m!=0){
		REP(i,0,m){
			scanf("%d %d %d",&u,&v,&w);
			edges.pb(mp(-w,mp(u-1,v-1)));
		}	
		sort(edges.begin(),edges.end());
	
		REP(i,0,n)			rank[i]=1, unionF[i]=i,parent[i]=-1;

		acumW[m-1]=-edges[m-1].fst % MOD;
		
		REP(i,1,m)			acumW[m-1-i]=(long long)(-edges[m-1-i].fst + acumW[m-i]) % MOD;

		long long cost=0LL;
		REP(i,0,m){
			u=edges[i].snd.fst;
			v=edges[i].snd.snd;
	//cout<<"u v: "<<u<<" "<<v<<endl;

			while(parent[u]!=-1)	u=parent[u];
			while(parent[v]!=-1)	v=parent[v];
		
	//cout<<"luego u v: "<<u<<" "<<v<<endl;		
			if(unionF[u]!=unionF[v]){
				if(rank[u]<rank[v])	swap(u,v);
				cost=(cost + (acumW[i]*rank[u]*rank[v]) % MOD) % MOD;
				rank[u]=(rank[u]+rank[v]) % MOD;
				parent[v]=u;
				unionF[v]=unionF[u];
			}
		}
	
	//	REP(i,0,n)	cout<<unionF[i]<<" ";
	//	cout<<endl;
	
		printf("%lld\n",cost);
	}else
		printf("%lld\n",0LL);

	return 0;
}
