#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define	MAXN	55

using namespace std;
int fix[MAXN][MAXN], score[MAXN];

int main(){
	int n,m,g;
	while(cin>>n>>m>>g, n && m && g){
		memset(fix,0,sizeof fix);
		memset(score,0,sizeof score);
		
		for(int i=0,u,v;i<g;++i){
			char res;
			scanf("%d %c %d\n",&u,&res,&v);
			fix[u][v]++;
			fix[v][u]++;

//cout<<"u: "<<u<<"- v: "<<v<<" -- fix:"<<fix[u][v]<<endl;
			if(res=='='){
				score[u]++;
				score[v]++;
			}else{
				score[v]+=2;
			}
		}
		int mx=0;

		for(int i=1;i<n;++i)
			for(int j=0;j<i;++j){
				for(int k=fix[i][j];k<m;++k){
				
				if(fix[i][j]<m){
					fix[i][j]++;
					fix[j][i]++;

//cout<<"i: "<<i<<"- j: "<<j<<" -- fix:"<<fix[i][j]<<endl;
					if(j==0)	score[j]+=2;
					else{
						if( abs(score[i]-score[j])>=2 )
							score[i]<score[j]?score[i]+=2:score[j]+=2;
						else
							score[i]++,score[j]++;
					}
				}
				mx = max( mx,max(score[i],score[j]) );
				
				}
			}
		
		if(mx==score[0])	printf("Y\n");
		else					printf("N\n");

//cout<<"----------------"<<endl;

	}
	return 0;
}
