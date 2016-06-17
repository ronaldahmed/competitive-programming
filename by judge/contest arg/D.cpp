#include<iostream>

using namespace std;

int main(){
	long long n,m;
	long long t;

	while(cin>>n>>m,n!=-1 || m!=-1){
		t=0;

		int caps[n];
		for(int i=0;i<n;i++)	cin>>caps[i];
		
//		for(int i=0;i<n;i++)	cout<<caps[i]<<" ";
		
		for(int i=0;i<n;i++){
			t+=caps[i]*(n-i);
		}
		t*=m;
		cout<<t<<endl;
	}
	return 0;
}
