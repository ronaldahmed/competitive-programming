#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define		MAXN	200
#define		REP(i,x,y)	for(int i=x;i<y;++i)

using namespace std;
double mem[MAXN][MAXN];

int main(){
	int n,m,t; cin>>t;
	while(t--){
		REP(i,0,MAXN)	REP(j,0,MAXN)	mem[i][j]=0.0;
		cin>>n>>m;
		REP(i,1,7)
			mem[1][i]=1.0/6.0;

		REP(i,2,n+1)
			REP(j,1,m+1){
				REP(r,1,7)
					mem[i][j]+= 1.0/6.0 * mem[i-1][j-r];
			}

//REP(i,0,n+1){    REP(j,0,m+1)   printf("%.2f ",mem[i][j]); cout<<endl; }
//cout<<"------------------"<<endl;
		printf("%.2f\n",mem[n][m]);
//cout<<"+++++++++++"<<endl;
	}
	return 0;
}
