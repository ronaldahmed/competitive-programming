#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define	maxn	11000
#define	fst		first
#define	snd		second
#define	pb		push_back
#define mp		make_pair
using namespace std;

typedef pair<int,int> pii;
int sons[maxn],total;
bool used[maxn];
vector<pii>  g[maxn];
vector<pair<pii,int> > ord;
map<pii,int> edges;

int dfs(int u){
	used[u] = 1;
	int sum=1;

//cout<<"llegue "<<u<<endl;
	
	for(int i=0,v;i<g[i].size();++i){
		v = g[u][i].fst;
		if(!used[v])
			sum += dfs(v);
	}
	
	return sons[u]=sum;
}

void dfs2(int u){
	used[u]=1;
	for(int i=0,v;i<g[i].size();++i){
		v = g[u][i].fst;
		if(!used[v]){
			pii temp = mp( (sons[v]-1)*(total-sons[v]-1),g[u][i].snd );
			ord.pb(mp(temp, edges[mp(min(u,v),max(u,v))]) );
		}
	}
}

int main(){
	int n,k,sh,sc;
	while(cin>>n>>k>>sh>>sc){
		for(int i=0;i<n;++i)	g[i].clear();
		ord.clear();
		edges.clear();
		memset(sons,0,sizeof sons);
		
		for(int i=0,u,v,l;i<n-1;++i){
			cin>>u>>v>>l;
			if(u>v)	swap(u,v);
			g[u-1].pb(mp(v-1,l));
			g[v-1].pb(mp(u-1,l));
			edges[mp(u-1,v-1)]=i+1;
//			cout<<"----- "<<u<<" "<<v<<" "<<i+1<<endl;
		}
/*
		for(int i=0;i<n;++i){
			cout<<i<<": ";
			for(int j=0;j<g[i].size();++j)
				printf("%d(%d) ",g[i][j].fst,i<=g[i][j].fst?edges[mp(i,g[i][j].fst)]:-1);
			cout<<endl;
		}
*/		
		memset(used,0,sizeof used);
		total = dfs(0);

//		cout<<"llegue"<<endl;
		
		memset(used,0,sizeof used);
		dfs2(0);
		int l = ord.size();
		sort( ord.begin(),ord.end() );

//for(int i=0;i<l;++i)	cout<<ord[i].fst.fst<<" "<<ord[i].fst.snd<<" - "<<ord[i].snd<<endl;
		
		if(sh<sc){
			for(int i=0;i<min(k,l);++i){
				printf("%d%c",ord[l-1-i].snd, i==k-1?'\n':' ' );
			}
		}else{
			for(int i=0;i<min(k,l);++i){
				printf("%d%c",ord[i].snd, i==k-1?'\n':' ' );
			}
		}		 
	}
	return 0;
}
