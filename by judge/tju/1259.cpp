#include<iostream>
#include<sstream>
#include<string>
#define		N	2147483647
#define		N1	800000000

using namespace std;

string tos(int n){
	stringstream a;
	string nn;
	a<<n;
	a>>nn;
	return nn;
}

int main(){
	int n,pos;
	string s="",s1="",s2="";

	for(int i=1;;i++){
		for(int j=1;j<=i;j++){
	cout<<"paso"<<" "<<i<<endl;
			if(s.size()<=N1)		s+=tos(j);
			else if(s1.size()<=N1)	s1+=tos(j);
			else if(s2.size()<=N1)	s2+=tos(j);
			else{
				cout<<"paso"<<endl;
				break;break;
			}
		}
	}

	cin>>n;
	while(n--){
		cin>>pos;
		if(pos<=s.size())		cout<<s[pos-1]<<endl;
		else{
			pos-=s.size();
			if(pos<=s1.size())	cout<<s1[pos-1]<<endl;
			else{
				pos-=s1.size();	cout<<s2[pos-1]<<endl;
			}
		}
	}

/*
	int sumas[10];
	for(int i=0;i<10;i++)
		sumas[i]=(i+1)*(i+2)/2;
	
	int n,pos;
	cin>>n;
	while(n--){
		cin>>pos;
		pos%=sumas[9];
		int j=0;

		for(int i=0;i<10;i++){
			if(pos>sumas[i])	j++;
			else				break;
		}
		if(j==0)	cout<<1<<endl;
		else{
			cout<<pos-sumas[j-1]<<endl;
		}
	}
*/
	return 0;
}
