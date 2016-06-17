#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define	MAXN	1000010
#define	N	350
#define	REP(i,x,y)	for(int i=x;i<y;++i)

using namespace std;

struct RSQ2 {
    int a[N * 2][N * 2];
    RSQ2()
    {
        memset(a, 0, sizeof(a));
    }
 
    void Add(int posX, int posY, int dx)
    {
        for (int i = posX + N; i; i >>= 1)
            for (int j = posY + N; j; j >>= 1)
                a[i][j] = dx;
    }
 
 
    int Sum(int Lx, int Rx, int Ly, int Ry) const
    {
        int res = 0;
        for (Lx += N, Rx += N; Lx < Rx; Lx >>= 1, Rx >>= 1) {
            if (Lx & 1) {
                int tLy = Ly;
                int tRy = Ry;
                for (tLy += N, tRy += N; tLy < tRy; tLy >>= 1, tRy >>= 1) {
                    if (tLy & 1)
//                        res += a[Lx][tLy++];
								res=max(res,a[Lx][tLy++]);
                    if (tRy & 1)
//                        res += a[Lx][--tRy];
                        res=max(res,a[Lx][--tRy]);
                }
                Lx++;
            }
            if (Rx & 1) {
                --Rx;
                int tLy = Ly;
                int tRy = Ry;
                for (tLy += N, tRy += N; tLy < tRy; tLy >>= 1, tRy >>= 1) {
                    if (tLy & 1)
//                        res += a[Rx][tLy++];
                        res=max(res,a[Rx][tLy++]);
                    if (tRy & 1)
//                        res += a[Rx][--tRy];
                        res=max(res,a[Rx][--tRy]);
                }
            }
        }
        return res;
    }
};
 
void Build(int L, int R, int *res) {
    int resc = 0;
    for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
        if (L & 1)
            res[resc++] = L++;
        if (R & 1)
            res[resc++] = --R;
    }
    res[resc] = -1;
}
 
struct RSQ22 {
    int a[N * 2][N * 2];
    RSQ22()
    {
        memset(a, 0, sizeof(a));
    }
 
    void Add(int posX, int posY, int dx)
    {
        for (int i = posX + N; i; i >>= 1)
            for (int j = posY + N; j; j >>= 1)
                a[i][j] = max(a[i][j],dx);
    }
 
    int Sum(int Lx, int Rx, int Ly, int Ry) const
    {
        int res = 0;
        static int x[142];
        static int y[142];
        Build(Lx, Rx, x);
        Build(Ly, Ry, y);
        for (int i = 0; x[i] != -1; ++i)
            for (int j = 0; y[j] != -1; ++j)
                res =max(res,a[x[i]][y[j]]);
        return res;
    }
};

int mat[N][N];

int main(){
	int n, m,temp,q; scanf("%d %d\n",&n,&m);
	RSQ22	rsq;
	REP(i,0,n)	REP(j,0,m)	scanf("%d ",&temp), rsq.Add(i,j,temp), mat[i][j]=temp;		
		
	int r1,r2,c1,c2;
	scanf("%d\n",&q);
	while(q--){
		scanf("%d %d %d %d\n",&r1,&c1,&r2,&c2);
		int mx=rsq.Sum(r1-1,r2,c1-1,c2);
		if(mat[r1-1][c1-1]==mx || mat[r2-1][c1-1]==mx || mat[r1-1][c2-1]==mx || mat[r2-1][c2-1]==mx)
			printf("%d yes\n",mx);
		else
			printf("%d no\n",mx);
	}	
	return 0;
}
