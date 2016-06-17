#include <iostream>
#include <string>
#define		MAXN	1000100
#define		K		33LL
#define		C		5381LL

using namespace std;
typedef	unsigned long long hash;
hash pow[MAXN], H[MAXN];
int ls;

hash calcH(int a, int b){
	return H[b]-H[a]*pow[b-a];
}

hash  expo(hash s, int m, hash ks){
	hash res=0;
	while(m>0){
		if(m&1)	res=res*ks+s;
		m>>=1;
		s= s*ks + s;
		ks*=ks;
	}
	return res;
}

bool isPower(int i){
	if(ls%i==0 and expo(H[i],ls/i,pow[i])==H[ls] )
		return 1;
	return 0;
}

int main(){
	string s;
	pow[0]=1;
	for(int i=1;i<MAXN;++i)	pow[i]=pow[i-1]*K;

	while(cin>>s,s!="."){
		ls=s.size();		
		for(int i=0;i<ls+1;++i)		H[i]=0LL;
		H[0]=0LL;
		for(int i=1;i<ls+1;++i)		H[i]=H[i-1]*K + s[i-1]-' ';
		hash ans=1LL;
//		cout<<"hash: "<<H[ls]<<" -- "<<calcH(0,1)<<" "<<expo(calcH(0,1),ls,pow[1])<<" - "<<expo(H[1],2,pow[1])<<" "<<H[2]<<endl;

		for(int i=1;i<=ls;++i)
			if( isPower(i) ){	ans=ls/i; break;}
		cout<<ans<<endl;
	}

}
