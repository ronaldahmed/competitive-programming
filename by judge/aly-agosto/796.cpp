#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;
int n=0;
int times=0;
int node_pos=1;

struct tree{
    int dato;
    int pos;
    tree *Parent;
    tree *Lson;
    tree *Rsib;
};

vector<tree* > ST;

tree* insertar(tree* A, int d){
    tree* temp=(tree*)malloc(sizeof(tree));
    temp->dato=d;
    if(A->Lson==NULL){
        A->Lson=temp;
        temp->Parent=A;
    }else{
        temp->Parent=A;
        temp->Lson=NULL;
        temp->Rsib=NULL;
        (A->Lson)->Rsib=temp;
    }
    return temp;
}

void DFS_visit(int u, int* G, char* color, int* p, int* d, int* f,tree* A){
    color[u]='g';

    d[u]=++times;

    for(int i=0;i<n;i++){
        if(G[u*n+i]==1 && color[i]=='w'){
            p[i]=u;
            tree* temp=insertar(A,i);
            DFS_visit(i,G,color,p,d,f,temp);
        }
    }
    color[u]='b';
    f[u]=++times;
}

void DFS(int* G, char* color, int* p, int* d, int* f){
    times=0;
    ST.clear();
    for(int i=0;i<n;i++){
        if(color[i]=='w'){
            tree* dft=(tree*)malloc(sizeof(tree));
            dft->dato=i;
            dft->Parent=NULL;

            DFS_visit(i,G,color,p,d,f,dft);
            if(f[i]!=d[i]+1){
                ST.push_back(dft);
            }
        }
    }
}

void preOrder(tree* A){
    if(A!=NULL){
        A->pos=node_pos;
        cout<<A->dato<<"<"<<node_pos<<">"<<" (";
        node_pos++;
        preOrder(A->Lson);
        preOrder(A->Rsib);
    }else
        cout<<") ";
}

int main(){
	int net_i, net_j, nd;

	while(cin>>n){
	    if(n!=0){
            int net[n*n];
            int grado[n];

            int d[n];
            int f[n];

            int parent[n];

            char color[n];
            node_pos=1;

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    net[i*n+j]=0;
                grado[i]=0;
                color[i]='w';
                parent[i]=-1;
            }

            for(int i=0;i<n;i++){
                scanf("%d (%d) ",&net_i, &nd);
                grado[net_i]=nd;
                while(nd--){
                    cin>>net_j;
                    net[net_i*n+net_j]=1;
                }
            }

            DFS(net,color,parent,d,f);

            tree* temp=(tree*)malloc(sizeof(tree));
            tree* temp2=(tree*)malloc(sizeof(tree));

            for(int i=0;i< ST.size();i++){
                preOrder(ST[i]);
                cout<<endl;
            }
            cout<<endl;

	    }else
            cout<<"0 crtical links"<<endl;
	}
	return 0;
}
