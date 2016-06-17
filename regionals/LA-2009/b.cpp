#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define	MAXN	200

using namespace std;
int n,r,c,k;
int grid[MAXN][MAXN], gridNew[MAXN][MAXN];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int main(){
	while(scanf("%d %d %d %d",&n,&r,&c,&k),n && r && c && k){
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)	cin>>gridNew[i][j];		
		
		while(k--){
			for(int i=0;i<r;++i)
				for(int j=0;j<c;++j)	grid[i][j]=gridNew[i][j];

			for(int i=0;i<r;++i)
				for(int j=0;j<c;++j){
					for(int u=0;u<4;++u)
						if(i+dx[u]>=0 && i+dx[u]<r &&
							j+dy[u]>=0 && j+dy[u]<c &&
							grid[i+dx[u]][j+dy[u]] == (grid[i][j]+1) % n)
							gridNew[i+dx[u]][j+dy[u]] = grid[i][j];
				}
		}
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)	printf("%d%c",gridNew[i][j],j==c-1?'\n':' ');
		
	}
	return 0;
}
