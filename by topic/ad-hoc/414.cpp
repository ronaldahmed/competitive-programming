#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
#include<stack>

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

int main(){
  int n=0;
  string s;
  vi hs;
  while(cin>>n, n!=0){
    int mm=0;
    while(n--){
      getline(cin,s);

      int l=s.sz;
      int temp=0;
      REP(i,0,l){
        if(s[i]=='x')   temp++;
      }
      mm=max(mm,temp);
      hs.pb(temp);
    }
    int cc=0;
    REP(i,0,hs.sz){
        cc+=mm-hs[i];
    }
    cout<<cc<<endl;
  }
	return 0;
}
