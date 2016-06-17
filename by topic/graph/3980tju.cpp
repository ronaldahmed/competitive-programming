#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define 	maxn	10100
#define	REP(i,x,y)	for(int i=(x);i<(y);++i)
#define	mp	make_pair
#define	pb	push_back
#define	INF	(1LL<<40)

using namespace std;
typedef pair<int,int> pii;
vector<pii> g[maxn];
int gout[maxn] , minpath;
long long minL;
bool used[maxn];

long long dfs(int u){
	if(g[u].size()==0){
//cout<<"u: "<<u<<"  ---"<<endl;
		minpath++;
		return 0LL;
	}
	used[u] = 1;
	long long acum = 0LL, mn=INF;
	int w_min=0;
	
//cout<<"u: "<<u<<"  --------------"<<endl;
	REP(i,0,g[u].size()){
		int v = g[u][i].first;
		int w = g[u][i].second;
		long long temp;
		
		if(!used[v]){
			temp = dfs(v);
//printf("---temp: %lld  -  w : %d  \n",temp,w);
			
			if(temp+w < mn){
				mn = temp+w;
				w_min = w;
			}
			acum += temp;
		}
	}
	
	minL += (acum-mn+w_min);
	
//printf("u: %d - acum: %lld  - w_min: %d  - mn : %lld \n",u,acum,w_min,mn);
// cout<<"-------------------"<<endl;
	if(u==0)
		return minL + mn;
	else
		return mn;
}

int main(){
	int n, k=1;

	while(cin>>n){
		REP(i,0,n)	g[i].clear();
		memset(gout,0,sizeof gout);
		
		REP(i,0,n-1){
			int f,w;
			cin>>f>>w;
			g[f].pb(mp(i+1,w));
			gout[f]++;
		}
		memset(used,0,sizeof used);
		minpath=0;
		minL = 0LL;
		long long ans = dfs(0);

		printf("Case #%d: %d %lld\n",k++,minpath,ans);
	}
	return 0;
}
