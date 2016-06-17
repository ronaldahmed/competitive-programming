#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

#define MAXV (2 + 400 + 100)
#define MAXE (400 + 400 * 100 + 100)

int ne,last[MAXV],to[2 * MAXE],nxt[2 * MAXE],cap[2 * MAXE];

void add_edge(int u, int v, int c){
    to[ne] = v; cap[ne] = c; nxt[ne] = last[u]; last[u] = ne++;
    to[ne] = u; cap[ne] = 0; nxt[ne] = last[v]; last[v] = ne++;
}

bool visited[MAXV];

int dfs(int cur, int t, int f){
    if(cur == t) return f;
    if(visited[cur]) return 0;
    visited[cur] = true;
    
    for(int e = last[cur];e != -1;e = nxt[e]){
        if(cap[e] > 0){
            int f2 = dfs(to[e],t,min(f,cap[e]));
            
            if(f2){
                cap[e] -= f2;
                cap[e ^ 1] += f2;
                return f2;
            }
        }
    }
    
    return 0;
}

int max_flow(int s, int t){
    int ret = 0;
    
    while(true){
        memset(visited,false,sizeof visited);
        int f = dfs(s,t,INT_MAX);
        
        if(f == 0) break;
        else ret += f;
    }
    
    return ret;
}

int main(){
    int T,W,P;
    int x[100],y[100],f[100],r[100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&W,&P);
        
        ne = 0;
        memset(last,-1,sizeof last);
        
        for(int i = 0;i < W;++i)
            scanf("%d %d %d %d",&x[i],&y[i],&f[i],&r[i]);
        
        int totalf = 0;
        
        for(int i = 0,x2,y2,f2;i < P;++i){
            scanf("%d %d %d",&x2,&y2,&f2);
            vector<int> adj;
            
            bool ok = false;
            
            for(int j = 0;j < W;++j){
                if((x2 - x[j]) * (x2 - x[j]) + (y2 - y[j]) * (y2 -y[j]) <= r[j] * r[j]){
                    adj.push_back(j);
                    ok = true;
                }
            }
            
            if(ok){
                if(adj[0] == 0){
                    f[0] += f2;
                }else{
                    totalf += f2;
                    add_edge(0,1 + i,f2);
                    
                    for(int j = adj.size() - 1;j >= 0;--j)
                        add_edge(1 + i,1 + P + adj[j],INT_MAX);
                }
            }
        }
        
        bool ok = true;
        
        for(int i = 1;i < W;++i)
            if(f[i] > f[0]) ok = false;
        
        for(int i = 1;i < W;++i)
            add_edge(1 + P + i,1 + P + W,f[0] - f[i]);
        
        int ret = max_flow(0,1 + P + W);
        
        if(ok && ret == totalf) puts("Suiting Success");
        else puts("Lonesome Willy");
    }    
    
    return 0;
}
