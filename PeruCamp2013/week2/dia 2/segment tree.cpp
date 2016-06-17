#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100000
#define INF (1 << 28)

int a[maxn],T[4 * maxn];

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

int query(int node, int l, int r, int x, int y){
    if(r < x || l > y) return -INF;
    
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    return max(query(2 * node + 1,l,mi,x,y), query(2 * node + 2,mi + 1,r,x,y));
    
}

void update(int node, int l, int r, int x, int val){
    if(r < x || l > x) return;
    
    if(l == r) T[node] = val;
    else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,val);
        update(2 * node + 2,mi + 1,r,x,val);
        
        T[node] = max(T[2 * node + 1],T[2 * node + 2]);
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    init(0,0,n - 1);
    
    int op,x,y;
    
    while(true){
        scanf("%d %d %d",&op,&x,&y);
        
        if(op == 0) printf("%d\n",query(0,0,n - 1,x,y));
        else update(0,0,n - 1,x,y);
    }
    
    return 0;
}
