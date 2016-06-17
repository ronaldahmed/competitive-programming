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
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()
using namespace std;
vector<double> toVec(string S);
vector<double> inversiones;
double eval(double);
int tam;
			double investIni;
int main(){
	int casos;
	cin>>casos;
		while(casos--){

			string linea;
			cin>>investIni;
			getline(cin,linea);
			inversiones.clear();
			inversiones=toVec(linea);
			tam=inversiones.size();
			bool signoP=false;
			if(eval(2.0)>0.0) signoP=true;
			
			double beg=0.0;
			double fin=2.0;
			double med;
			
			while(fin-beg>1e-8){
				med=(beg+fin)/2.0;
				bool sig=false;
				if(eval(med)>0.0) sig=true;
				
				if(sig==signoP)
				  fin=med;
				else
				  beg=med;
			}
			printf("%.3lf%c\n",double((beg-1.0)*100.0),'%');
			
		}
	return 0;
}
vector<double> toVec(string S){
	
	vector<double> ans;
	istringstream s;
	s.str(S);
	string s1;
	double temp;
	while(s>>s1){
		stringstream ss;
		ss<<s1;
		ss>>temp;
		ans.push_back(temp);
	}
	return ans;
}
double eval(double rate){
	double ans=0;
		for(int i=0;i<tam;i++){
			ans+=(inversiones[i])/pow(rate,i+1.0);	
		}
		return ans-investIni;
}


