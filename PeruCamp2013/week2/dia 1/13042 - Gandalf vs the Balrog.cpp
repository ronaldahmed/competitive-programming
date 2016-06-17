#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000005

int cont[MAXN];

int main(){
    int T,N,M;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 1;i <= N;++i) cont[i] = i - 1;
        
        for(int i = 0,x,y;i < M;++i){
            scanf("%d %d",&x,&y);
            ++cont[x];
            --cont[y];
        }
        
        int ans = 1,choose;
        
        for(int i = N;i >= 1;--i)
            if(cont[i] == N - 1){
                ans = 2;
                choose = i;
                break;
            }
        
        if(ans == 2) printf("%d %d\n",2,choose);
        else puts("1");
    }
    
    return 0;
}

