#include <iostream>

using namespace std;

int main(){
	int t, x,n,unos;
	cin>>t;
	while(t--){
		cin>>n;
		x=0;
		unos=0;
		for(int i=0,temp;i<n;++i){
			cin>>temp;
			unos += (temp==1);
			x^=temp;
		}
		if(unos==n){
			if(unos&1)	cout<<"Brother"<<endl;
			else			cout<<"John"<<endl;
		}else{
			if(x==0)	cout<<"Brother"<<endl;
			else			cout<<"John"<<endl;
		}
	}
	
	return 0;
}
