#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define		ft	first
#define		sc	second

using namespace std;

int cant=0;
stack<int>	camino;


int main(){
	vector<pair<int,int> > elf;
	vector<pair<int,int> > es;
	
	vector< vector<int> > dag;
	pair<int ,int> p;
	
	while(cin>>p.first>>p.second){
		elf.push_back(p);
		es.push_back(p);
	}

	for(int i=0;i<elf.size();i++){
		cout<<i<<" : "<<(elf[i]).first<<" "<<(elf[i]).second<<endl;
	}
	
	cout<<endl<<"Sorted :"<<endl<<endl;
	sort(es.begin(),es.end());
	
	for(int i=0;i<es.size();i++)
		cout<<i<<" : "<<(es[i]).first<<" "<<(es[i]).second<<endl;
	

	int l=es.size();
	int itsec=0;
	int m=0;
		
	for(int i=0;i<l-1;i++){
		itsec=0;
		m=0;
		for(int j=i;j<l;j++){
			if( (es[i]).sc> (es[j]).sc ){
				if( (es[i]).ft!=(es[j]).ft ){
					dag[i].push_back(j);
				}
			}
		}
	}
	
	return 0;
}
