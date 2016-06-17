#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define	maxn	500

using namespace std;
typedef pair<int,int> pii;
int avoid;
bool used[maxn];
vector<int> g[maxn];
vector<pii> edges;

pii dfs(int u, int h){
	used[u]=1;

//cout<<"deb: "<<u<<endl;
	
	pii mx(0,0);
	bool in=0;
	for(int i=0,v;i<g[u].size();++i){
		v = g[u][i];
		
		
		if(!used[v] and v != avoid){
			pii x = dfs(v,h+1);
			in=1;
			if(mx.second < x.second)	mx=x;
		}
	}
	if(in)	return mx;
	else		return make_pair(u,h);
}

int diameter(int u, int av){
	memset(used,0,sizeof used);
	
	if(g[u].size()==1)	return 0;
	avoid = av;
	pii x = dfs(u,0);
	
//	cout<<"---------"<<x.first<<endl;
	
	memset(used,0,sizeof used);
	pii y = dfs(x.first,0);
	return y.second;
}

int main(){
	int n;
	cin>>n;
	for(int i=0,u,v;i<n-1;++i){
		cin>>u>>v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
		if(u>v)	swap(u,v);
		edges.push_back(make_pair(u-1,v-1));
	}
	
/*	for(int i=0;i<n;++i){
		cout<<i+1<<": ";
		for(int j=0;j<g[i].size();++j)	cout<<g[i][j]+1<<" ";
		cout<<endl;
	}
*/	
	int mx=0;
	for(int i=0;i<edges.size();++i){
//		cout<<edges[i].first+1<<" - "<<edges[i].second+1<<endl;
		
		int d1 = diameter(edges[i].first,edges[i].second);
		int d2 = diameter(edges[i].second,edges[i].first);
		
//		cout<<edges[i].first+1<<" - "<<edges[i].second+1<<": "<<d1<<" "<<d2<<endl<<"...................."<<endl;
		mx=max(mx,d1*d2);
	}
	
	cout<<mx<<endl;
	
	return 0;
}
