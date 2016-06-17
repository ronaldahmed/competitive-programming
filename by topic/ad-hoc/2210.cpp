#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>


using namespace std;
string tos(int a){
	stringstream ss;
	string s1;
	ss<<a;
	ss>>s1;
	return s1;
}

int toi(string s){
	stringstream ss;
	int a;
	ss<<s;
	ss>>a;
	return a;
}

int main(){
	int n;
	string a,b,c;
	int a1,b1;
	int c1;
	cin>>n;

	while(n--){
		cin>>a>>b;
		reverse(a.begin(),a.end());
		a1=toi(a);
		reverse(b.begin(),b.end());
		b1=toi(b);		
		c1=a1+b1;
		c=tos(c1);
		reverse(c.begin(),c.end());
		c1=toi(c);
		cout<<c1<<endl;
	}
	return 0;
}
