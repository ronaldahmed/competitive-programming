#include <iostream>
#include <cstring>
#define		MAXN	100001

using namespace std;
typedef pair<int,int> pii;
int rem[MAXN], mods[MAXN];

pii egcd(int a, int b){
	if(b==0)	return make_pair(1,0);
	else{
		pii res=egcd(b,a%b);
		return make_pair( res.second , res.first - res.second*(a/b) );		
	}
}

int inv(int n, int m){
	pii ext=egcd(n,m);
	return (ext.first % m + m) % m;
}

int crt(int k){
	int mod=1, res=0;
	for(int i=0;i<k;++i)	mod*=mods[i];
	for(int i=0;i<k;++i){
		int temp=mod/mods[i];
		temp *= inv(temp,mods[i]);
		res += ( temp*rem[i] ) % mod;		
	}
	return res % mod;
}

int main(){
	cout<<inv(7,5)<<endl;
	rem[0]=2;
	rem[1]=3;
	rem[2]=2;
	mods[0]=3;
	mods[1]=5;
	mods[2]=7;
	cout<<crt(3)<<endl;
	
	return 0;
}
