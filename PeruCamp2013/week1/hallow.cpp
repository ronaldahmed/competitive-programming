#include <iostream>
#include <cstdio>
#include <cstring>
#define	MAXN	100010

using namespace std;
bool cmod[MAXN];
int pos[MAXN],num[MAXN];

int main(){
	int n,c;
	
	while(scanf("%d %d\n",&c,&n),c && n){
		memset(cmod,0,sizeof cmod);

		int u;		
		for(int i=0,temp;i<n;++i){
			scanf("%d",&temp);
			num[i] = temp%c;
		}
		u=num[0];
		cmod[u] = true;
		pos[u]=1;
		int l=-1,r=-1;
		
		for(int i=1,v;i<n;++i){
			v=num[i];
			if( (u+v)%c==0 ){
				l=1; r=i+1;
				break;
			}else{
				if(cmod[(u+v)%c]){
					l=pos[(u+v)%c]+1;
					r=i+1;
					break;
				}else{
					cmod[(u+v)%c] = true;
					pos[(u+v)%c] = i+1;
				}
			}
			u = (u+v)%c;
		}
		if(l!=-1 and r!=-1)
			for(int i=l;i<=r;++i)	printf("%d%c",i,i==r?'\n':' ');
	}
	return 0;
}
