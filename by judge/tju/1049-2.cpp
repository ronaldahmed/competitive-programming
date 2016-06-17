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

int main(){
	int nr;
	int xm,xmm,ym,ymm;

	while(cin>>nr){

		while(nr--){
			cin>>xm>>xmm>>ym>>ymm;
			x.PB(make_pair(xm,xmm));
			y.PB(make_pair(ym,ymm));
		}
		int l=x.size();
		int cc=0;
		for(int i=l-1;i>=0;i--){
			for(int j=l-1;j>=0;j--){
				if(i!=j && F(x,i)>=F(x,j) && S(x,i)<=S(x,j) && F(y,i)>=F(y,j) && S(y,i)<=S(y,j)){
					cc++; break;
				}
			}
		}
		cout<<cc<<endl;
		x.clear();	y.clear();
		cc=0;
	}
	
	return 0;
}
