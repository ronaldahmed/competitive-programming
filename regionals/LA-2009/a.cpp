#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define	MAXN	100100

using namespace std;

vector<vector<int> > g;
int gout[MAXN],memo[MAXN],n,t;

int dp(int u){
	if(memo[u]!=-1)	return memo[u];
	multiset<int> q;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(gout[v]==0)	q.insert(1);
		else				q.insert(dp(v));
	}
	int needed = ceil((t/100.0) * gout[u] );
	
	memo[u]=0;
	multiset<int>::iterator it;
	it = q.begin();
	for(int i=0;i<needed;++i){
		memo[u] += (*it);
		it++;
	}
	return memo[u];
}

int main(){
	while(scanf("%d %d\n",&n,&t),n && t){
		g.clear();
		vector<int> p;
		g.assign(n+1,p);
		memset(gout,0,sizeof gout);
		memset(memo,-1,sizeof memo);
		
		for(int i=0,v;i<n;++i){
			scanf("%d",&v);
			g[v].push_back(i+1);
			gout[v]++;
		}
		
/*		for(int i=0;i<n+1;++i){
			cout<<i<<": ";
			for(int j=0;j<g[i].size();++j)	cout<<g[i][j]<<" ";
			cout<<endl;
		}
*/		
		printf("%d\n",dp(0));
		
//		cout<<".-----------."<<endl;
	}
	return 0;
}
