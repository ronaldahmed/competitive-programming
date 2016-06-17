#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100000
#define INF (1 << 28)

int a[maxn],T[4 * maxn],lazy[4 * maxn];

void init(int node, int l, int r){
    if(l == r){
        T[node] = a[l];
    }else{
        int mi = (l + r) >> 1;
        
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
        
        a[node] = max(a[2 * node + 1],a[2 * node + 2]);
    }
}

void push(int node, int l, int r){
    T[node] += lazy[node];
    
    if(r != l){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
    
    lazy[node] = 0;
}

void pull(int node){
    T[node] = max(T[2 * node + 1],T[2 * node + 2]);
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return -INF;
    
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    int ret1 = query(2 * node + 1,l,mi,x,y);
    int ret2 = query(2 * node + 2,mi + 1,r,x,y);
    
    pull(node);
    
    return max(ret1,ret2);
}

void update(int node, int l, int r, int x, int val){
    push(node,l,r);
    if(r < x || l > x) return;
    
    if(l == r) T[node] = val;
    else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,val);
        update(2 * node + 2,mi + 1,r,x,val);
        
        pull(node);
    }
}

void update2(int node, int l, int r, int x, int y, int val){
    push(node,l,r);
    
    if(r < x || l > y) return;
    
    if(x <= l && r <= y){
        lazy[node] += val;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        
        update2(2 * node + 1,l,mi,x,y,val);
        update2(2 * node + 2,mi + 1,r,x,y,val);
        
        pull(node);
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    init(0,0,n - 1);
    
    int op,x,y,val;
    
    while(true){
        scanf("%d %d %d",&op,&x,&y);
        
        if(op == 0) printf("%d\n",query(0,0,n - 1,x,y));
        else if(op == 1) update(0,0,n - 1,x,y);
        else if(op == 2){
            scanf("%d",&val);
            update2(0,0,n - 1,x,y,val);
        }
    }
    
    return 0;
}
