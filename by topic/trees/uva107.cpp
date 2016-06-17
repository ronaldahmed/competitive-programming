#include<iostream>
#include<cmath>
#define ld	long double

using namespace std;
ld fun(ld n,ld c){
	return (ld)((ld)log(n+1)-(ld)(c*log(n)));
}
ld defun(ld n,ld c){
	return (ld)((ld)1.0/(n+1)-(ld)c/n);
}

int main(){
	int ht,en;
	ld n,ex;
	long long nn;

	while(cin>>ht>>en, ht!=0 && en!=0){
	if(ht==1 && en==1){
		cout<<0<<" "<<1<<endl;
	}else{
		long long sum,stc=0;
		long long hh=ht;
		long long ch=1;

		if(en==1){
			nn=1;
			ex=round(log10(ht)/log10(2.0));
			sum=ex;
			stc=pow(2,ex+1)-1;
		}else{
			n=(ld)1000.0,ex=(ld)0.0;
			ld err=1e-6;
			ld ni;
			ld cte=(ld)( ((ld)log10(ht)) / ((ld)log10(en)) );
//	cout<<"k: "<<cte<<endl;

			while(1){
				ni=n;
//	cout<<"n antes: "<<n<<endl;
				n=ni-fun(ni,cte)/defun(ni,cte);

//	cout<<"n after: "<<n<<endl;
				if(abs(n-ni)<=err)	break;
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
