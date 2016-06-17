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
vector<pair<int,char> >    k,e;
string known,encode;
int k_size, e_size;

char correspond(int a){
    int l=e.size();
    int interv_apunt=0;
    if(a<97)    a+=32;

    vector<int> interval;
    interval.push_back(0);

    for(int i=1;i<l;i++){
        if(e[i].first!=e[i-1].first)    interval.push_back(i);
    }

    for(int i=0;i<l;i++){
        //caso F =1
        if(interval[interv_apunt]+1==interval[interv_apunt+1]){
            if(a==e[i].second)  return k[i].second;
        }

    }
}

int main(){

	int count[60];
	for(int i=0;i<60;i++)   count[i]=0;

	getline(cin,known);
	scanf("\n");
	getline(cin,encode);

    k_size=known.size();
    e_size=encode.size();
    int temp;

    for(int i=0;i<k_size;i++){
        temp=known[i];
        if(isalpha(temp)){
            if(temp<97)     temp-=32;
            count[temp-'A']++;
        }
    }
    for(int i=0;i<60;i++){
        if(count[i]!=0)         k.push_back(make_pair(count[i],i+'A'));
    }

	for(int i=0;i<60;i++)       count[i]=0;
    for(int i=0;i<e_size;i++){
        temp=encode[i];
        if(isalpha(temp)){
            if(temp<97)     temp-=32;
            count[temp-'A']++;
        }
    }
    for(int i=0;i<60;i++){
        if(count[i]!=0)         e.push_back(make_pair(count[i],i+'A'));
    }
    sort(k.begin(),k.end());
    sort(e.begin(),e.end());

    for(int i=0;i<e_size;i++){
        temp=encode[i];
        if(isalpha(temp)){
            if(temp<97)     temp-=32;


        }else       cout<<(char)temp;
    }
	return 0;
}
