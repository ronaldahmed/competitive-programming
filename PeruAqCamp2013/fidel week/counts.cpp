#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define	MAXN	1001000

using namespace std;

long long sum[MAXN];
map<long long, int>	m;

int main(){
	int t,n,temp;
	cin>>t;
	while(t--){
		memset(sum,0,sizeof sum);
		m.clear();
		
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>temp;
			if(i!=0)	sum[i]=sum[i-1] + temp;
			else		sum[i]=temp;
		}
		m[0]=1;
		long long ans=0LL;
			
		for(int i=0;i<n;++i){
			ans+=m[sum[i]-47];
			++m[sum[i]];
		}	
		
		printf("%lld\n",ans);
	}

	return 0;
}
