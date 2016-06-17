#include <iostream>

using namespace std;
long long T[50];
long long tt(int n){
	if(T[n]!=0)	return T[n];
	else{
		return T[n]=3*tt(n-1) +2;
	}
}
int main(){
	int n,temp; cin>>n;
	T[0]=0;	T[1]=2;
	while(n--){
		cin>>temp;
		cout<<tt(temp)<<endl;
	}
	return 0;
}
