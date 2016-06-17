#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

int dsig[12][2];
int dsigb[12][2];
string signo[12];

bool bis=false;

int toi(string a){
	int it;
	stringstream  ss;
	ss<<a;
	ss>>it;
	return it;
}

bool bisiesto(int a){
	return (( (a%100!= 0)  || (a%400==0) ) && (a%4==0));
}

int cifras(int a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s.size();
}

string sig(int dd, int im);
bool   busca(int ,int);

int main(){
	int n,d,m,a;
	string s;

	
	dsig[0][0]=21;			dsig[0][1]=31;
	dsig[1][0]=51;			dsig[1][1]=59;
	dsig[2][0]=80;			dsig[2][1]=90;
	dsig[3][0]=110;			dsig[3][1]=120;
	dsig[4][0]=142;			dsig[4][1]=151;
	dsig[5][0]=173;			dsig[5][1]=181;
	dsig[6][0]=204;			dsig[6][1]=212;
	dsig[7][0]=234;			dsig[7][1]=243;
	dsig[8][0]=267;			dsig[8][1]=273;
	dsig[9][0]=297;			dsig[9][1]=304;
	dsig[10][0]=327;		dsig[10][1]=334;
	dsig[11][0]=357;		dsig[11][1]=365;
	
	for(int i=0;i<12;i++){
		dsigb[i][0]=dsig[i][0];
		dsigb[i][1]=dsig[i][1];
	}
	dsigb[1][1]=60;
	
	for(int i=2;i<12;i++){
		dsigb[i][0]++;
		dsigb[i][1]++;
	}
	
	signo[0]="aquarius";
	signo[1]="pisces";
	signo[2]="aries";
	signo[3]="taurus";
	signo[4]="gemini";
	signo[5]="cancer";
	signo[6]="leo";
	signo[7]="virgo";
	signo[8]="libra";
	signo[9]="scorpio";
	signo[10]="sagittarius";
	signo[11]="capricorn";
	
	int mes[12];
	mes[0]=31;
	mes[1]=28;
	mes[2]=31;
	mes[3]=30;
	mes[4]=31;
	mes[5]=30;
	mes[6]=31;
	mes[7]=31;
	mes[8]=30;
	mes[9]=31;
	mes[10]=30;
	mes[11]=31;
	
	scanf("%d\n",&n);
	
	int sm;
	int dactual,dias;
	int j=1;
	int t;
	int ca;
	
	while(n--){
		sm=0;
		bis=false;
		getline(cin,s);
		m=toi(s.substr(0,2))-1;
		d=toi(s.substr(2,2));
		a=toi(s.substr(4,4));
		
		//modificar si es bisciesto
		if(bisiesto(a)){
			bis=true;
			t=366;
			mes[1]=29;
		}else{
			mes[1]=28;
			t=365;
		}

		for(int i=0;i<m;i++)	sm+=mes[i];

		int dtotal=d+sm+280;
		int i;
//	cout<<dtotal<<" "<<t<<endl;
		if(dtotal!=t){
			dactual=(dtotal)%t;
		
			if((dtotal)/t!=0 ){
				a++;
				if(bisiesto(a)){
					bis=true;
					mes[1]=29;
				}else{
					mes[1]=28;
					bis=false;
				}
			}
			i=0;
			ca=cifras(a);
			dtotal=dactual;
			while(dactual>mes[i]) {	dactual-=mes[i]; i++;  }
		}else{
			dactual=31; i=11;
		}
		
		cout<<j++<<" ";
		if(i+1<10)			printf("0%d/",i+1);
		else				printf("%d/",i+1);
		if(dactual<10)		printf("0%d/",dactual);
		else				printf("%d/",dactual);

		for(int i=0;i<(4-ca);i++)
			printf("0");

		cout<<a<<" "<<sig(dtotal,i)<<endl;

	}
		
	return 0;
}

bool busca(int i,int dd){
	if(bis){
		if( dd>=dsigb[i][0] && dd<=dsigb[i][1] )	return true;
		else										return false;

	}else{
		if( dd>=dsig[i][0] && dd<=dsig[i][1] )	return true;
		else									return false;
	}
}

string sig(int dd, int i){
	if(i==0){
		if(busca(i,dd))	return signo[i];
		else			return signo[11];
	}else{
		if(busca(i,dd))	return signo[i];
		else			return signo[i-1];
	}
}

