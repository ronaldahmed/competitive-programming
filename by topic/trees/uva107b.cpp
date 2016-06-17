#include<iostream>
#include<cmath>
#define ld	long double
#define	INF	(1<<30-1)
#define ll	long long

using namespace std;

ld fun(ld n){
	return log10(n+1)/log10(n);
}

int main(){
	int ht,en;
	ld n=1.0,ex;
	long long nn;

	while(cin>>ht>>en, ht!=0 && en!=0){
	if(ht==1 && en==1){
		cout<<0<<" "<<1<<endl;
	}else{
		ll sum,stc=0;
		ll hh=ht;
		ll ch=1;

		if(en==1){
			nn=1;
			int exp=round(log10(ht)/log10(2.0));
			sum=exp;
			stc=(1<<(exp+1))-1.0;
		}else{
			ld ini=1.0;
			ld fin=(ld)INF;
			ld err=1e-7;
			ld ni;
			ld cte=(ld)( ((ld)log10(ht)) / ((ld)log10(en)) );

			int a=10;
			while(1){
				n=ini/2.0+fin/2.0;
				ld f=fun(n);
//cout<<"ni : "<<n<<" fun:"<<f<<" cte: "<<cte<<endl;
				if(f>cte)		ini=n;
				else			fin=n;
				if(fabs(f - cte) <= err)	break;
			}
		
			nn=round(n);
			ex=round(log10(en)/log10(nn));

			sum=(pow(nn,ex)-1)/(nn-1);
			for(int i=0;i<=ex;i++){
				stc+=ch*hh;
				hh/=(nn+1);
				ch*=nn;
			}
		}
//	cout<<"ex "<<ex<<"  N:"<<nn<<endl;			
			cout<<sum<<" "<<stc<<endl;

	}
	}

	return 0;
}
