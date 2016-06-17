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

int toi(string s){
	stringstream a;
	int nn;
	a<<s;
	a>>nn;
	return nn;
	
}

int max1(int d){
	string s="4";
	for(int i=0;i<d-1;i++)	s+="9";
	s+="5";
	for(int i=0;i<d-1;i++)	s+="0";
	return toi(s);
}

int main(){
	long long lims[10];
	long long lim_pos[2][10];
	lim_pos[0][0]=0;
	lim_pos[1][0]=9;

	long long ad_digs[10];
	ad_digs[0]=0;

	for(int i=1;i<10;i++){
		lim_pos[0][i]=pow(10,i);
		lim_pos[1][i]=pow(10,i+1)-1;
	}

	for(int i=1;i<10;i++){
		ad_digs[i]=ad_digs[i-1]+ (lim_pos[1][i]-lim_pos[0][i]+1)*(lim_pos[1][i]-lim_pos[0][i] +2)*i/2;
	}
	
	int n,pos;
	lims[0]=45;
	for(int i=1;i<10;i++){
		lims[i]=max1(i+1)+ad_digs[i];
cout<<lims[i]<<endl;
	}

	cin>>n;
	while(n--){
		cin>>pos;
		int i=0;
		while(pos>lims[i])	i++;
			
		
	}
	return 0;
}
