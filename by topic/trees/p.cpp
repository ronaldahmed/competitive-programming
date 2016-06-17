#include<iostream>
#include<cmath>
#define ld	long double
#define	INF	(1<<30-1)
#define ll	long long

using namespace std;

ld fun(ld n){
	return (ld)log(n+1)/( (ld)log(n) );
}

int main(){
	ld n;
	cout<<"n: "<<endl;
	cin>>n;
	cout<<fun(n)<<endl;
	return 0;

}
