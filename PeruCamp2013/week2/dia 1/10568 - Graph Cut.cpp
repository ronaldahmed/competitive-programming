#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int T,N,E,K;
    vector<int> L[500];
    vector<bool> cut[500];
    int color[500];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&E,&K);
        
        for(int i =0 ;i < N;++i){
            L[i].clear();
            cut[i].clear();
        }
        
        for(int i = 0,u,v;i < E;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            
            L[u].push_back(v);
            cut[u].push_back(i < K? true: false);
            
            L[v].push_back(u);
            cut[v].push_back(i < K? true: false);
        }
        
        memset(color,-1,sizeof color);
        queue<int> Q;
        
        bool valid = true;
        
        for(int i =0;i < N;++i){
            if(color[i] == -1){
                color[i] = 0;
                Q.push(i);
                
                while(!Q.empty()){
                    int cur = Q.front();
                    Q.pop();
                    
                    for(int i = L[cur].size() - 1;i >= 0;--i){
                        int to = L[cur][i];
                        
                        if(color[to] != -1){
                            if(color[cur] == color[to] && cut[cur][i]) valid = false;
                            if(color[cur] != color[to] && !cut[cur][i]) valid = false;
                        }else{
                            int c = (cut[cur][i]? 1 - color[cur] : color[cur]);
                            Q.push(to);
                            color[to] = c;
                        }
                    }
                }
            }
        }
        
        puts(valid? "YES" : "NO");
    }
    
    return 0;
}


