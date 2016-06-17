#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
	char tab[200];
	for(int i=0;i<200;i++)	tab[i]='0';
	
	string ss="0123456789";
	string st="OIZEASGTBP";

	for(int i=0;i<ss.size();i++)	tab[ss[i]]=st[i];
	
	int n;
	scanf("%d\n",&n);
	string sin;
	
	while(n--){
		int l;
		while(getline(cin,sin), sin.size()!=0){
//cout<<sin<<endl;
			l=sin.size();
			for(int i=0;i<l;i++){
				if(tab[sin[i]]!='0')	cout<<tab[sin[i]];
				else					cout<<sin[i];
			}
			cout<<endl;
		}
		if(n!=0)	cout<<endl;

	}
	
	return 0;
}
