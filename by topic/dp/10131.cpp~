#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main(){
	vector<pair<int,int> > elf;
	vector<pair<int,int> > es;
	pair<int ,int> p;
	
	while(cin>>p.first>>p.second){
		elf.push_back(p);
		es.push_back(p);
	}
	int l=es.size();
	int suc[l];
	int L[l];
	int mapeo[l];
	
	sort(es.begin(),es.end());

//mapeo
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(elf[i]==es[j]){	mapeo[j]=i;	break; }
		}
	}

	L[l-1]=1;
	suc[l-1]=-1;

//Inicio DP	
	int m,it;
	int lk;

	for(int i=l-2;i>=0;i--){
		m=0;
		it=-1;
		for(int j=i+1;j<l;j++){
			if( (es[i]).second> (es[j]).second && (es[i]).first!=(es[j]).first ){
				if(L[j]>m){		m=L[j]; it=j;	}
			}
		}
		suc[i]=it;
		L[i]=1+m;
	}
	m=0;it=0;
	
	for(int i=0;i<l-1;i++){
		if(L[i]>m){	m=L[i]; it=i;	}
//cout<<L[i]<<" ";
	}
//cout<<endl;
//it mapea todo
	cout<<L[it]<<endl;

	for(int i=it;i!=-1;){
		cout<<mapeo[i]+1<<endl;
		i=suc[i];
	}
	return 0;
}
