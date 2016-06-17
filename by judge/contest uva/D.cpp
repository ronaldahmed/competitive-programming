#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<set>
#include<stack>
#include<cstring>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()

using namespace std;

int main(){
	int N,j=0;
	cin>>N;
	double a,suma;
	while(N--){
		suma=0.0;
		for(int i=0;i<12;i++){
			cin>>a;
			suma+=a;
		}
		suma/=12.0;
	
		char ans[1000];
		int pq;
		pq=sprintf(ans,"%.2lf",suma);
		
		printf("%d $",++j);
		stack<char> pilaResp;
		pq--;
		for(int nt=0;nt<3;nt++){
		pilaResp.push(ans[pq]); 
		pq--;
		}
		
		for(int k=0;pq>=0;pq--,k++){
			if(k%3==0&&k!=0) 
			pilaResp.push(',');
			pilaResp.push(ans[pq]);
		}
		while(!pilaResp.empty())
		{
			printf("%c",pilaResp.top());
			pilaResp.pop();
		}
		printf("\n");
	}
	return 0;
}

