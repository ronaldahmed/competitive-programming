// AC WEVON!!!
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#define mp	make_pair

using namespace std;

class Point{
	public:
		double x,y;
		Point(double,double);
		void print(){
			printf("  %d %d\n",(int)x,(int)y);
		}
};
Point::Point(double _x, double _y){
	x = _x;
	y = _y;
}

class Quad{
	public:
		vector<Point> quad;
		Quad(Point,Point);
	
	};
Quad::Quad(Point P, Point O){
	int a = P.x - O.x,
	    b = P.y - O.y;
	quad.push_back(P);
	for(int i=0;i<3;++i){
		int _x = O.x - b,
		    _y = O.y + a;
		quad.push_back(Point(_x,_y));
		int temp = b;
		b = a;
		a = -temp;
	}
}


double area(vector<Point> P){
	P.push_back(P[0]);
	double area = 0.0;
	for(int i=0;i<P.size()-1;++i){
		area += P[i].x*P[i+1].y - P[i+1].x*P[i].y;
	}
	area /= 2.0;
	return fabs(area);
}

double dist2(Point p1, Point p2){
	return (p1.x-p2.x) * (p1.x-p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


double angle(Point p, Point r){
	return atan2(r.x*p.y - r.y*p.x,r.x*p.x + r.y*p.y);
}


void angularSort(Point* V){
	double cx = 0.0;
	double cy = 0.0;
	
	for (int i=0;i<4;++i){
		cx += V[i].x;
		cy += V[i].y;
	}
	cx /= 4.0;
	cy /= 4.0;
	Point r = Point(1,0);
	/*
	for(int k=0;k<4;k++){
		Point pi = Point(V[k].x - cx, V[k].y - cy);	
		printf("x y: %.2f %.2f | u:%.2f %.2f | angle: %.2f\n",V[k].x,V[k].y,pi.x,pi.y,angle(pi,r));
	}
	*/
	// Referencia Punto 1
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;++j){
			Point pi = Point(V[i].x - cx, V[i].y - cy);
			Point pj = Point(V[j].x - cx, V[j].y - cy);
			
			if( angle(pi,r) > angle(pj,r) )
				swap(V[i],V[j]);
		}
	}

}

int main() {
	int n;

	cin >> n;
	
	for (int i=0;i<n;++i){
		vector<Quad> Q;
		for(int k=0,x,y,ox,oy;k<4;k++){
			cin >> x >> y >> ox >> oy;
			Q.push_back( Quad(Point(x,y),Point(ox,oy)) );

			
		}
		/*
		for(int k=0;k<4;k++){
			printf("area:%.3f | dist: %.4f\n",area(Q[k].quad), dist2(Q[k].quad[0],Q[k].quad[1]));
			cout << "----------------" << endl;
		}
		cout <<"++++++++++++++++++++++++++++++++" << endl;
		*/
		int mn = (1<<30);
		
		for(int i1=0;i1 < Q[0].quad.size();++i1){
			for(int i2=0;i2 < Q[1].quad.size();++i2){
				for(int i3=0;i3 < Q[2].quad.size();++i3){
					for(int i4=0;i4 < Q[3].quad.size();++i4){
						Point p1 = Q[0].quad[i1];
						Point p2 = Q[1].quad[i2];
						Point p3 = Q[2].quad[i3];
						Point p4 = Q[3].quad[i4];
						Point a[4] = {p1,p2,p3,p4};
						
						angularSort(a);
						
						vector<Point> v(a, a + sizeof(a) / sizeof(a[0]));
						/*						
						bool pp = false;
						for(int k=0;k<4;k++)
							if( v[k].x==-2.0 && v[k].y==0.0 && area(v) == 0.0){
								pp=true;
								break;
							}
						
						if(pp){
							for(int k=0;k<4;k++)
								v[k].print();

							printf("area:%.1f | dist: %.1f\n",area(v), dist2(v[0],v[1]));
							cout << "----------------" << endl;
						}
						*/
						if( dist2(v[0],v[2]) == dist2(v[1],v[3]) &&		// diagonales
								dist2(v[0],v[1]) == dist2(v[1],v[2]) &&		// lados
								dist2(v[1],v[2]) == dist2(v[2],v[3]) &&
								dist2(v[3],v[0]) == dist2(v[2],v[3]) &&
								fabs(area(v) - dist2(v[0],v[1])) <= 1e-9 &&	// area = l**2
								area(v) > 0.0){															// area != 0
							mn = min(mn,i1+i2+i3+i4);
						}
					}
				}
			}
		}

		if(mn == (1<<30))
			cout << -1 << endl;
		else
			cout << mn << endl;

	}

	return 0;
}
