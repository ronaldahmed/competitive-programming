#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define	MAXN	100100

using namespace std;

int T[4*MAXN];
int Q[MAXN];
vector<int> V;
map<int,int> frec;

void update(int node,int l, int r, int pos, int val){
	if(pos<l || pos>r)	return;
	if(l==r && l==pos){
		T[node] = val;
		return;
	}
		
	int mid=(l+r)>>1;
	update(2*node+1,l,mid,pos,val);
	update(2*node+2,mid+1,r,pos,val);
	T[node]=__gcd(T[2*node+1],T[2*node+2]);
}

int main(){
	int n;
	char ch;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		scanf("%c %d\n",&ch,Q+i);

		if(ch=='+')	V.push_back(Q[i]);
		else			Q[i] = -Q[i];
	}
		
	int len = ceil(sqrt(V.size()) );
	V.resize(len*len,0);
	sort(V.begin(),V.end());
	
/*	for(int i=0;i<V.size();++i)	cout<<V[i]<<" ";
	cout<<endl<<"----"<<endl;
*/	
	for(int i=0,temp;i<n;++i){
		frec.find(abs(Q[i]))!=frec.end()? temp=frec[abs(Q[i])] : temp=frec[abs(Q[i])]=0;
		if(Q[i]<0)	temp--;
		
		int ind = (int)(lower_bound(V.begin(),V.end(),abs(Q[i])) - V.begin())+ temp;

//		cout<<"frec "<<abs(Q[i])<<" : "<<frec[ abs(Q[i]) ]<<" + "<<(int)(lower_bound(V.begin(),V.end(),abs(Q[i])) - V.begin())<<"/"<<ind<<endl;

		update(0,0,V.size()-1, ind,Q[i]<0?0:Q[i]);
		

		printf("%d\n",T[0]==0?1:T[0]);
		
		if(Q[i]>=0)	temp++;
		frec[abs(Q[i])] = temp;
	}
	
	return 0;
}
