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
int times=0;

void DFS_visit(int u, int* d, int* low, int* p, int* children, char* color,bool* art){
    int nu= graph[u].sz;
    int v;

    d[u]=++times;
    low[u]=d[u];
    color[u]='g';
    children[u]=0;

    REP(i,0,nu){
        v=graph[u][i];
        if(color[v]=='w'){
            children[u]++;
            p[v]=u;
            DFS_visit(v,d,low,p,children,color,art);
            low[u]=min(low[u],low[v]);

            if(p[u]!=-1 and low[v]>=d[u])
                art[u]=true;
        }else if (color[v]=='g'and p[u]!=v)
            low[u]=min(low[u], d[v]);

    }
    color[u]='b';
}

void DFS(int* d, int* low, int* p,int* children, char* color, bool* art,int n){
    times=0;
    REP(i,0,n){
        p[i]=-1;
        color[i]='w';
        art[i]=false;
    }
    REP(i,0,n){
        if(color[i]=='w'){
            DFS_visit(i,d,low,p,children,color,art);
            if(children[i]>1)
                art[i]=true;
        }
    }
}

int search(string s, string* L,int n){
    REP(i,0,n){
        if(s==L[i]){
            return i;
        }
    }
}

int main(){
    int n,ed;
    int x,y;
    int cc=1;
    string s1,s2;

    bool enter=1;

    while(cin>>n, n!=0){
        string loc[n];
        int d[n];
        int low[n];
        int parent[n];
        int children[n];
        char color[n];
        bool artic[n];


        graph.clear();

        REP(i,0,n){
            cin>>loc[i];
            vi gt;
            graph.pb(gt);
        }
        cin>>ed;
        REP(i,0,ed){
            cin>>s1>>s2;
            x=search(s1,loc,n);
            y=search(s2,loc,n);

            graph[x].pb(y);
            graph[y].pb(x);
        }

        DFS(d,low,parent,children,color,artic,n);

/*        REP(i,0,n){
            cout<<i<<": ";

            REP(j,0,graph[i].sz){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        vs  cams;
        REP(i,0,n){
            if(artic[i])
                cams.pb(loc[i]);
        }
        sort(all(cams));
        int nc=cams.sz;

        if(enter)   enter=0;
        else        cout<<endl;

        cout<<"City map #"<<cc++<<": "<<nc<<" camera(s) found"<<endl;

        REP(i,0,nc)
            cout<<cams[i]<<endl;

    }

	return 0;
}
