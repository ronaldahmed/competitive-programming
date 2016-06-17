#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char grid[5][5];
int row[5][2];
int res,n;

bool can(int r,int i){
    for(int k=r-1;k>=0;k--){
        if(grid[k][i]=='X')                 return 1;
        if(row[k][0]==i || row[k][1]==i)    return 0;        
    }
    return 1;
}

void backtrack(int r, int blocks){
    if(r==n){
        res=max(res,blocks);
        return;
    }

    bool x=0,prev=0;
    for(int i=0;i<n;++i){
        if(grid[r][i]=='.'){
            if(can(r,i)){
                if(x and prev){
                    x=0; prev=0;
                    if(row[r][0]<i){
                        row[r][1]=i;
                        backtrack(r+1,blocks+2);
                    }
                }else{
                    if(!x)  prev=1;
                    row[r][0]=i;
                    row[r][1]=-1;
                    backtrack(r+1,blocks+1);
                }
            }
        }else if(prev)
            x=1;
    }
    backtrack(r+1,blocks);
}

int main(){
    while(cin>>n,n!=0){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)    cin>>grid[i][j];

//        for(int i=0;i<n;++i){
//            for(int j=0;j<n;++j)    cout<<grid[i][j]; cout<<endl;}

        memset(row,-1,sizeof row);
        res=0;
        backtrack(0,0);
        printf("%d\n",res);
    }
    return 0;
}
