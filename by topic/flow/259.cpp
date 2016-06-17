#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
const int N = 500;
int Gf[N][N];
char idx[N];
char node2App[30];
int prev[N];
bool used[N];

int n_apps = 30,pos=0;
int S,T;


void showG(){
	cout << "**********" << endl;
	for(int i=0;i<pos+2;++i){
		cout << i << " : ";
		for(int j=0;j<N;++j){
			if(Gf[i][j] != -1)
				printf("%d/%d ",j,Gf[i][j]);
		}
		cout << endl;
	}
	
	for(int i=n_apps;i<n_apps+10;++i){
		cout << i << " : ";
		for(int j=0;j<N;++j){
			if(Gf[i][j] != -1)
				printf("%d/%d ",j,Gf[i][j]);
		}
		cout << endl;
	}
	cout << "**********" << endl;
}



int dfs(int p, int node){
	//cout << p << " -> " << node << endl;
	
	if(p != -1 && node == T){
		//cout << "------------" << endl;
		return 1 - Gf[p][node];
	}
	
	used[node] = true;
	
	for(int i=0;i<N;++i){
		if( i != node && !used[i] && Gf[node][i] != -1 & Gf[node][i] != 1){
			int rr = dfs(node,i);
			if(rr != 0){
				prev[i] = node;
				return min(rr,1-Gf[node][i]);
			}
		}
	}
	return 0;
}


bool fordfullk(){
	S = pos ;
	T = pos +1;
	for(int i=0;i<pos;++i)
		Gf[S][i] = 0, Gf[i][S] = 1;

	for(int i=n_apps;i<n_apps+10;++i)
		Gf[i][T] = 0, Gf[T][i] = 1;
	
	memset(used,0,sizeof used);
	memset(prev,-1,sizeof prev);
	
	int aug_path = dfs(-1,S);

	while(aug_path != 0){
		//printf("aumentando : %d ---\n",aug_path);
		
		int u = T;
		while( prev[u] != -1){
			//printf("  path: %d - %d\n",prev[u],u);
			
			Gf[prev[u]][u] += aug_path;
			Gf[u][prev[u]] -= aug_path;
			u = prev[u];
		}
		memset(prev,-1,sizeof prev);
		memset(used,0,sizeof used);
		aug_path = dfs(-1,S);
	}
	
	for(int i=0;i<pos;++i){
		bool connected = false;
		for(int j=n_apps;j< n_apps + 10;++j){
			if(Gf[i][j] == 1){
				idx[j-n_apps] = node2App[i];
				connected = true;
				break;
			}
		}
		if(!connected)
			return false;
	}
	return true;
}



int main(){
	string line;
	memset(Gf,-1,sizeof Gf);
	memset(idx,0,sizeof idx);
	
	while(getline(cin,line)){
		if(line.size() == 0){
			bool res = fordfullk();
			
			if(res){
				for(int i=0;i<10;++i)
					printf("%c",idx[i]==0?'_':idx[i]);
				cout << endl;
			}else
				cout << "!" << endl;

			memset(Gf,-1,sizeof Gf);
			memset(idx,0,sizeof idx);
			memset(node2App,0,sizeof node2App);
			pos = 0;									// offset de app_number
			continue;
		}

		for(int i=3;i<line.size()-1;++i){
			int comp = line[i] - '0' + n_apps;
			for(int j=pos;j<pos + line[1]-'0';++j){
				node2App[j] = line[0];
				Gf[j][comp] = 0;
				Gf[comp][j] = 1;
			}
		}
		pos += line[1]-'0';
	}
	
	bool res = fordfullk();
	
	if(res){
		for(int i=0;i<10;++i)
			printf("%c",idx[i]==0?'_':idx[i]);
		cout << endl;
	}else
		cout << "!" << endl;
	
	return 0;
}
