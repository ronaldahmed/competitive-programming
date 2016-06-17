#include <iostream>
#include <cstdio>
#define		MAXN	100
#define		INF		(1<<29)

using namespace std;
int d[MAXN][MAXN], p[MAXN][MAXN];
int g[MAXN][MAXN];
bool yes=0;

void floydWarshall(int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){		
			d[i][j]=g[i][j];
			p[i][j]=i;
		}
	}
	
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k] + d[k][j];
					p[i][j]=k;
				}
			}
		}
	}
}

void path(int i, int j){
	if(i!=j)	path(i,p[i][j]);
	if(yes)	printf(" ");
	printf("%d",j);
	yes=1;
}

int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		for(int j=0,temp;j<n;++j){			
			scanf("%d",&temp);
			g[i][j]= temp==-1?INF:temp;
		}
		scanf("\n");
	}
	
	floydWarshall(n);
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	path(0,3);
	cout<<endl;
	
	return 0;
}
