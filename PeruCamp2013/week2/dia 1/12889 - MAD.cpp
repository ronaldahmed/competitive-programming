#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,a[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        sort(a,a + n);
        
        int ans = n;
        
        for(int i = 0;i < n;){
            int e = i;
            
            while(e < n && a[e] == a[i]) ++e;
            
            ans = min(ans,max(0,n / 2 + 1 - (e - i)));
            
            i = e;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
