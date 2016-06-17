#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define maxn	10100

using namespace std;
vector<int> S;
int memo[maxn];

int grunt(int a){
	if(memo[a]!=-1)	return memo[a];

	bool gSon[500];
	memset(gSon,0,sizeof gSon);

	bool in=0;
	for(int i=0;i<S.size();++i){
		if(a-S[i]>=0){
			gSon[grunt(a-S[i])]=true;
			in=1;
		}
	}
	if(!in)		return memo[a]=0;
	int k=0;
	while(gSon[k])	k++;
	
//	cout<<a<<" "<<k<<endl;
	return memo[a] = k;
}


int main(){
	int k,m,l;
	while(cin>>k,k){
		S.clear();
		for(int i=0,temp;i<k;++i){
			cin>>temp;
			S.push_back(temp);
		}
		
		memset(memo,-1,sizeof memo);
		memo[0]=0;

//		cout<<"------------"<<endl;
		
		cin>>m;
		for(int i=0;i<m;++i){
			cin>>l;
			int xtotal = 0, heap;
			for(int j=0;j<l;++j){
				cin>>heap;
				int tm= grunt(heap);
				
//				cout<<heap<<"  "<<tm<<endl;
				
				xtotal ^= tm;
			}
			if(xtotal==0)	printf("L");
			else				printf("W");		
//			cout<<endl;
		}
		printf("\n");
	}
	return 0;
}
