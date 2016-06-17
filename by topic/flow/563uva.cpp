#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define	REP(i,x,y)	for(int (i)=(x);(i)<(y);++i)
#define	mp	make_pair
#define	fst	first
#define	snd	second

using namespace std;

typedef pair<int,int> pii;
const int maxn = 10000;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int s,a,B, S,T;
vector<pair<int,int> > G[maxn];

int p[maxn];
bool used[maxn];

void showG(vector<pii>* g){
	printf("source : %d\nsink: %d\n",S,T);
	REP(i,0,2*s*a+2){
		cout << i << ": ";
		REP(j,0,g[i].size()){
			printf("%d(%d) ",g[i][j].first, g[i][j].second);
		}
		cout << endl;
	}
	cout << "---------" << endl;
}

int bfs(){
	queue<int> Q;
	Q.push(S);
	int d[maxn];
	
	for(int i=0;i<maxn;++i)	d[i] = (1<<30);
	memset(p,-1,sizeof p);
	memset(used,0,sizeof used);
	
	d[S] = 0;
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		used[u] = true;
		if(u == T)
			break;
			
		for(int i=0;i<G[u].size();++i){
			int v = G[u][i].fst;
			int w = G[u][i].snd;
			if(!used[v] && d[v] > d[u] + 1 && w < 1){
				d[v] = d[u] + 1;
				p[v] = u;
				Q.push(v);
			}
		}
	}
	
	// siempre aumenta de 1 en uno :S, capacidad maxima es de 1 LOL
	if(used[T])
		return 1;
	else
		return 0;
	
}

bool ek(){

	
	int aug_path = bfs();
	while(aug_path != 0){
		//printf("path : %d\n",aug_path);
		
		int u = T;
		while(p[u] != -1){
			//printf("p[u]:%d -> u: %d\n",p[u],u);
			
			int i = 0;
			while(i<G[p[u]].size() && G[p[u]][i].fst != u) ++i;
			G[p[u]][i].snd += aug_path;
			int j = 0;
			while(j<G[u].size() && G[u][j].fst != p[u]) ++j;
			G[u][j].snd -= aug_path;

			u = p[u];
		}
		
		aug_path = bfs();
	}
	for(int i=0;i<G[S].size();++i){
		if(G[S][i].second == 0)
			return false;
	}
	return true;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s >> a >> B;
		REP(i,0,2*s*a+4)	G[i].clear();
		
		S = 2*(s*a);
		T = 2*(s*a)+1;
		REP(i,0,s)
			REP(j,0,a){
				G[2*(i*a+j)+1].push_back(mp(2*(i*a+j),0));
				G[2*(i*a+j)].push_back(mp(2*(i*a+j)+1,1));
				REP(k,0,4){
					int x = i + dx[k];
					int y = j + dy[k];
					if(x>=0 && x<s && y>=0 && y<a){
						G[2*(i*a+j)].push_back(mp(2*(x*a+y)+1,0));
						G[2*(x*a+y)+1].push_back(mp(2*(i*a+j),1));
					}
				}
			}
		// SINK (T) CONECTIONS
		// | -- |
		REP(i,0,s){
			G[2*i*a].push_back(mp(T,0));
			G[T].push_back(mp(2*i*a,1));
			
			G[2*(i*a + a-1)].push_back(mp(T,0));
			G[T].push_back(mp(2*(i*a + a-1),1));
		}
		// .-----.
		// .......
		REP(i,1,a-1){
			G[2*i].push_back(mp(T,0));
			G[T].push_back(mp(2*i,1));
			
			G[2*((s-1)*a + i)].push_back(mp(T,0));
			G[T].push_back(mp(2*((s-1)*a + i),1));
		}
		
		// SOURCE CONECTIONS
		for(int i=0,u,v;i<B;++i){
			cin >> u >> v;
			u--;v--;
			
			G[S].push_back(mp(2*(u*a+v)+1,0));
			G[2*(u*a+v)+1].push_back(mp(S,1));
		}

		//showG(G);		
		
		bool res = ek();
		if(res)
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;

	}
	return 0;
}
