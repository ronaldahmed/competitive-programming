#include <cstdio>
#include <iostream>
#include <algorithm>
#define	MAXN	100100

using namespace std;
int a[MAXN];

int main(){
	int t,m;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&m);
		int mx=0,temp,res=0;
		for(int i=0;i<m;++i){
			scanf("%d",&temp);
			res+=temp;
			mx=max(temp,mx);
		}
		cout<<res-mx<<endl;
	}
	return 0;
}
