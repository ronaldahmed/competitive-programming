#include <iostream>
#include <cstdio>
#include <algorithm>
#define	MAXN	40001

using namespace std;
int tree[MAXN], level[MAXN];
//bool map[MAXN];

void add(int pos){
	for(int i=pos;i<MAXN; i += i&-i)
		tree[i]++;
}

int sum(int pos){
	int res=0;
	for(int i=pos;i>0;i -= i&-i)
		res+=tree[i];
	return res;
}

int main(){
	int n,x,y;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d\n",&x,&y);
		x++;
		add(x);
		level[sum(x)-1]++;
	}
	for(int i=0;i<n;++i)	printf("%d\n",level[i]);
	
	return 0;
}
