#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> webs;

int toInt(string a,int p){
	int f=1,num=0;
	for(int i=a.size()-1;i>=p;i--){
		num += (a[i]-'0')*f;
		f*=10;
	}
	return num;
}

int main(){
	int t,j=1;
	cin>>t;
	while(t--){
		string s;
		webs.clear();
		int mx=0;
		cin.ignore();
		for(int i=0;i<10;++i){
			getline(cin,s);
			int k=s.size()-1;
			while(s[k]!=' ')	k--;
//cout<<"s: "<<s.size()<<"  k: "<<k<<endl;
			
			int temp=toInt(s,k+1);
			if(mx < temp){
				webs.clear();
				mx=temp;
			}
			if(mx <= temp)
				webs.push_back(s.substr(0,k));			
		}
		cout<<"Case #"<<(j++)<<":"<<endl;
		for(int i=0;i<webs.size();++i)
			cout<<webs[i]<<endl;

	}
	return 0;
}
