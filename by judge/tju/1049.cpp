/*  COMMENTED: UNDER CONSTRUCTION
#include<iostream>
#include<vector>
#include<cstdlib>

#define N		10000
#define	PB(x)	push_back(x)
#define	F(x,i)	(x[i]).first
#define	S(x,i)	(x[i]).second

using namespace std;
vector<pair<int,int> >	x;
vector<pair<int,int> >	y;
int len;					//longitud datos


int particionarF(int p, int r, int *A){
	int xx = A[p].first;
	int q=p;
	for(int s=p+1;s<=r;s++){
		if(A[s].first<xx){
			q++;
			swap(x[q],x[s]);
			swap(y[q],y[s]);
		}
	}
	swap(x[p],x[q]);
	swap(y[p],y[q]);
	return	q;
}

void QuickSortF(int p, int r, int *A){
	if(r<=p)			return;
	int i=rand()%r+p;
	swap(x[i],x[p]);
	swap(y[i],y[p]);

	int q = particionarF(p,r,A);
	QuickSortF(p,q-1,A);
	QuickSortF(q+1,r,A);

}

int particionarS(int p, int r, int *A){
	int xx=A[p].second;
	int q=p;
	for(int s=p+1;s<=r;s++){
		if(A[s].second<xx){
			q++;
			swap(x[q],x[s]);
			swap(y[q],y[s]);
		}
	}
	swap(x[p],x[q]);
	swap(y[p],y[q]);
	return	q;
}

void QuickSortS(int p, int r, int *A){
	if(r<=p)			return;
	int i=rand()%r+p;
	swap(x[i],x[p]);
	swap(y[i],y[p]);

	int q = particionarS(p,r,A);
	QuickSortS(p,q-1,A);
	QuickSortS(q+1,r,A);

}


int main(){
	int nr;
	int xm,xmm,ym,ymm;
	while(cin>>nr){
		while(nr--){
			cin>>xm>>xmm>>ym>>ymm;
			x.PB(make_pair(xm,xmm));
			y.PB(make_pair(ym,ymm));
		}
		len=x.size();
		bool eq=1;
		for(int i=1;i<len;i++){
			if(F(x,i-1)!=F(x,i) && F(y,i-1)!=F(y,i)){
				eq=0; break;
			}
		}

for(int i=0;i<l;i++){
	cout<<x[i].first<<" "<<x[i].second<<" "<<y[i].first<<" "<<y[i].second<<endl;
}
cout<<endl<<"Ordenado es:"<<endl;

//		if(!eq)		QuickSortF(0,l-1,x);
//		else		QuickSortS(0,l-1,y);

for(int i=0;i<l;i++){
	cout<<x[i].first<<" "<<x[i].second<<" "<<y[i].first<<" "<<y[i].second<<endl;
}

//NIvel 01: X min

		int cc=0;
		for(int i=l-1;i>0;i--){
			if(S(x,i)>=F(x,i-1))
		}
		
		x.clear();	y.clear();
		cc=0;

	}
	
	return 0;
}
*/
