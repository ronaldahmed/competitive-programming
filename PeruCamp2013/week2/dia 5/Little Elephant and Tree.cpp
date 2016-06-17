#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define MAXN 100005
#define INF 100000000

int n,m;
int pos[MAXN],end[MAXN],sz = 0;
vector<int> L[MAXN];

void dfs(int cur, int p){
    pos[cur] = end[cur] = sz;
    ++sz;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != p){
            dfs(to,cur);
            end[cur] = end[to];
        }
    }
}

pair<int, int> T[4 * MAXN];
int lazy[4 * MAXN];

void init(int node, int l, int r){
    T[node] = make_pair(0,r - l + 1);
    
    if(l != r){
        int mi = (l + r) >> 1;
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
    }
}

void push(int node, int l, int r){
    if(lazy[node]){
        T[node].first += lazy[node];
        
        if(l != r){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        
        lazy[node] = 0;
    }
}

pair<int, int> mix(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first)
        return make_pair(a.first,a.second + b.second);
    else
        return min(a,b);
}

void update(int node, int l, int r, int x, int y, int val){
    push(node,l,r);
    if(r < x || l > y) return;
    
    if(x <= l && r <= y){
        lazy[node] = val;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        update(2 * node + 1,l,mi,x,y,val);
        update(2 * node + 2,mi + 1,r,x,y,val);
        T[node] = mix(T[2 * node + 1],T[2 * node + 2]);
    }
}

int ans[MAXN];
vector<int> query[MAXN];

void dfs2(int cur, int p, int lsz = 0){
    if(!query[cur].empty()){
        update(0,0,n - 1,pos[cur],end[cur],1);
        ++lsz;
    }
    
    for(int i = query[cur].size() - 1;i >= 0;--i)
        update(0,0,n - 1,pos[ query[cur][i] ],end[ query[cur][i] ],1);
    
    if(lsz == 0) ans[cur] = 0;
    else{
        ans[cur] = n - 1;
        if(T[0].first == 0) ans[cur] -= T[0].second;
    }
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        if(to != p) dfs2(to,cur,lsz);
    }
    if(!query[cur].empty()){
        update(0,0,n - 1,pos[cur],end[cur],-1);
        --lsz;
    }
    
    for(int i = query[cur].size() - 1;i >= 0;--i)
        update(0,0,n - 1,pos[ query[cur][i] ],end[ query[cur][i] ],-1);
}

int main(){
    scanf("%d %d",&n,&m);
    
    for(int i = 1,u,v;i < n;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    dfs(1,0);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        query[u].push_back(v);
        query[v].push_back(u);
    }
    
    init(0,0,n - 1);
    
    dfs2(1,0);
    
    for(int i = 1;i <= n;++i)
        printf("%d ",ans[i]);
    printf("\n");
    
    return 0;
}
