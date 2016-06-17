#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXV1 200
#define MAXV2 100

int V1,V2;
int l[MAXV2],r[MAXV1];
bool visited[MAXV1];
vector<int> L[MAXV1];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(l[to] == -1 || dfs(l[to])){
            l[to] = cur;
            r[cur] = to;
            return true;
        }
    }
    
    return false;
}

int main(){
    int T,N,M,K,C;
    int t[100][100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&N,&M,&K,&C);
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < M;++j)
                scanf("%d",&t[i][j]);
        
        V1 = 2 * M; V2 = N;
        
        int lo = 0,hi = 20000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            for(int i = 0;i < V1;++i)
                L[i].clear();
            
            for(int i = 0;i < N;++i)
                for(int j = 0;j < M;++j)
                    if(t[i][j] <= mi){
                        L[2 * j].push_back(i);
                        
                        if(t[i][j] <= mi - C)
                            L[2 * j + 1].push_back(i);
                    }
            
            memset(l,-1,sizeof l);
            memset(r,-1,sizeof r);
            bool change = true;
            
            while(change){
                memset(visited,false,sizeof visited);
                change = false;
                
                for(int i = 0;i < V1;++i)
                    if(r[i] == -1)
                        change |= dfs(i);
            }
            
            int match = 0;
            
            for(int i = 0;i < V1;++i)
                if(r[i] != -1) ++match;
            
            if(match < K) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
