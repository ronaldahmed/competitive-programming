#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
string s,p;
int len,t;
int m=0;

string tras(string a){
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]=='B')	a[i]='N';
		else			a[i]='B';
	}
	return a;
}

int dp(int k, int j){

//cout<<"bbf :"<<endl;

	if( p.substr(k,j-k)==tras(s.substr(k,j-k)) )	return 1;
	if( p.substr(k,j-k)==s.substr(k,j-k) )			return 0;
	
//cout<<"entre !"<<endl;
	for(int i=k; i<j ;i++){
		if(s[i]==p[i]){	t=i; break;	}
	}

//cout<<"pase !, t= "<<t<<"  j: "<<j<<endl;
	if(t==k)			return dp(t+1,j);
	else{ if(t==j-1)	return dp(k,j-1);
	else 				return (dp(k,t)+dp(t+1,j) );
	}
}

int main(){
	int mov=0;
	while(cin>>s>>p, s!="*" || p!="*"){
//cout<<s<<" "<<p<<endl;
		len=p.size();
		m=0;
		mov=dp(0,len);
		cout<<mov<<endl;
		
		
	}
	return 0;
}
