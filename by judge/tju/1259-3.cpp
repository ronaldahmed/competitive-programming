#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#define		N	2147 483 647
#define		N1	800000000

using namespace std;

string tos(int n){
	stringstream a;
	string nn;
	a<<n;
	a>>nn;
	return nn;
}

int main(){
	string cad[2000];
	string s="";

	for(int i=1;i<10;i++){
		for(int j=1;j<=i;j++)	s+= tos(j);
	}
	cad[0]=s;
	s.clear();

	for(int i=10;i<100;i++){
		for(int j=1;j<=i;j++)	s+= tos(j);
	}
	cad[1]=s;
	s.clear();

	int cc=2;
	for(int k=100;k<1000;k+=100){
		for(int i=k;i<k+100;i++){
			for(int j=1;j<=i;j++)	s+= tos(j);
		}
		cad[cc]=s;	cc++;
		s.clear();
	}	

	for(int k=1000;k<5000;k+=100){
		for(int i=k;i<k+100;i++){
			for(int j=1;j<=i;j++)	s+= tos(j);
		}
		cad[cc]=s;	cc++;
		s.clear();
	}	
	
cout<<"ultimos "<<cc<<" y "<<cad[cc].size()<<endl<<cad[cc-1].size()<<endl;
	return 0;
}
