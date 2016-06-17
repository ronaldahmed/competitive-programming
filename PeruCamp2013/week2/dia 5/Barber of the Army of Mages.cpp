#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

struct flow_graph{
	int MAX_V,E,s,t,head,tail;
	int *cap,*to,*next,*last,*dist,*q,*now;
	
	flow_graph(){}
	
	flow_graph(int V, int MAX_E){
		MAX_V = V; E = 0;
		cap = new int[2 * MAX_E], to = new int[2 * MAX_E], next = new int[2 * MAX_E];
		last = new int[MAX_V], q = new int[MAX_V];
		dist = new int[MAX_V], now = new int[MAX_V];
		fill(last,last + MAX_V,- 1);
	}
	
	void clear(){
		fill(last,last + MAX_V,- 1);
		E = 0;
	}
	
	void add_edge(int u, int v, int uv, int vu = 0){
		to[E] = v,cap[E] = uv,next[E] = last[u]; last[u] = E++;
		to[E] = u,cap[E] = vu,next[E] = last[v]; last[v] = E++;
	}
	
	bool bfs(){
		fill(dist,dist + MAX_V,-1);
		head = tail = 0;
		
		q[tail] = t; ++tail;
		dist[t] = 0;
		
		while(head < tail){
			int v = q[head]; ++head;
			
			for(int e = last[v];e != -1;e = next[e]){
				if(cap[e ^ 1] > 0 && dist[to[e]] == -1){
					q[tail] = to[e]; ++tail;
					dist[to[e]] = dist[v] + 1;
				}
			}
		}
		
		return dist[s] != -1;
	}
	
	int dfs(int v, int f){
		if(v == t) return f;
		
		for(int &e = now[v];e != -1;e = next[e]){
			if(cap[e] > 0 && dist[to[e]] == dist[v] - 1){
				int ret = dfs(to[e],min(f,cap[e]));
				
				if(ret > 0){
					cap[e] -= ret;
					cap[e ^ 1] += ret;
					return ret;
				}
			}
		}
		
		return 0;
	}
	
	int max_flow(int source, int sink){
		s = source; t = sink;
		int f = 0;
		int x;
		
		while(bfs()){
			for(int i = 0;i < MAX_V;++i) now[i] = last[i];
			
			while(true){
				x = dfs(s,INT_MAX);
				if(x == 0) break;
				f += x;
			}
		}
		
		return f;
	}
}G;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	G = flow_graph(1 + n + 2000 + 1,n + n * 1000 + 2000);
	
	for(int i = 0,t,s;i < n;++i){
		scanf("%d %d",&t,&s);
		
		G.add_edge(0,1 + i,2);
		
		for(int j = 0;j < s;++j)
			G.add_edge(1 + i,1 + n + t + j,1);
	}
	
	for(int i = 0;i <= 2000;++i)
		G.add_edge(1 + n + i, 1 + n + 2000,k);
	
	int f = G.max_flow(0, 1 + n + 2000);
	
	if(f < 2 * n) puts("No");
	else{
		puts("Yes");
		
		int choose[100][2],sz[100];
		memset(sz,0,sizeof(sz));
		
		for(int i = 0;i < G.E;i += 2){
			int u = G.to[i ^ 1],v = G.to[i];
			
			if(u >= 1 && u <= n && G.cap[i] == 0){
				--u;
				choose[u][sz[u]++] = v - 1 - n;
			}
		}
		
		for(int i = 0;i < n;++i)
			printf("%d %d\n",choose[i][0],choose[i][1]);
	}
	
	return 0;
}
