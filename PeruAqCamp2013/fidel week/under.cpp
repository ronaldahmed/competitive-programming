#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define     mp      make_pair
#define     pb      push_back
#define     fst     first
#define     snd     second
#define     MAXN    1100

using namespace std;

int unionF[MAXN], p[MAXN], rank[MAXN];
double g[MAXN][MAXN];
vector <pair<int,int> > point;
vector <pair<double,pair<int,int> > > edges;

double dist(pair<int,int> p1, pair<int,int> p2){
    return sqrt((p1.fst-p2.fst)*(p1.fst-p2.fst) + (p1.snd-p2.snd)*(p1.snd-p2.snd));
}

double kruskal(){
    memset(p,-1,sizeof p);
    for(int i=0;i<MAXN;++i) unionF[i]=i, rank[i]=1;
    double L=0.0,w;
    
    for(int i=0,u,v;i<edges.size();i++){
        w=edges[i].fst;        
        u=edges[i].snd.fst;
        v=edges[i].snd.snd;
        while(p[u]!=-1)    u=p[u];
        while(p[v]!=-1)    v=p[v];
        if(unionF[u]!=unionF[v]){
            L+=w;
            if(rank[u]>rank[v]) swap(u,v);
            p[v]=u;
            rank[u]+=rank[v];
        }
    }
    return L;
}

int main(){
    int n,x,y;
    while(cin>>n, n!=0){
        point.clear();
        edges.clear();

        for(int i=0;i<MAXN;++i)
            for(int j=0;j<MAXN;++j)     g[i][j]=0.0;

        for(int i=0;i<n;i++){
            cin>>x>>y;
            point.push_back(make_pair(x,y));
        }
        for(int i=0;i<n-1;++i)
            for(int j=i+1;j<n;++j){
                double temp=dist(point[i],point[j]);
                g[i][j]=g[j][i]=temp;
                edges.pb(mp(temp,mp(i,j)) );
            }
        sort(edges.begin(),edges.end());
        printf("%.2f\n",kruskal());
    }
    return 0;
}
