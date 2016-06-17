#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()
using namespace std;
int main(){
	int N;
	string s1;
	map<int,char> mapa;
	mapa[1]='I';
	mapa[2]='Z';
	mapa[3]='E';
	mapa[4]='A';
	mapa[5]='S';
	mapa[6]='G';
	mapa[7]='T';
	mapa[8]='B';
	mapa[9]='P';
	mapa[0]='O';
	scanf("%d\n",&N);
	while(N--){
		
		while(getline(cin,s1)){
		
			if((int)SZ(s1)>0){
					for(int i=0;i<SZ(s1);i++){
						if(isdigit(s1[i])) cout<<mapa[s1[i]-'0'];
						else cout<<s1[i];
					}
					cout<<endl;
			}
			else break;
		}
		if(N!=0)cout<<endl;
	}
	
	return 0;
}


