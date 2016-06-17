#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define	MAXN	4700
#define	all(x)	(x).begin(),(x).end()

using namespace std;

int a[MAXN],b[MAXN],c[MAXN],d[MAXN];

int main(){
	int n;

	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d %d %d\n",a+i,b+i,c+i,d+i);		
	}
	vector<int> l,r;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			l.push_back(a[i]+b[j]);
			r.push_back(c[i]+d[j]);
		}
	sort( l.begin(),l.end() );
	sort( r.begin(),r.end() );
	
	vector<int>::iterator it,temp;
	int mx = 0, le,re;
	for(it=l.begin(); it!=l.end() ;){
		int k=-(*it);
		if( binary_search(all(r),k) ){
			re = upper_bound(all(r),k) - lower_bound(all(r),k);
			temp = upper_bound(all(l),-k);
			le = temp - it;

//cout<<".."<<le<<" "<<re<<endl;

			mx += le*re;
			
//			if(it != temp)	it=temp;
//			else				it++;
			it=temp;
		}else
			it++;
	}
	
	printf("%d\n",mx);
	
	return 0;
}
