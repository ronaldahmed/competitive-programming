/*
 * title: Numbering paths
 * topic: Floyd Warshall / mod Transitive Closure + mod Detect Cycles
 * state: AC
 */


#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool g[50][50];
int res[50][50],
    V;

void FW_transC(){
	//	Primer FW para hallar cantidad de caminos
	for(int k=0;k<V;++k)
		for(int i=0;i<V;++i)
			for(int j=0;j<V;++j)			
				res[i][j] += res[i][k] * res[k][j];

	// segundo FW para detectar ciclos negativos
	// si m[i][j] > 0 hay un ciclo que pasa por i

	for(int k=0;k<V;++k)
		if(res[k][k]>0)
			for(int i=0;i<V;++i)
				for(int j=0;j<V;++j)
					if(res[i][k]!=0 && res[k][j]!=0)
						res[i][j] = -1;
}

int main(){
	int n,u,v, cases=0;
	
	while(cin>>n){
		memset(res,0,sizeof res);
		memset(g,0,sizeof g);

		V = 0;
		
		for(int i=0;i<n;++i){
			cin >> u >> v;	
			g[u][v] = true;
			res[u][v] ++;
			V = max(V,max(u,v));
		}
		if(n!=0) V++;
			
		FW_transC();
		cout << "matrix for city " << (cases++) << endl;
		for(int i=0;i<V;++i){
			for(int j=0;j<V;++j)
				printf("%d%c",res[i][j],j==V-1?'\n':' ');
		}
	}
	
	return 0;
}
