#include<iostream>
#define		N	50000
using namespace std;

int n,m,imax;
int a[N];
void iteration1(int *c, int p, int f, int it){
	// orden inicial: ascendente 1, 2, ..
	int i=0;
	while(it!=c[i])	i++;

	if(it>n-1){
		swap(a[p],a[f]);		it-=(n-1);
		iteration1(a,p+1,f-1,it);
	}else
		swap(a[f],a[f-it]);	
}

void iteration2(int p, int f, int r){
	//orden descendente: 7,6,5,2..1
	if(r>n-1){
		swap(a[p],a[f]);		r-=(n-1);
		iteration2(p+1,f-1,r);
	}else
		swap(a[p],a[p+r]);
}

int main(){
	//n y m globales evitar muchos parametros
	//imax tmb global
	int res;

	while(cin>>n>>m,n!=-1 && m!=-1){
		imax=n*(n-1)/2;
		int cad[n-1];

		for(int i=0;i<n-1;i++)
			cad[i]=i*(i+1)/2;

		if(m<imax/2){
			for(int i=0;i<n;i++)	a[i]=i+1;
			iteration1(cad,0,n-1,m);
		}else{
			for(int i=0;i<n;i++)	a[i]=n-i;
			res=imax-m;
			iteration2(0,n-1,res);
		}
		cout<<a[0];
		for(int i=1;i<n;i++)
			cout<<" "<<a[i];
		cout<<endl;
	}
	return 0;
}
