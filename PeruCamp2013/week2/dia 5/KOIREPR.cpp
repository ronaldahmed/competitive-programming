#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define MAXSZ 1000

int M[MAXSZ][MAXSZ];
int pos[MAXSZ];

int main(){
    int R,C;
    
    scanf("%d %d",&R,&C);
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j) scanf("%d",&M[i][j]);
        sort(M[i],M[i] + C);
    }
    
    if(R == 1) printf("0\n");
    else{
        int ans = 1000000000;
        set< pair<int, int> > S;
        
        for(int i = 0;i < R;++i){
            S.insert(make_pair(M[i][C - 1],i));
            pos[i] = C - 1;
        }
        
        int cont = R;
        
        while(cont == R){
            set< pair<int, int> >::iterator it = S.end();
            pair<int, int> p = *(--it);
            
            ans = min(ans,p.first - S.begin()->first);
            
            S.erase(it);
            --cont;
            
            int cur = pos[p.second];
            
            if(cur > 0){
                S.insert(make_pair(M[p.second][cur - 1],p.second));
                --pos[p.second];
                ++cont;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
