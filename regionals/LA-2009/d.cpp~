#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<int,char> > cards;

int main(){
	int n;
	string s;
	while(scanf("%d\n",&n), n){
		cards.clear();
		
		int in=0, out=0;
		for(int i=0,h,m,seg;i<n;++i){
			getline(cin,s);
			h = s[0]*10+s[1];
			m = s[3]*10+s[4];
			seg = s[6]*10+s[7];
			
			if(s[9]=='E')	in++;
			if(s[9]=='X')	out++;
			
			cards.push_back(make_pair( h*3600 + m*60 + seg, s[9] ));
		}
		sort(cards.begin(), cards.end());

//cout<<cards[n-1].second<<endl;

		if(cards[0].second == '?')			cards[0].second = 'E', in++;
		if(cards[n-1].second == '?')		cards[n-1].second = 'X', out++;
		int curr=0,mx=0;
		
		for(int i=0;i<n;++i){
			switch( cards[i].second ){
				case 'E':	curr++;
								mx = max(curr,mx);
								break;
				case 'X':	curr--;
								mx = max(mx,curr);
								break;
				case '?':	if(mx < n/2 && in < n/2)	curr++,in++;
								else								curr--;
//cout<<"cur: "<<curr<<" 	"<<i<<endl;
								mx = max(mx,curr);
								break;
				default:
								break;
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}
