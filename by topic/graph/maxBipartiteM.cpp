/*
#include <iostream>
#include <vector>
#define	maxn	1000

using namespace std;
bool used[maxn];
vector<int> g[maxn];
int left[maxn], right[maxn];

bool dfsBM(int u){
	if(used[u])		return 0;
	used[u] = true;
	for(int i=0,v;i<g[u].size();++i){
		v = g[u][i];
		if( left[v]==-1 || dfsBM(left[v]) ){
			left[v] = u;
			return 1;
		}
	}
	return 0;
}

int main(){
	int cardBM=0;
	for(int i=0;i<left_size();++i){
		memset(used,0,sizeof used);
		cardBM += dfsBM(i);
	}
	
	return 0;
}
*/
