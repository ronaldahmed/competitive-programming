#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<set>
#include<stack>
#include<numeric>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()
using namespace std;
string tos(double a);
int main(){
	int N,j=0;
	cin>>N;
	double a,b,apuesta,c;
	vector<double> vec;
	while(N--){
		cin>>a>>b;
		apuesta=a;
		for(int i=0;i<b;i++){
			cin>>c;
			if(c<0.0) {
				char temp[50];
				double multiplier=100.0/fabs(c);
				
				int tamp=sprintf(temp,"%.3lf",multiplier);
				
				string sss="";
				for(int i=0;i<tamp;i++)
				sss=sss+temp[i];
				stringstream ss;
				ss<<sss;
				//cout<<"Multipliere1: "<<multiplier<<endl;
				ss>>multiplier;
				//cout<<"Multipliere2: "<<multiplier<<endl;				
				vec.PB(ceil(apuesta*multiplier));	
				apuesta+=(ceil(apuesta*multiplier));
			}
			else{
				char temp[50];
				double multiplier=c/100.0;
				
				int tamp=sprintf(temp,"%.3lf",multiplier);
				
				string sss="";
				for(int i=0;i<tamp;i++)
				sss=sss+temp[i];
				stringstream ss;
				ss<<sss;
				//cout<<"Multipliere1: "<<multiplier<<endl;
				ss>>multiplier;
				//cout<<"Multipliere2: "<<multiplier<<endl;				
				vec.PB(ceil(apuesta*multiplier));	
				apuesta+=(ceil(apuesta*multiplier));
			}
		}
		if(apuesta>=1000000.0) apuesta=1000000.0;
		cout<<++j<<" $"<<tos(apuesta)<<endl;
		vec.clear();
	}

	return 0;
}
string tos(double a){
		char ans[1000];
		int pq;
		pq=sprintf(ans,"%.2lf",a);
		
		
		stack<char> pilaResp;
		pq--;
		for(int nt=0;nt<3;nt++){
		pilaResp.push(ans[pq]); 
		pq--;
		}
		
		for(int k=0;pq>=0;pq--,k++){
			if(k%3==0&&k!=0) 
			pilaResp.push(',');
			pilaResp.push(ans[pq]);
		}
		string ANS="";
		while(!pilaResp.empty())
		{
			ANS=ANS+pilaResp.top();
			pilaResp.pop();
		}
		return ANS;
}
