#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <cstdio>

using namespace std;
set<int>    primes;
int n;
vector<vector<int> >   memo[20];

bool can(int x,vector<int> cad){
    for(int i=0;i<cad.size();++i)
        if(cad[i]==x)  return 0;        
    return 1;        
}

void backtrack(int u,vector<int> cad){
    int lt=cad.size();

//        for(int i=0;i<cad.size();++i)   cout<<cad[i]<<" ";
//cout<<endl;

    if(u>=n){
//cout<<"last"<<endl;
        if(primes.find(cad.back()+1)!=primes.end() )
            memo[n].push_back(cad);
        return;
    }


    for(int i=2;i<=n;++i){
        if(can(i,cad) and primes.find(i+cad.back() )!=primes.end() ){
//cout<<"in: "<<i<<"  ult: "<<cad.back()<<"  u: "<<u<<endl;
//cout<<"---------"<<endl;
            vector<int> temp(cad);
            temp.push_back(i);
            backtrack(u+1,temp);
        }
    }
//cout<<"end"<<endl;
}

int main(){
    int caso=0;
    primes.insert(2);
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    primes.insert(23);
    primes.insert(29);
    primes.insert(31);
    primes.insert(37);

    while(cin>>n){
        if(memo[n].size()==0){
//            memset(used,-1,sizeof used);
            vector<int> t(1,1);
            backtrack(1,t);
        }
        printf("Caso %d:\n",++caso);
        int nn=memo[n].size();
        for(int i=0;i<nn;++i)
            for(int j=0;j<memo[n][i].size();++j){
                cout<<memo[n][i][j];
                if(j<memo[n][i].size()-1)   cout<<" ";
                else                        cout<<endl;
            }
/*        for(int i=0;i<nn;+i){
            int li=memo[n][i].size();
            for(int j=0;j<li;++j){
                cout<<memo[n][i][(li-j)%li];
                if(j<li-1)   cout<<" ";
                else         cout<<endl;
            }
        }
*/
        cout<<endl;
    }
    return 0;
}
