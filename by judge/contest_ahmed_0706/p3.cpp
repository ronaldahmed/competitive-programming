/*
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

#define     FOR(i,n)        for(int i=0;i<n;i++)

using namespace std;
int l_max;

void expand(int grid[],int n, int jx[],int jy[],int l[]){
    FOR(i,n){
        for(int j=jx[i]+l_max-1-l[i] ; j<= jx[i]+l_max-1+l[i]; j++)
            grid[j][jy[i]+l_max-1]=1;

        FOR(a,l[i]){
            FOR(b,l[i]-a){
                grid[jx[i]+l_max-1+b][jy[i]+l_max-1 + a+1]=1;
                grid[jx[i]+l_max-1-b][jy[i]+l_max-1 - a-1]=1;
            }
        }
    }
}

//funciones A*

const int dir=4; //direcciones
const int dx[dir]={1, 0,-1, 0};
const int dy[dir]={0, 1, 0,-1};

double heuristic(int x, int y,int r, int c){
    return sqrt((x-r)*(x-r)+(y-c)*(y-c));
}

void Astar(int x_fin, int y_fin, int grid[]){


}

int main(){
    int r,c,blocked,x,y,l;
    int num_jigly;
    while(scanf("%d %d\n",&r,&c),r!=0 and c!=0){
        //armando el mapa :S
        cin>>blocked;
        int bx[blocked];
        int by[blocked];

        FOR(i,blocked)
            scanf("%d %d\n",&bx[i],&by[i]);


        cin>>num_jigly;
        int jx[num_jigly],  jy[num_jigly],  l[num_jigly];
        l_max=0;

        FOR(i,num_jigly){
            cin>>jx[i]>>jy[i]>>l[i];
            if (l_max<l[i]) l_max=l[i];
        }
        int grid_aug[r+2*l_max][c+2*l_max];

        for(int i=l_max-1;i<=l_max+r;i++){
            for(int j=l_max-1;j<=l_max+c;j++){
                if(i>=l_max and i<l_max+r and j>=l_max and j<l_max+c)
                    grid_aug[i][j]=0;
                else
                    grid_aug[i][j]=1;
            }
        }

        FOR(i,blocked)  grid_aug[bx[i]+l_max-1][by[i]+l_max-1]=1;
        expand(grid_aug,num_jigly,jx,jy,l);

        //empieza A* oh yeahh

    }


	return 0;
}
*/
