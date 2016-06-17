#include<iostream>
#include<vector>
#include<string>

using namespace std;
int tar(char A, int d){
	if(d<1)			return 0;
	else{
		if(A=='F')		return 2*d;
		else if(A=='B')	return 1.5*d;
		else{
			if(d<500)	return 500;
			else		return d;
		}
	}
}
int main(){
	string a1,a2;
	int d,earn=0;
	char C;
	cin>>a1;
//cout<<a1;
	while(a1!="#"){
		while(a1!="0"){
			cin>>a2>>d>>C;
//cout<<a2<<" "<<earn<<" "<<C<<endl;
			earn+=tar(C,d);
			cin>>a1;
		}
		cout<<earn<<endl;
		earn=0;
		cin>>a1;
	}
	return 0;
}
