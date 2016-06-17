#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
map<string,int> mp;

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		mp[s]++;
		getline(cin,s);
	}
	map<string,int>::iterator it;
	for(it=mp.begin(); it!= mp.end(); ++it)
		cout<<(*it).first<<" "<<(*it).second<<endl;
		
	return 0;
}
