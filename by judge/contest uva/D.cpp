#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

string num(double nn);
double round(double a);

int main(){
	int n,m=12;
	double s,a;
	int j=1;
	cin>>n;

	while(n--){
		m=12;
		s=0.0;
		while(m--){	cin>>a;	s+=a;	}
		s/=12.0;
//cout<<s<<endl;
		cout<<j++<<" $"<<num(s)<<endl;
	}
	return 0;
}

string num(double nn){
	int num,l;
	stringstream ss;
	string sn,si;

	if(floor(nn)!=ceil(nn))
		nn=(round(nn*100))/100;
	ss<<nn;
	ss>>sn;
	reverse(sn.begin(),sn.end());

	if(floor(nn)==ceil(nn))
		sn.insert(0,"00.");
	l=sn.size();
//cout<<"l: "<<l<<endl;

	if(l>6){
		sn.insert(6,",");
		if(l>10)			sn.insert(10,",");
	}
	
	reverse(sn.begin(),sn.end());
	return sn;
}

double round(double a){
	return floor(a+0.5);
}
