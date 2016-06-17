#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 100005

bool ok[MAXN];
vector<int> L[MAXN];

double dfs(int cur, int p, int cont){
    double ret = 1.0 / (1 + cont);
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != p) ret += dfs(to, cur, cont + (!ok[cur]? 1 : 0));
    }
    
    return ret;
}

int main(){
    int T,N,M;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 1;i <= N;++i)
            L[i].clear();
        
        for(int i = 1,u,v;i < N;++i){
            scanf("%d %d",&u,&v);
            L[u].push_back(v);
            L[v].push_back(u);
        }
        
        scanf("%d",&M);
        memset(ok,true,sizeof ok);
        
        for(int i = 0,x;i < M;++i){
            scanf("%d",&x);
            ok[x] = false;
        }
        
        printf("%.10f\n",N - dfs(1,0,0));
    }
    
    return 0;
}
