#include <iostream>
#include <cstring>
#include <vector>
#define		MAXN	10100

using namespace std;
vector<vector<int> > g;
bool used[MAXN], cut[MAXN];

void dfs(int u){
	used[u]=1;
	int lu=g[u].size();
	
	for(int i=0;i<lu;++i){
		if(!used[g[u][i]])
			dfs(g[u][i]);
	}
}

void dfs2(int u){
	used[u]=1;
	int lu=g[u].size();
	
	for(int i=0;i<lu;++i){

		if(!used[g[u][i]] and (!cut[u] or !cut[g[u][i]]) ){	
			dfs2( g[u][i] );
		}
	}
}

int main(){
	int t,n,e,k;
	cin>>t;
	while(t--){
		cin>>n>>e>>k;
		vector<int> p;
		g.clear();
		g.resize(n,p);
		
		memset(cut,0,sizeof cut);
		for(int i=0,u,v;i<e;++i){
			cin>>u>>v;
			g[u-1].push_back(v-1);
			g[v-1].push_back(u-1);

			if(i<k)	cut[u-1]=1, cut[v-1]=1;
		}
				
		memset(used,0,sizeof used);
		int c=0, c1=0;
		for(int i=0;i<n;++i)
			if(!used[i] ){
				dfs(i);
				++c;
			}
		
		memset(used,0,sizeof used);
		vector<int> temp;
		for(int i=0;i<n;++i)
			if(!used[i]){
				dfs2(i);
				++c1;
//				temp.push_back(i);
			}
			
//cout<<"c c1:  "<<c<<" "<<c1<<endl;			

//for(int i=0;i<temp.size();++i)	cout<<temp[i]+1<<" ";
//cout<<endl;


		if(c1-c>=1)	cout<<"YES"<<endl;
		else		cout<<"NO"<<endl;
	}
	return 0;
}
