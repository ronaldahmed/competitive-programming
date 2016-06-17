#include <iostream>
#include <cstring>
#include <string>
#define		MAXN	550000
#define		C		5381LL
#define		K		33LL

using namespace std;

typedef unsigned long long hash;
hash H[MAXN], pow[MAXN];

hash calcH(int a, int b){
	return H[b]-H[a]*pow[b-a];
}

int main(){
	string s,p;
	while(cin>>p && cin>>s){
//		getline(cin,p);
//		getline(cin,s);
		pow[0]=1LL;

		int lp=p.size();
		int ls=s.size();

	//cout<<s<<" "<<p<<": "<<lp<<" "<<ls<<endl;

		for(int i=1;i<ls+1;++i)	pow[i]=pow[i-1]*K;
		hash hashP=0;
		H[0]=C*pow[ls-1];

		for(int i=0;i<lp;++i)	hashP=hashP*K + p[i]-'a';

		for(int i=1;i<ls;++i)	H[i]=H[i-1]*K + s[i-1]-'a';
	//cout<<"sad "<<calcH(3,7)<<endl;
	//cout<<"hash: "<<H[4]<<" "<<calcH(0,4)<<endl;
	//cout<<"P: "<<hashP<<endl;

		int c=0;
		hash res=0LL;
		for(int i=0;i<ls;++i){
			H[c+1]=H[c]*K + s[i]-'a';
			++c;
	//cout<<"c: "<<c<<" "<<c-lp+1<<"  ---"<<calcH(c-lp+1,c+1)<<endl;
			if(c-lp>=0 and calcH(c-lp,c)==hashP){
				++res;
				c-=(lp);
	//cout<<"enter"<<endl;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
