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
int times=0;

void DFS_visit(int u,int** G, char* color, int* d, int* p, bool* bridge, int* grado,int* low){
    int v;
    d[u]=++times;
    color[u]='g';
    low[u]=d[u];

    for(int i=0;i<grado[u];i++){
        v=*(G[u]+i);
        if(color[v]=='w'){
//cout<<"DFS_v: node "<<v<<endl;
            p[v]=u;
            DFS_visit(v,G,color,d,p,bridge,grado,low);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u])
                bridge[v]=true;
        }else if(color[v]=='g' and p[u]!=v)
            low[u]=min(low[u],d[v]);
    }
    color[u]='b';
}

void DFS(int** G, char* color, int* d, int* p, bool* bridge, int* grado,int* low,int n){
    times=0;
    for(int i=0;i<n;i++){
        color[i]='w';
        p[i]=-1;
        bridge[i]=false;
    }

    for(int i=0;i<n;i++){
        if(color[i]=='w'){
//cout<<endl<<"node "<<i<<" at time "<<times<<endl;
            DFS_visit(i,G,color,d,p,bridge,grado,low);
        }
    }

}

int main(){
    int n;
	int net_i, net_j, nd;
	while(cin>>n){
	    if(n!=0){
	        int* graph[n];
	        int grado[n];
	        int d[n];
	        char color[n];
	        int parent[n];
	        bool bridge[n];
	        int low[n];

	        for(int i=0;i<n;i++){
                scanf("%d (%d) ",&net_i, &nd);
                int j=0;
                grado[net_i]=nd;
                graph[net_i]=(int*)malloc(nd*sizeof(int));
                while(nd--){
                    cin>>*(graph[net_i]+j);
                    j++;
                }
	        }

            DFS(graph,color,d,parent,bridge,grado,low,n);

            vector<pair<int,int> > links;
            int x,y;
            for(int i=0;i<n;i++){
                if(bridge[i]){
                    x=parent[i];
                    y=i;
                    if(x>y)     swap(x,y);
                    links.push_back(make_pair(x,y));
                }
            }
            sort(links.begin(), links.end());
            int nl=links.size();

            cout<<nl<<" critical links";
//            if(nl>1) cout<<"s";
            cout<<endl;

            for(int i=0;i<nl;i++)
                cout<<links[i].first<<" - "<<links[i].second<<endl;

            cout<<endl;

	    }else{
            cout<<"0 critical links"<<endl<<endl;
	    }
	}

	return 0;
}
