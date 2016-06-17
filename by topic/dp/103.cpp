#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define	MAXK	50

using namespace std;

vector<int> boxes[MAXK];
vector<vector<int> > g,gt;
vector<int> L;
int n,k, dp[MAXK], p[MAXK];
bool used[MAXK];

bool fit(int a, int b){
	for (int i = 0; i < n; ++i)	
		if(boxes[a][i]>=boxes[b][i])
			return 0;
	return 1;
}

void dfs(int u){
	used[u]=1;
	for(int i=0;i<g[u].size();++i)
		if(!used[g[u][i]])
			dfs(g[u][i]);
	L.push_back(u);
}

int main(){	
	while(cin>>k>>n){
		for(int i=0;i<k;++i)	boxes[i].clear();		
		g.clear();
		gt.clear();

		for(int i=0;i<k;++i)
			for(int j=0,temp;j<n;++j){
				cin>>temp;
				boxes[i].push_back(temp);
			}
		for(int i=0;i<k;++i)	sort(boxes[i].begin(),boxes[i].end());
		
		vector<int> q;
		g.assign(k,q);
		gt.assign(k,q);
		memset(used,0,sizeof used);
		memset(dp,0,sizeof dp);
		memset(p,-1,sizeof p);
		L.clear();

		for(int i=0;i<k;++i)
			for(int j=0;j<k;++j)
				if(i!=j and fit(i,j)){
					g[i].push_back(j);
					gt[j].push_back(i);
				}
		
/*		cout<<"...-------------......"<<endl;
		for(int i=0;i<k;++i){
			cout<<i<<": ";
			for(int j=0;j<g[i].size();++j)	cout<<g[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
*/

		for(int i=0;i<k;++i)
			if(!used[i])	dfs(i);

		reverse(L.begin(),L.end());		
		
/*		cout<<"--------- "<<L.size()<<"-----"<<endl;
		for(int i=0;i<L.size();++i)	cout<<L[i]<<" ";
		cout<<endl;
*/
		int mx , idx=L.back();
		int mx_total=0,idx_total;
		for(int i=0;i<k;++i){
			mx=0;
			for(int j=0,v;j<gt[ L[i] ].size();++j){
				v = gt[L[i]][j];
				if(mx < dp[v]){
//cout<<"updated: "<<L[i]<<" to "<<v<<endl;
					mx = dp[v];
					p[L[i]] = v;
					idx = L[i];
					if(mx+1>mx_total){
						mx_total = 1+mx;
						idx_total = idx;
					}
				}
			}
			dp[L[i]] = 1+mx;
		}
		
		if(mx_total==0){
			printf("1\n1\n");
		}else{
			vector<int> par;

			cout<<mx_total<<endl;
			while(idx_total != -1){
				par.push_back(idx_total+1);
				idx_total=p[idx_total];
			}
			for(int i=par.size()-1;i>=0;--i)
				printf("%d%c",par[i],i==0?'\n':' ');
		}
	}
	return 0;
}