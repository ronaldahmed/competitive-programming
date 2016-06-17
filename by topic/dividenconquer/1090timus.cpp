#include <iostream>
#include <cstdio>
#include <algorithm>
#define	oo		(1<<30)
#define	maxn	10100
using namespace std;

int A[maxn];

long long merge(int p, int r){
	long long inv=0LL;
	int q=(p+r)>>1;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i=0;i<n1;++i)	L[i]=A[p+i];
	for(int i=0;i<n2;++i)	R[i]=A[q+1+i];
	L[n1]=oo;
	R[n2]=oo;
	
	int i=0, j=0;
	
	for(int k=p ; k<=r ;++k){
		if(L[i] <= R[j])
			A[k]=L[i++];
		else{
			A[k]=R[j++];
			inv += n1-i;
		}
	}
	return inv;
}

long long mergesort(int p, int r){
	if(p!=r){
		int m=(p+r)>>1;
		long long li = mergesort(p,m);
		long long ri = mergesort(m+1,r);
		long long si = merge(p,r);
		return li+ri+si;
	}else
		return 0;
}

int main(){
	int n,k;
	int temp,j=0;
	long long mx=0LL, idx=1;
	cin>>n>>k;
	for(int r=0;r<k;++r){
		for(int i=0;i<n;++i)
			cin>>A[i];
		long long inv = mergesort(0,n-1);

//cout<<"-----"<<inv<<endl;

		if(mx<inv){
			mx=inv;
			idx=r+1;
		}
	}
	printf("%d\n",idx);
	return 0;
}
