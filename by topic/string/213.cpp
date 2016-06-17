#include <iostream>
#include <string>
#include <map>

using namespace std;
string header;
map<string,int> key;

string toS(int num, int dig){
	string s;

	for(int i=dig-1;i>=0;--i){
		s.push_back( ((1<<i)&num?1:0) + '0' );
	}
	return s;
}

int toInt(string s){
	int num=0;
	for(int i=0;i<s.size();++i){
		num += (1<<(s.size()-i-1))*(s[i]-'0');
	}
	return num;
}

int main(){

	for(int i=1,acum=0;i<=9;++i){
		for(int j=0;j<(1<<i)-1;++j,acum++){
			string s = toS(j,i);
			key[s] = acum;
		}
//if(i==9)	cout<<acum<<endl;
	}


	string line;
	while( getline(cin,header) ){
//		cout<<"*header : : "<<header<<endl;
		
		getline(cin,line);
		
//		cout<<"*initial_line: "<<line<<endl;
		
		int ini=0;		
		while(1){
		
//			cout<<"--------------------"<<endl;
			
			if(line.size()-ini<3){
			
//				cout<<"--resta:  "<<line.size()-ini-1;
				
				string ap;
				getline(cin,ap);
				line = line.substr(ini) + ap;
				ini=0;
//				cout<<ap<<endl;
			}

//			cout<<endl<<"cur_line: "<<line<<endl;

			int seg_size= toInt(line.substr(ini,3));

//			cout<<endl<<"seg:  "<<seg_size<<"   -   ini: "<<ini<<endl;

			if(seg_size==0)
				break;
			
			ini+=3;
			
			while(1){
				if(line.size()-ini<seg_size){
				
//					cout<<"--resta_k:  "<<line.size()-ini-1<<endl;
					
					string ap;
					getline(cin,ap);
					line = line.substr(ini) + ap;
					ini=0;
				}

//				cout<<"cur_inte: "<<line<<endl;

				int k = toInt(line.substr(ini,seg_size));
				if(k==(1<<seg_size)-1){
					ini += seg_size;
					break;
				}
				
//				cout<<"----ini_bef:  "<<ini<<endl;
				
				cout<<header[key[line.substr(ini,seg_size)]];
				ini+=seg_size;
				
//				cout<<"----ini_aft:  "<<ini<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
