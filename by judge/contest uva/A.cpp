#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
using namespace std;
bool test(vector<int> a,vector<int> b); 
int main(){
	int N;
	cin>>N;
	vector<int> v,vo;
	int a;
	cout<<"Lumberjacks:"<<endl;
	while(N--){
		
		for(int i=0;i<10;i++){
			cin>>a;
			v.PB(a);	
		}
		vo=v;
		sort(ALL(vo));
		if(test(vo,v)) cout<<"Ordered"<<endl;
		else cout<<"Unordered"<<endl;
		v.clear();
		vo.clear();
	}
	
	return 0;
}
bool test(vector<int> a,vector<int> b){
		bool b1=true,b2=true;
		for(int i=0;i<10;i++) if(a[i]!=b[i]) b1=false;
		reverse(ALL(a));
		for(int i=0;i<10;i++) if(a[i]!=b[i]) b2=false;
		if(b1 || b2) return true;
		return false;
}






