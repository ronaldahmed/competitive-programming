#include<iostream>
#define N	100500
using namespace std;
int sumad(int a){
	int s=0;
	while(a!=0){
		s+=a%10;
		a/=10;
	}
	return s;
}

int main(){
	int table[N];
	table[0]=0;
	for(int i=1;i<N;i++){
		table[i]=i+sumad(i);
	}
	
	int num,a,c=0;
	cin>>num;
	while(num--){
		c=0;
		cin>>a;
		for(int i=1;i<N;i++){
			if(table[i]==a){	c=i;	break;}	
		}
		cout<<c<<endl;
		//if(num!=0)		cout<<endl;
	}
	return 0;
}
