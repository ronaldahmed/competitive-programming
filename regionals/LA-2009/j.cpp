#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int table[30];

int main(){
	table['W'-'A'] = 64;
	table['H'-'A'] = 32;
	table['Q'-'A'] = 16;
	table['E'-'A'] = 8;
	table['S'-'A'] = 4;
	table['T'-'A'] = 2;
	table['X'-'A'] = 1;
	
	string s;
	getline(cin,s);
	while(s[0]!='*'){
		int mx=0;
		for(int i=0,c=0;i<s.size();++i)
			if(s[i]=='/'){
				if(c==64)	mx++;
				c=0;
			}else				c+=table[s[i]-'A'];
		cout<<mx<<endl;
		getline(cin,s);
	}

	
	return 0;
}
