#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define		maxn		30100
#define		max_q		2000100

using namespace std;

struct event{
	bool type;					// 1: query, 0: number
	int a,b,ID;
	event(int _a, int _b){
		a=_a;
		b=_b;
	}
	bool operator <(event e)const{
		return b<e.b;
	}
};

vector<event> E;
int lastPos[max_q],a[maxn], querys[max_q];
int T[maxn],n;

void update(int pos, int val){
	for(;pos<n; pos += pos&-pos)	T[pos]+=val;
}

int sum(int pos){
	int res=0;
	for(;pos>0;pos -= pos&-pos)	res+=T[pos];
	return res;
}

int main(){
	int q;
	scanf("%d\n",&n);
	for(int i=0,tmp;i<n;++i){
		scanf("%d",a+i);
	}
	scanf("%d\n",&q);
	for(int i=0,u,v;i<q;++i){
		scanf("%d %d\n",&u,&v);
		if(u>v)	swap(u,v);
		event e = event(u,v);
		e.ID = i;
		E.push_back(e);
	}
	sort(E.begin(),E.end());
	
/*	for(int i=0;i<E.size();++i){
		printf("%d  ",E[i].b);
	}
	cout<<endl;
*/
	
	memset(lastPos,-1,sizeof lastPos);
	memset(T,0,sizeof T);
	
	int total=0, pos=0;
	
	for(int i=0;i<n;++i){
		if(lastPos[a[i]]!=-1)
			update(lastPos[a[i]],-1);
		else
			total++;
		
		update(i+1,1);
		lastPos[a[i]] = i+1;
		
		while(pos<q && E[pos].b==i+1){
			querys[E[pos].ID] = total - sum(E[pos].a-1);
			pos++;
		}
	}

	for(int i=0;i<q;++i)
		printf("%d\n",querys[i]);
	
	return 0;
}
