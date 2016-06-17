#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 1<<30
#define REP(i,x,y)	for(int i=x;i<y;++i)

using namespace std;
int x1_min=0, y1_min=0;
int x2_min=0, y2_min=0;

void merge(int P[][2], int p, int q, int r, int opc)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1][2], R[n2+1][2];
	REP(i,0,n1){
		L[i][0]=P[i+p][0];
		L[i][1]=P[i+p][1];
	}
	REP(i,0,n2){
		R[i][0]=P[i+q+1][0];
		R[i][1]=P[i+q+1][1];
	}
	L[n1][opc]=INF; R[n2][opc]=INF;
	int i=0, j=0;
	REP(k,p,r+1)
		if(L[i][opc]<=R[j][opc]){
			P[k][0]=L[i][0];
			P[k][1]=L[i][1];
			++i;
		}else{
			P[k][0]=R[j][0];
			P[k][1]=R[j][1];
			++j;
		}
}

void mergeSort(int P[][2], int p, int r, int opc)
{
	if(p<r){
		int q=(p+r)/2;
		mergeSort(P,p,q,opc);
		mergeSort(P,q+1,r,opc);
		merge(P,p,q,r,opc);
	}
}

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int disMin(int Px[][2],int Py[][2], int p,int r)
{
	if(r-p+1<=4){
		double minD=INF;
		REP(i,p,r+1){
			REP(j,p,r+1){
				if(i!=j){
					double temp=dist(Px[i][0],Px[i][1],Px[j][0],Px[j][1]);
					if(temp<minD){
						minD=temp;
						x1_min=Px[i][0];
						x2_min=Px[i][0];
						y1_min=Px[i][1];
						y2_min=Px[i][1];
					}

					x1_min=Px[r][0];
					x2_min=Px[p][0];
					y1_min=Px[r][1];
					y2_min=Px[p][1];

				}
			
			}
		}
	}else{

	}
}

int main()
{
	int Px[6][2]= {1,5,
						-3,2,
						5,9,
						3,0,
						1,-9,
						10,5};
	int Py[6][2]= {1,5,
						-3,2,
						5,9,
						3,0,
						1,-9,
						10,5};

	mergeSort(Px,0,5,0);
	mergeSort(Py,0,5,1);

	REP(i,0,6)	cout<<Px[i][0]<<" "<<Px[i][1]<<endl;
	cout<<endl;
	REP(i,0,6)	cout<<Py[i][0]<<" "<<Py[i][1]<<endl;

	return 0;
}
