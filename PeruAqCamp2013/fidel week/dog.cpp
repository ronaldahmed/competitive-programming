#include <cstdio>
#include <algorithm>
#define MOD     1000000007

using namespace std;

int a[100];

int main(){
    int t,n;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)    scanf("%d",&a[i]);
        sort(a,a+n);
        long long res=1LL;
        
        for(int i=0;i<n;i++)
            res=(res*(a[i]-i))%MOD;
        printf("%lld\n",res);
    }
    return 0;
}
