#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#define	maxn	500

using namespace std;

int n,E,s,t;
int capacity[4*maxn];
int last[maxn], p[maxn], d[maxn], times=0;
bool used[maxn];
vector<pair<int,int> > g[maxn];
vector<int> gD[maxn];

void dfs(int u){
	used[u]=1;
	d[u]=times++;
	for(int i=0,v ; i<g[u].size() ; ++i){
		v = g[u][i].first;
		
		bool in=0;
		if(!used[v]){
			p[v] = u;
			gD[u].push_back(v);
			
			dfs(v);
			in = 1;
		}else if(p[u]!=v and p[u]!=-1 and d[u]>d[v]){
			gD[u].push_back(v);
			in = 1;
		}
		if(in){
			capacity[E] = g[u][i].second;
			last[u] = E++;
			capacity[E] = 0;
			last[v] = E++;
		}
	}
}

int augmenting_path(int u, int bottleneck){
	if(used[u] || bottleneck<=0)	return 0;
	if(u==t)		return bottleneck;
	int res=0;
	used[u]=0;
	for(int i=0;i<gD[i].size();++i){
		int v = gD[u][i];
		if(!used[v]){
			res = augmenting_path(v,min(bottleneck,capacity[last[u]] ));
		}
	}

}

int max_flow(int s, int t){
	int f=-1;
	int res=0;
	while(f!=0){
		memset(used,0,sizeof used);
		f = augmenting_path(s,INT_MAX);
		res += f;
	}
	return res;
}

int main(){
	int e;
	while(cin>>n,n){
		cin>>s>>t>>e;
		for(int i=0;i<n;++i)	g[i].clear(),gD[i].clear();
		
		for(int i=0,u,v,cap;i<e;++i){
			cin>>u>>v>>cap;
			g[u-1].push_back( make_pair(v-1,cap) );
			g[v-1].push_back( make_pair(u-1,cap) );
		}
		memset(used,0,sizeof used);
		memset(p,-1,sizeof p);
		memset(d,-1,sizeof d);
		
		E=0, times = 0;
		for(int i=0;i<n;++i)
			if(!used[i])	dfs(i);
			
	
		for(int i=0;i<n;++i){
			cout<<i<<": ";
			for(int j=0;j<gD[i].size();++j)	cout<<gD[i][j]<<" ";
			cout<<endl;
		}
//		int f = max_flow(s,t);

	}
	return 0;
}
