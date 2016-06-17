#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#define		maxN	1000
#define		oo		(1<<31-1)

using namespace std;
int pred[maxN];
int T,N;
bool V[maxN];
int	G[maxN][maxN],f[maxN][maxN],Gf[maxN][maxN];
vector<vector<int> >	gfDFS;

void limpiar(){
	for(int i=0;i<N;i++){
		pred[i]=i;
		V[i]=false;
	}
}

bool DFS(int v){
V[v]=true;
	if(v==T)	return true;

	for(int i=0;i<gfDFS[v].size();i++){
		int u=gfDFS[v][i];
		if(V[u]==false){
			pred[u]=v;
			bool flag=DFS(u);
			if(flag)	return true;
		}
	}
	return false;
}


vector<int> makeP(int a){
	vector<int> ans;
	ans.push_back(a);
	while(pred[a]!=a){
		a=pred[a];
		ans.push_back(a);
	}
	reverse(ans.begin(),ans.end());



	cout<<"P: "<<endl;
for(int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";
cout<<endl;
	
	return ans;
}

int bottleneck(vector<int> P){
	int l=P.size();
	int ans=oo;
	
	for(int i=1;i<l;i++){
		ans=min(ans,Gf[P[i-1] ][P[i] ]);
	}
//cout<<"bottle neck: "<<ans<<endl;
	return ans;
}

void augment(vector<int> P){
	int b=bottleneck(P);
	int l=P.size();

	for(int i=1;i<l;i++){
		if(G[P[i-1] ][P[i] ]>0 )
			f[P[i-1] ][P[i] ]+=b;
		else
			f[P[i] ][P[i-1] ]-=b;
	}

}

void mkGf(){
	gfDFS.clear();
	vector<int>	vacio;
	gfDFS.resize(N+1,vacio);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(G[i][j]>0){
				Gf[i][j]=G[i][j]-f[i][j];
				Gf[j][i]=f[i][j];
		
				if(Gf[i][j]>0)	gfDFS[i].push_back(j);
				if(Gf[j][i]>0)	gfDFS[j].push_back(i);
				
			}else{
				if(G[j][i]==0){
					Gf[i][j]=0;
					Gf[j][i]=0;
				}
			}
		}
	}
}
void mostrarG();
void mostrarf();
int main(){
	int flow,t,u;
	cin>>N;
	T=N-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			G[i][j]=0;
			f[i][j]=0;
		}
	}

	for(int i=0;i<N-1;i++){
		cin>>t;
		for(int j=0;j<t;j++){
			cin>>u>>flow;
			G[i][u]=flow;
		}
	}

	while(1){
cout<<"Empieza un nuevo Ciclo"<<endl;
		limpiar();
		mkGf();
cout<<"Gf:"<<endl;
mostrarG();

		bool fl=DFS(0);

	cout<<"Padres: "<<endl;
for(int i=0;i<N;i++)
cout<<pred[i]<<" ";
cout<<endl;


		if(fl==false)	break;

		vector<int> P=makeP(N-1);
		augment(P);
cout<<"f:"<<endl;
mostrarf();
	}

	return 0;
}
void mostrarG(){
	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%5d",Gf[i][j]);
			}
			cout<<endl;
		}
		cout<<"*********************************"<<endl;
}
void mostrarf(){
	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%5d",f[i][j]);
			}
			cout<<endl;
		}
		cout<<"*********************************"<<endl;
}
