#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int memo[8000];
int coins[5]={50,25,10,5,1};

int main(){
	memset(memo,0,sizeof memo);
	memo[0]=1;

	for(int j=0;j<5;++j)
		for(int i=1;i<8000;++i)
			if(i-coins[j]>=0 ){
				memo[i] += memo[i-coins[j]];
			}
	
//	memo[0]=1;
	int c;
	while(cin>>c)
		cout<<memo[c]<<endl;
	return 0;
}
