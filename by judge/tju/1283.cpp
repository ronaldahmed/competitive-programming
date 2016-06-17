#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

int toi(string s){
//	cout<<"Entra TOI: "<<s<<endl;
	if(s.size()==0)	return 1;
	stringstream ss;
	int n;
	ss<<s;
	ss>>n;
	return n;
}

int main(){
	int n,x1,x2,c1,c2;
	cin>>n;
	string s;
	while(n--){
		x1=0,x2=0,c1=0,c2=0;
		cin>>s;
		int igual=0;

		int ini=1,temp;
		int l=s.size();		
/*
		for(int i=0;i<l;i++){
			if(s[i]==' '){
				s.erase(i,1);
				i--;
			}
		}
*/
		if(s[0]!='+' && s[0]!='-')	s="+"+s;
		while(s[igual]!='=') igual++;

		for(int i=ini;i<=igual;i++){
			if(s[i]=='+' || s[i]=='-' || s[i]=='='){
//cout<<"det "<<endl;
				if(s[i-1]=='x'){
					temp=toi(s.substr(ini,i-1-ini) );
					s[ini-1]=='+'?(x1+=temp):(x1-=temp);
				}else{
					temp=toi(s.substr(ini,i-ini) );
					s[ini-1]=='+'?(c1+=temp):(c1-=temp);
				}
				ini=i+1;
			}
		}
		if(s[igual+1]!='+' && s[igual+1]!='-')	s.insert(igual+1,"+");
		s+="=";
		l=s.size();

		ini=igual+2;
//cout<<s<<" "<<igual<<endl;

		for(int i=ini;i<l;i++){
			if(s[i]=='+' || s[i]=='-' || s[i]=='='){
				if(s[i-1]=='x'){
					temp=toi(s.substr(ini,i-1-ini) );
					s[ini-1]=='+'?(x2+=temp):(x2-=temp);
				}else{
					temp=toi(s.substr(ini,i-ini) );
					s[ini-1]=='+'?(c2+=temp):(c2-=temp);
				}
				ini=i+1;
			}
		}

//cout<<"c1 "<<c1<<", c2 "<<c2<<", x1 "<<x1<<", x2 "<<x2<<endl;
		if(x1==x2){
			if(c1==c2)	cout<<"IDENTITY"<<endl;
			else		cout<<"IMPOSSIBLE"<<endl;
		}else{
			if(x1>x2)		temp=floor( ((double)(c2-c1))/((double)(x1-x2)) );
			else			temp=floor( ((double)(c1-c2))/((double)(x2-x1)) );
			cout<<temp<<endl;
		}
		s.clear();
	}

	return 0;
}

