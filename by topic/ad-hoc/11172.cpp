#include <cstdio>

using namespace std;

int main(){
	int t,a,b;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d\n",&a,&b);
		if(a<b)			printf("<\n");
		else if(b<a)	printf(">\n");
		else				printf("=\n");
	}
	return 0;
}
