#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#define	K	97LL
#define	C	5381LL
#define	maxn	100

using namespace std;
typedef	unsigned long long hash;

map<hash,int> query;
//map<string,int> query;
string obj[10];
hash hashObj[10];
hash pow[maxn];

hash getHash(string s){
	hash H = C;
	for(int i=0;i<s.size();++i)
		H = K*H + s[i]-'+';
	return H;
}

hash concatenar(hash L, hash R, int lR){
	return L*pow[lR] + R;
}

int main(){
//	cout<<getHash("+")<<"  - "<<getHash("0")<<endl;
	pow[0]=1LL;
	for(int i=1;i<maxn;++i)
		pow[i]=K*pow[i-1];
	
	int n,m, k;
	scanf("%d\n",&n);
	while(n--){
		scanf("%d ",&k);
		for(int j=0;j<k;++j){
			cin>>obj[j];
		}
		sort(obj,obj+k);
		for(int i=0;i<k;++i)			hashObj[i] = getHash(obj[i]);
		
		
		int ways = (1<<k);
		for(int r=1;r<ways;++r){
			hash temp=0LL;
			for(int s=0;s<k;++s)
				if(r&(1<<s)){
					temp = concatenar(temp, hashObj[s],obj[s].size());
				}
			query[temp]++;
		}
	}

	scanf("%d\n",&m);
	
	while(m--){
		scanf("%d ",&k);
		for(int j=0;j<k;++j){
			cin>>obj[j];
		}
		sort(obj,obj+k);
		for(int i=0;i<k;++i)			hashObj[i] = getHash(obj[i]);
		hash H=0LL;
		for(int j=0;j<k;++j)		H=concatenar( H,hashObj[j],obj[j].size() );

		printf("%d\n",query[H]);
	}
	
	return 0;
}
