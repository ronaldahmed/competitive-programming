#include<iostream>

using namespace std;

int main(){
	int cas,n,a,b,c;
	int s;
	cin>>cas;
	while(cas--){
		s=0;
		cin>>n;
		while(n--){
			cin>>a>>b>>c;
			s+=a*c;
		}
		cout<<s<<endl;
	}
	return 0;
	
}
