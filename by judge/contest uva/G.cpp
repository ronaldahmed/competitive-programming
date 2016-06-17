#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
#define SZ(x) (x).size()

using namespace std;
bool isPot(int L);
bool mapa[1<<14][1<<14];
void makeTree(int,int,int);
void pintar(int x,int y,int L);
int main(){
	int casos;
	int L;
	cin>>casos;
	string lineaBasura;
	while(casos--){
		scanf("%d ",&L);
		
		if(isPot(L)){
			
			for(int i=0;i<=L+1;i++)
				for(int j=0;j<=L+1;j++)
					if(j==0||j==L+1) mapa[i][j]=false;
					else mapa[i][j]=true;
					
			//cout<<"LLEGO HASTA AQUI"<<endl;
			char ch;
			makeTree(1,1,L);
			
			bool imprimioUno=false;
		/*	for(int i=1;i<=L;i++)
			{	for(int j=1;j<=L;j++)
					{cout<<mapa[i][j];
					
					}
					cout<<endl;
					}
					cout<<"Fue un caso"<<endl;
					*/
			for(int y=1;y<=L;y++){
				int beg=0;
				int end=1;
				while(end<=L){
					//cout<<mapa[1][1]<<endl;
					while(end<=L&&mapa[y][end]) end++;
					//cout<<"L:"<<L<<" El end "<<end<<endl;
					/*if(end-beg==L+1) {}
					else
					*/
					if(end-beg>2){
						if(imprimioUno) cout<<",";
						printf("(%d-%d,%d)",beg+1,end-1,y);
						imprimioUno=true;
					}
					else
					if(end-beg==2){
						if(imprimioUno) cout<<",";
						printf("(%d,%d)",beg+1,y);
						imprimioUno=true;
					}
					beg=end;
					end=beg+1;
					
				}
			}
			cout<<endl;
					
		}
		else{
		cin>>lineaBasura;
		cout<<"Invalid length"<<endl;
		}
		
		
	} 
	return 0;
}
bool isPot(int L){
	if(L==1) return true;
	if(L%2!=0) return false;
	while(L%2==0){
		//cout<<" "<<L<<endl;
		L=L>>1;
	}
	
	if(L==1) return true;
	return false;
}

void makeTree(int x,int y,int L){
	char ch;
	scanf("%c",&ch);
	if(ch=='0') pintar(x,y,L);
	if(ch=='*') {
	
		makeTree(x,y,L/2);
		makeTree(x,y+L/2,L/2);
		makeTree(x+L/2,y,L/2);
	 	makeTree(x+L/2,y+L/2,L/2);
	}

}

void pintar(int x,int y,int L){
	//cout<<"Intenta pintar "<<x<<"*"<<y<<"*"<<L<<endl;
	//cout<<"Intentara pintar desde "<<x<<":"<<y<<" HASTA: "<<(x+L-1)<<":"<<(y+L-1)<<endl;
	for(int i=x;i<x+L;i++)
	for(int j=y;j<y+L;j++)
	mapa[i][j]=false;
}
