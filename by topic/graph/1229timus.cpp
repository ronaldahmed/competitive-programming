#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define	maxn	11000
#define	pb	push_back

using namespace std;
bool used[maxn];
int Left[maxn], grid[200][200];
int dx[4] = {-1,0,1, 0};
int dy[4] = { 0,1,0,-1};
vector<int> g[maxn];
vector<int> L;

void dfsCountLeft(int u,bool side){
	used[u]=1;
	if(side)	L.pb(u);
	
	for(int i=0,v;i<g[u].size();++i){
		v = g[u][i];
		if(!used[v])
			dfsCountLeft(v,!side);
	}
}

bool dfsBM(int u){
	if(used[u])	return 0;
	used[u]=1;
	for(int i=0,v;i<g[i].size();++i){
		v = g[u][i];
		if(Left[v]==-1 || dfsBM(Left[v])){
			Left[v]=u;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m;
	int maxNum=0;

	cin>>n>>m;
		
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin>>grid[i][j];
			maxNum = max(maxNum,grid[i][j]);
		}
	for(int i=0;i<maxn;++i)	g[i].clear();

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			for(int k=0;k<4;++k){
				int x = i + dx[k];
				int y = j + dy[k];
				if(x>=0 and x<n and y>=0 and y<m and grid[x][y]!=grid[i][j]){
					g[i*m+j].pb(x*m+y);
//					g[x*m+y].pb(i*m+j);
				}
			}
		}
	}
	
	memset(Left,-1,sizeof Left);
	memset(used,0,sizeof used);
	
	for(int i=0;i<n*m;++i)
		if(!used[i])
			dfsCountLeft(i,1);

/*
for(int i=0;i<n*m;++i){
	cout<<i<<": ";
	for(int j=0;j<g[i].size();++j)	cout<<g[i][j]<<" ";
	cout<<endl;
}

cout<<"----"<<endl;
for(int i=0;i<L.size();++i)	cout<<L[i]<<" ";
cout<<endl<<"------------"<<endl;
*/
	
	int card=0;
	for(int i=0;i<L.size();++i){
		memset(used,0,sizeof used);
		card += dfsBM(L[i]);
	}

	memset(used,0,sizeof used);
	
	if(card == maxNum){
		int secLayer[200][200];
		for(int i=0;i<L.size();++i){
			used[L[i]]=1;
			int x = L[i]/m;
			int y = L[i]%m;
			secLayer[x][y] = i+1;

			int k=0;
			while(used[g[L[i]][k]]) k++;
			used[g[L[i]][k]]=1;
//cout<<"painted u v: "<<L[i]<<" "<<g[L[i]][k]<<endl;
			x = (g[L[i]][k])/m;
			y = (g[L[i]][k])%m;
			secLayer[x][y] = i+1;
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				printf("%d%c",secLayer[i][j],j==m-1?'\n':' ');
			}
	}else
		printf("-1\n");
	return 0;
}
