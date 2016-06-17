#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int main(){
	int n;
	scanf("%d\n",&n);
	printf("%d\n",n);
	string haab[19]={"pop", "no", "zip", "zotz",
                 "tzec", "xul", "yoxkin", "mol", "chen",
				 "yax", "zac", "ceh", "mac", "kankin",
				"muan", "pax", "koyab", "cumhu", "uayet"};

	string tz[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi",
 			   "manik", "lamat", "muluk", "ok", "chuen", "eb",
			   "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int dh,ah,dt,at,ndt;
	string mh;
	while(n--){
		dt=0;
		scanf("%d. ",&dh);
		cin>>mh>>ah;

		int i=0;
		while(haab[i]!=mh){
			i++;
		}

		dt=ah*365 + dh+1+ i*20;
		if(dt%260==0){
			at=dt/260-1;
			dt-=260;
			ndt=19;
		}else	at=dt/260;
		dt=dt%260;
//cout<<"dt: "<<dt<<endl;
		if(dt%20==0){
			ndt=19;
		}else			ndt=dt%20-1;

		dt%13!=0?(dt=dt%13):(dt=13);
		
		cout<<dt<<" "<<tz[ndt]<<" "<<at<<endl;

	}
	return 0;
}
