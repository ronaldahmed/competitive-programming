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

int main(){
    int n,total,m,show;
    int pass;
    cin>>n;
    while(n--){
        show=0;
        scanf("%d %d\n",&total,&m);
        while(1){
            pass=total/m;
            show+=pass;
            total=total-pass*(m-1);
            if(total<m){
                if(total!=1) show=0;
                break;
            }
        }
        if(show==0)     cout<<"cannot do this"<<endl;
        else            cout<<show<<endl;
    }
	return 0;
}
