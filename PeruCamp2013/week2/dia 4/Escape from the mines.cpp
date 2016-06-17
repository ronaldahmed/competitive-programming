#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100000

int N,M;
int T[12 * MAXN],lazy[12 * MAXN];
bool prop[12 * MAXN];
int x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN];
vector<int> vy;
vector< pair<int, int> > vx;

int get_id(int y){
    int lo = 0,hi = M - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(vy[mi] < y) lo = mi + 1;
        else hi = mi;
    }
    
    return lo;
}

void push(int node, int l, int r){
    if(prop[node]){
        T[node] = lazy[node];
        
        if(l != r){
            lazy[2 * node + 1] = lazy[node];
            prop[2 * node + 1] = true;
            
            lazy[2 * node + 2] = lazy[node];
            prop[2 * node + 2] = true;
        }
        
        prop[node] = false;
        lazy[node] = -1;
    }
}

int query(int node, int l, int r, int x){
    push(node,l,r);
    if(l == r) return T[node];
    
    int mi = (l + r) >> 1;
    
    if(x <= mi) return query(2 * node + 1,l,mi,x);
    return query(2 * node + 2,mi + 1,r,x);
}

void update(int node, int l, int r, int x, int y, int val){
    push(node,l,r);
    
    if(y < l || x > r) return;
    
    if(x <= l && r <= y){
        lazy[node] = val;
        prop[node] = true;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,y,val);
        update(2 * node + 2,mi + 1,r,x,y,val);
    }
}

int p[MAXN];

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
    
    for(int i = 0;i < N;++i){
        vy.push_back(2 * y1[i] - 1);
        vy.push_back(2 * y1[i]);
        vy.push_back(2 * y2[i]);
        
        vx.push_back(make_pair(x1[i],i));
        vx.push_back(make_pair(x2[i],i));
    }
    
    sort(vy.begin(),vy.end());
    M = unique(vy.begin(),vy.end()) - vy.begin();
    
    sort(vx.begin(),vx.end());
    
    memset(T,-1,sizeof T);
    memset(prop,false,sizeof prop);
    
    for(int i = 0;i < 2*N;++i){
        int cur = vx[i].second;
        int s = get_id(2 * y1[cur]),e = get_id(2 * y2[cur]);
        int to = cur;
        
        if(vx[i].first == x2[cur])
            p[cur] = to = query(0,0,M - 1,s - 1);
        
        update(0,0,M - 1,s,e,to);
    }
    
    for(int i = 0;i < N;++i)
        printf("%d\n",p[i]);
    
    return 0;
}
