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
#include<numeric>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (x).size()
using namespace std;
struct kid{ 
string nombre; 
char w1;
char w2;
};
int i;
kid getGanador();
kid getKid();
kid jugar(kid,kid);
string linea;
int comparar(char,char);
int main(){
	bool imprimioUno=false;
	while(getline(cin,linea)!=NULL){
		i=1;
		linea="["+linea+"]";
		//for(int k=0;k<linea.size();k++){ cout<<k<<" "<<linea[k]<<"        "; if(k%8==0&&k!=0) cout<<endl;}
		if(imprimioUno) cout<<endl; imprimioUno=true;
		kid ganador=getGanador();
		
		cout<<"Final Winner: ("<<ganador.nombre<<"-"<<ganador.w1<<"-"<<ganador.w2<<")"<<endl;
		
	}
return 0;}
kid getGanador(){
	//cout<<"Pide Ganador: "<<i<<endl;
	queue<kid> colas;
	kid best;
	bool hayComunidad=false;
	while(linea[i]!=']'){
		
		if(linea[i]=='['){
			hayComunidad=true;
			i++;
			best=getGanador();
		}else
		if(linea[i]=='('){
			i++;
			colas.push(getKid());
			
		}
		
		i++;
		//if(i>=linea.size()) break;
	}
	if(!hayComunidad){
		best=colas.front();
		colas.pop();
	}
	while(!colas.empty()){
		best=jugar(best,colas.front());
		colas.pop();
	}
	//cout<<"Termina G: "<<i<<endl;
	return best;
}
kid getKid(){
	//cout<<"Pide ninio: "<<i<<endl;
	kid ans;
	string nom="";
	while(linea[i]!='-') { nom=nom+linea[i]; i++;}
	//cout<<"Termine de vericiar nombre: i "<<i<<endl;
	ans.nombre=nom;
	ans.w1=linea[i+1];
	ans.w2=linea[i+3];
	i+=4;
	//cout<<ans.nombre<<" "<<ans.w1<<" "<<ans.w2<<endl;
	//cout<<"Termina : "<<i<<endl;
	return ans;
}
kid jugar(kid a1,kid a2){
	int ans;
	char w1,w2;
	if(ans=comparar(a1.w1,a2.w1))
		{w1=a1.w1; w2=a2.w1;}
	else if(ans=comparar(a1.w2,a2.w1))
		{w1=a1.w2; w2=a2.w1;}
	else if(ans=comparar(a1.w1,a2.w2))
		{w1=a1.w1; w2=a2.w2;}
	else if(ans=comparar(a1.w2,a2.w2))
		{w1=a1.w2; w2=a2.w2;}
	else {ans=1; w1=a1.w1; w2=a2.w1;}
	cout<<a1.nombre<<", Weapon: "<<w1<<" VS "<<a2.nombre<<", Weapon: "<<w2<<endl;
	cout<<"Won: ";
	if(ans==1) {cout<<a1.nombre<<endl; return a1;}
	else {cout<<a2.nombre<<endl; return a2;}
	
}
int comparar(char c1,char c2){
	if(c1=='P'&&c2=='R') return 1;
	if(c1=='P'&&c2=='S') return -1;
	if(c1=='R'&&c2=='S') return 1;
	if(c1=='R'&&c2=='P') return -1;
	if(c1=='S'&&c2=='P') return 1;
	if(c1=='S'&&c2=='R') return -1;
	return 0;
}


