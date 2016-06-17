#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN    50

using namespace std;
vector<vector<int> > g;
char color[MAXN];

bool dfs(int u){
    color[u]='g';
    int lu=g[u].size();
    bool c=0;
    for(int i=0;i<lu;++i)
        if(color[g[u][i]]=='w'){
            c=dfs(g[u][i]);
            if(c)   break;
        }else if(color[g[u][i]]=='g'){
            c=1;
            break;
        }
    color[u]='b';
    return c;
}

int main(){
    int t,n,m; cin>>t;
    vector <int> temp;

    while(t--){
        g.clear();
        g.assign(25,temp);
        cin>>n>>m;
        for(int i=0,u,v;i<m;++i)   cin>>u>>v, g[u-1].push_back(v-1);
        bool cycle=0;
        memset(color,'w',sizeof color);

        for(int i=0;i<n;++i)
            if(color[i]=='w'){
                cycle=dfs(i);
                if(cycle)   break;
            }
        if(cycle)   printf("0\n");
        else        printf("1\n");
    }

    
    return 0;
}
