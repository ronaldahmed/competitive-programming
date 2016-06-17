#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int room[20][50];
int price[20];

int main(){
	int n,b,h,w;
	while(cin>>n>>b>>h>>w){
		for(int i=0;i<h;++i){
			scanf("%d\n",&price[i]);
			for(int j=0;j<w;++j)	scanf("%d",&room[i][j]);
		}
		bool home=0;
		int mn=(1<<30);		
//		cout<<n<<" "<<b<<" "<<h<<" "<<w<<endl;

		for(int i=0,temp;i<w;++i){
			for(int j=0;j<h;++j){
				if(room[j][i]>=n){
					home=1;
					temp = price[j]*n;
					mn = min(temp,mn);
				}
			}
		}
		
//cout<<total<<endl;		
		if(!home or mn>b)		printf("stay home\n");
		else						printf("%d\n",mn);
	
	}
	return 0;
}
