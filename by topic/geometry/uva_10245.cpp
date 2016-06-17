#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cfloat>
#define	 xx		first
#define	 yy		second

using namespace std;

typedef pair<double,double> pdd;

const int maxn = 10100;
const double eps = 1e-9;

pdd P[maxn];
int n, Y[maxn];


bool xcomp(pdd a, pdd b){	return a.xx < b.xx;	}
bool ycomp(int a, int b){	return P[a].yy < P[b].yy;	}


double dist(pdd p1, pdd p2)
{
	return (p1.xx-p2.xx)*(p1.xx-p2.xx) + (p1.yy-p2.yy)*(p1.yy-p2.yy);
}


double closestPair(int l, int r,int* Ycurr, int ysize)
{

	if(r-l<=2){
		double ans = DBL_MAX;
		for(int i=l;i<=r;++i)
			for(int j=i+1;j<=r;++j)
				ans = min(ans,dist(P[i],P[j]));
		
		return ans;
	}
		
	int mid = (r+l)>>1;
	int Yleft[ysize];
	int Yright[ysize];
	int yl=0, yr=0;

	// divide
	for(int i=0;i < ysize;++i){
		int id = Ycurr[i];
		if(P[id].xx <= P[mid].xx)
			Yleft[yl++] = id;
		else
			Yright[yr++] = id;
	}

	// conquer
	double left  = closestPair(l    ,mid,Yleft ,yl);
	double right = closestPair(mid+1,r  ,Yright,yr);
	double delta = min(left,right);
	
	// combine
	int Yh[ysize+1];
	int yhc = 0;

	for(int i=0;i<ysize;++i){
		int id = Ycurr[i];
		if(fabs(P[id].xx-P[mid].xx) < delta)
			Yh[yhc++] = id;
	}
	
	for(int i=0;i<yhc;++i)
	{
		for(int j=i+1;j<min(yhc,i+8) ;++j){
			pdd p1 = P[Yh[i]];
			pdd p2 = P[Yh[j]];
			delta = min(delta, dist(p1,p2) );
		}
	}
		
	return delta;
}


int main()
{
	while(scanf("%d",&n),n){
		for(int i=0;i<n;++i)
		{
			double x,y;
			scanf("%lf %lf",&x,&y);
			Y[i] = i;
			P[i] = make_pair(x,y);
		}
		if(n==1){
			printf("INFINITY\n");
			continue;
		}
		sort(P,P+n,xcomp);
		sort(Y,Y+n,ycomp);
		
		double min_dist = sqrt(closestPair(0,n-1,Y,n));
		
		if(10000.0-min_dist > eps)
			printf("%.4lf\n",min_dist);
		else
			printf("INFINITY\n");
	}
	return 0;
}
