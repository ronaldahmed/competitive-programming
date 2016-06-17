#include<iostream>
#include<string>

using namespace std;

int main(){
/*	string s1="1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu51PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu51KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5";
	string ss1="*CDC is the trademark of the Control Data Corporation.*IBM is a trademark of the International Business Machine Corporation.*DEC is the trademark of the Digital Equipment Corporation.";

	char trad[200];
	int l=s1.size();
	
	for(int i=0;i<l;i++){
		trad[(int)s1[i]]=ss1[i];
	}
	for(int i=0;i<200;i++)	cout<<trad[i]<<" ";
*/
	string sin;

	while(getline(cin,sin)){
		int ll=sin.size();
		for(int i=0;i<ll;i++)	cout<<(char)(sin[i]-7);
		cout<<endl;
	}
	return 0;
}
