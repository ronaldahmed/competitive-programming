#include <iostream>
#include <string>
#include <map>
#define		MAXN	2000
#define		C		5381LL
#define		K		33LL

using namespace std;
typedef unsigned long long hash;
hash pow[MAXN], H[MAXN],bad[MAXN];
bool found[MAXN];
int acum[MAXN];

hash calcH(int a, int b){	return H[b]-H[a]*pow[b-a]; }

int main(){
	string s,val;
	cin>>s>>val;
	int ls=s.size();
	acum[0]=val[s[0]-'a']=='0'?1:0;
	for(int i=1;i<ls;++i)	if(val[s[i]-'a']=='0')	acum[i]=acum[i-1]+1;
							else					acum[i]=acum[i-1];
	
	return 0;
}
