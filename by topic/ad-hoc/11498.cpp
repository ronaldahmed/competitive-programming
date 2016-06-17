#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int t,x,y,dx,dy;
	while(scanf("%d\n",&t),t){
		scanf("%d %d\n",&dx,&dy);
		for(int i=0;i<t;++i){
			scanf("%d %d\n",&x,&y);
			if(x==dx || y==dy)		printf("divisa\n");
			else if(x<dx and y>dy)	printf("NO\n");
			else if(x>dx and y>dy)	printf("NE\n");
			else if(x>dx and y<dy)	printf("SE\n");
			else if(x<dx and y<dy)	printf("SO\n");
		}
	}
	return 0;
}
