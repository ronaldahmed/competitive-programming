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

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define FOR(it,A) for(typeof (A.begin()) it = A.begin(); it!= A.end(); it++)
#define cua(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define inf (1LL << 40)
#define sz size()
#define oo (1<<30)
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> vi;

vector<vi > graph;
vector<vi > g_tras;
vi          SCC;
vs names;
vi L;
int times=0;
int c=0;

void SCC_visit1(int u, int* d, int* f, int* p, char* color){
    int nu=graph[u].sz;
    int v;
    d[u]=++times;
    color[u]='g';

    REP(i,0,nu){
        v= graph[u][i];
        if(color[v]=='w'){
//cout<<v<<" ";
            p[v]=u;
            SCC_visit1(v,d,f,p,color);
        }
    }
    color[u]='b';
    L.pb(u);
    f[u]=++times;
}

void SCC_visit2(int u, int* p, char* color){
    int nu=g_tras[u].sz;
    int v;

    color[u]='a';
    SCC[u]=c;

    REP(i,0,nu){
        v= g_tras[u][i];
        if(color[v]=='b'){
//cout<<v<<" ";
            p[v]=u;
            SCC_visit2(v,p,color);
        }
    }
    color[u]='r';
}

void DFS(int* d,int* f, int* p, char* color, int n){
    times=0;
    SCC.clear();

    REP(i,0,n){
        p[i]=-1;
        color[i]='w';
    }
//Primer DFS en G
    REP(i,0,n){
        if(color[i]=='w'){
//cout<<endl<<"DFS1 "<<i<<" :";
            SCC_visit1(i,d,f,p,color);
        }
    }

//Segundo DFS en GT
/*
cout<<endl<<"Segundo :"<<endl<<"f: ";
REP(i,0,n){
cout<<f[i]<<" ";
}
cout<<endl<<"L: ";
*/
    REP(i,0,n){
        SCC.pb(0);
//cout<<L[i]<<" ";
    }

    c=0;
    for(int i=n-1;i>=0;i--){
        int u=L[i];
        if(color[u]=='b'){
//cout<<endl<<"DFS2 "<<u<<" : ";
            c++;
            SCC_visit2(u,p,color);
        }
    }

}


int search(string s){
    int n=names.sz;
    REP(i,0,n){
        if(s==names[i]){
            return i;
        }
    }
}

bool match(string s){
    int n=names.sz;
    REP(i,0,n){
        if(s==names[i])      return true;
    }
    return false;
}

int main(){
    int n,m;
    int x,y;
    int k=1;
    string s1,s2;
    bool enter=1;
    while(cin>>n>>m, n!=0 and m!=0){
        int d[n];
        int f[n];
        int parent[n];
        char color[n];

        L.clear();
        names.clear();
        graph.clear();
        g_tras.clear();

        REP(i,0,n){
            vi temp;
            vi temp2;
            graph.pb(temp);
            g_tras.pb(temp2);
        }

        while(m--){
            cin>>s1>>s2;
            if(!match(s1))   names.pb(s1);
            if(!match(s2))   names.pb(s2);
            x=search(s1);
            y=search(s2);
            int  ng=graph[x].sz;
            bool ind=1;

            REP(i,0,ng){
                if(graph[x][i]==y){
                    ind=0;
                    break;
                }
            }
            if(ind){
                graph[x].pb(y);
                g_tras[y].pb(x);
            }
        }

/*cout<<"g normal:"<<endl;
        REP(i,0,n){
            cout<<i<<": ";
            REP(j,0,graph[i].sz)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;

cout<<endl<<"g traverse:"<<endl;
        REP(i,0,n){
            cout<<i<<": ";
            REP(j,0,g_tras[i].sz)
                cout<<g_tras[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
*/
        DFS(d,f,parent,color,n);

        vs SCCtotal[c];
        REP(i,0,c){
            vs temp;
            SCCtotal[i]=temp;
        }
//cout<<"c: "<<c<<endl;

        REP(i,0,n){
            SCCtotal[SCC[i]-1].pb(names[i]);
        }
//cout<<endl;

        if(enter)   enter=0;
        else        cout<<endl;

        cout<<"Calling circles for data set "<<k++<<":"<<endl;
        bool com=1;
        REP(i,0,c){
            com=1;
            REP(j,0,SCCtotal[i].sz){
                if(com)     com=0;
                else        cout<<", ";
                cout<<SCCtotal[i][j];
//cout<<search(SCCtotal[i][j]);
            }
            cout<<endl;
        }
/*cout<<endl<<"Names: "<<endl;
        REP(i,0,n)
            cout<<i<<" "<<names[i]<<endl;

        cout<<endl;
*/
    }
	return 0;
}
