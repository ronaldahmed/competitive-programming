#include <iostream>
#include <cstdio>
#include <cstring>
#define	REP(i,x,y)	for(int (i) = (x); (i)<(y);++i)


using namespace std;
const int N = 20;
long long diff[N][N];
long long fact[11];
int n,k;
	
long long perm(int n, int k){
	long long res = 1LL;
	REP(i,0,k)
		res *= (n-i);
	return res;
}
	
int main(){
	fact[0] = 1LL;
	REP(i,1,11)	fact[i] = i*fact[i-1];
	
	while(cin >> n, n){
		REP(i,0,n)	cin >> diff[i][0];
		cin >> k;
		
		REP(i,1,n)
			REP(j,0,n-i)
				diff[j][i] = diff[j+1][i-1] - diff[j][i-1];
		
		/*
		REP(i,0,n){
			REP(j,0,n)
				cout << diff[i][j] << " ";
			cout << endl;
		}
		*/
		
		long long res = 0LL;
		REP(i,0,n){
			res += perm(k+n-1,i) * diff[0][i]/fact[i];
		}
		printf("Term %d of the sequence is %lld\n",k+n,res);
	}
	return 0;
}
