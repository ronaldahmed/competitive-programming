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

bool palindrome(int hora, int mins){
    int h1=hora/10;
    int h2=hora%10;
    int m1=mins/10;
    int m2=mins%10;
    if(h1==0 and h2!=0 and h2==m2)            return false;
    if(hora==0 and m1==0 and m2<10)           return false;
    if(hora==0 and mins>9 and mins%11==0)     return false;
    if(h1==m2 && h2==m1 and h1!=0)            return false;

    return true;
}

int main(){
    int n,hora,mins;
    cin>>n;

    while(n--){
        scanf("%d:%d\n",&hora,&mins);

        for(int i=0;;i++){
            if( palindrome(hora,mins) or i==0){
/*                if(hora%10>5 and (hora/10)>0){
                   hora=0;
                   mins=0;
                   break;
                }
*/
                mins=(mins+1)%60;
                if(mins==0) hora=(hora+1)%24;
            }else break;

        }

        if(hora<10) cout<<"0";
        cout<<hora<<":";
        if(mins<10) cout<<"0";
        cout<<mins<<endl;

    }

	return 0;
}
