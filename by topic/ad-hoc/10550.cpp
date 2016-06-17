#include <cstdio>

int main(){
	int ini,a,b,c;
	
	while(scanf("%d %d %d %d\n",&ini,&a,&b,&c),ini || a || b || c){
		int total = 360*2 + (a<ini?(ini-a)*9:(40-a+ini)*9) + 360 + (c<b?(b-c)*9:(b+40-c)*9)
					+ ( b>a?(b-a)*9:(40-a+b)*9 );
		printf("%d\n",total);
	}
	return 0;
}
