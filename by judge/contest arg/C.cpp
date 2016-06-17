#include<iostream>
#include<stack>
#define		N		110
using namespace std;

stack<int> uno;
stack<int> zero;
int cams=0;
int mat[N][N];

void agrega1();
void agrega0();


int main(){
	int cam;
	int a,b;
	int cont,n;

	while(cin>>n>>cam, n!=-1 && cam!=-1){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)	mat[i][j]=0;
		}
	
		while(cam--){
			cin>>a>>b;
			mat[a-1][b-1]=1;
			mat[b-1][a-1]=1;
		}

		for(int i=0;i<n;i++){
			cont=0;
			for(int j=0;j<n;j++){
				if(mat[i][j]==1)	cont++;
			}
			if(cont==1)		uno.push(i);
			if(cont==0)		zero.push(i);
		}
		cams=0;

/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)	cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		if(!uno.empty())	cout<<"top uno:  "<<uno.top()<<endl;
		if(!zero.empty())	cout<<"top zero: "<<zero.top()<<endl;
				
cout<<endl;
*/
		agrega1();
		
		cout<<cams<<endl;
		
		while(!uno.empty() )	uno.pop();
		while(!zero.empty() )	zero.pop();

	}
	return 0;
}

void agrega1(){
	int a,b;
	
	if(uno.empty()){
		if(zero.empty() )	return;
		else				agrega0();
	}else{
		if(!zero.empty() ){
			a=uno.top();
			b=zero.top();
			mat[a][b]=1;		mat[b][a]=1;
			uno.pop();
			zero.pop();
			uno.push(b);
			cams++;
			
		}else if(uno.size()>1){
			a=uno.top();	uno.pop();
			b=uno.top();	uno.pop();
			if( mat[a][b]!=1){
				mat[a][b]=1;	mat[b][a]=1;
				cams++;
			}else	cams+=2;
		}else	if(uno.size()==1){		cams++;	uno.pop(); }
	}

	agrega1();
}

void agrega0(){
	int a,b;
	if(zero.size()>1){
		a=zero.top();	zero.pop();
		b=zero.top();	zero.pop();
		mat[a][b]=1;		mat[b][a]=1;
		
		uno.push(a);	uno.push(b);
		cams++;
	}else{
		cams+=2;
	}
	agrega1();
}
