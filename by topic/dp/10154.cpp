#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> w;
vector<int> s;
vector<int> pila;
int wA=0;

void DP(int mx){
	int it=-1;
	if(!w.empty()){
		for(int i=0;i<w.size();i++){
			if(s[i]>=wA){	it=i; break;}
		}
		if(it==-1)	return;

		wA+=w[it];
//cout<<"wa "<<wA<<endl;
		pila.push_back(w[it]);
		w.erase(w.begin()+it);
		s.erase(s.begin()+it);
		DP(mx);
		
	}else		return;
	
}

int main(){
	vector<pair<int,int> > ts;
	pair<int ,int> p;
	int maxs=0,it=0;

//vector pair<w,strenght >	
	while(cin>>p.first>>p.second){
		p.second-=p.first;
		if(p.first>=0 && p.second>=0)
			ts.push_back(p);
	}
	int l=ts.size();

	if(l>0){
		sort(ts.begin(),ts.end());
	
		for(int i=0;i<l;i++)	maxs=max(maxs,(ts[i]).second);

//se quiere min W
		if((ts[0]).second==maxs && l>1)		it=1;
		else							it=0;
		for(int i=0;i<l;i++){
			w.push_back((ts[i]).first);
			s.push_back((ts[i]).second);
		}
	
		wA=w[it];
		pila.push_back(w[it]);
		w.erase(w.begin()+it);
		s.erase(s.begin()+it);

		DP(maxs);

	//Inicio DP	
		int num=pila.size();

	for(int i=0;i<num;i++)	cout<<pila[i]<<" ";
	cout<<endl<<"w: ";

	for(int i=0;i<w.size();i++)	cout<<w[i]<<" ";
	cout<<endl;

	
				cout<<num<<endl;
	}else		cout<<0<<endl;
	
	return 0;
}
