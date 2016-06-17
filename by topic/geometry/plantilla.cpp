#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define		EPS	1e-10
#define		PI	acos(0.0)*2.0
#define		oo		(1<<30)
#define	_inline(f...)	f() __attribute__((always_inline)); f

using namespace std;
typedef long double ld;

// Funcion para comparación de doubles
_inline(int cmp)(double x,double y=0.0, double tol = EPS)
{
	/* input: doubles x,y a comparar | tolerancia
	 * output: -1: x < y | 0 : x == y | 1 : x > y
	 */
	return (x <= y+tol) ? (x + tol < y) ? -1 : 0 : 1;
}


// Punto 2D
struct point{
	// Solo usar double si es realmente necesario
	// En lo posible usar Iny
	double x,y;
	
	point(double _x = 0.0, double _y = 0.0 ) : x(_x), y(_y) {}
	
	// Operaciones
	point operator +(const point &p){	return point(x + p.x, y + p.y);	}
	point operator -(const point &p){	return point(x - p.x, y - p.y);	}
	
	//    Multiplicacion por una constante
	point operator *(double t){	return point(x * t, y * t);	}
	
	//    Division entre una constante
	point operator /(double t){	return point(x / t, y / t);	}
	
	//		Producto escalar de dos puntos
	double operator *(point q){	return x*q.x + y*q.y;	}

	//		Producto vectorial de dos puntos
	double operator %(point q){	return x*q.y - y*q.x;	}


	int cmp(point q){
		/* Descripcion: compara punto P (actual) con Q (input). Primero por x, luego por y.
		   Uso: p.cmp(q)
		   input: point
		   output: p < q : -1 | p == q : 0 | p > q : 1
		 */
		if( int t = ::cmp(x,q.x) )	return t;
		return	::cmp(y,q.y);
	}
	
	// Operadores de comparación rápida de puntos
	bool operator ==(point q) {	return cmp(q) == 0;}
	bool operator !=(point q) {	return cmp(q) != 0;}
	bool operator  <(point q) {	return cmp(q)  < 0;}
	
	// punto pivote ??? 				------------------------------------------------------------
	static point pivot;
};

point point::pivot;


///////////////////////////////////////////////////////////////////////////////////////////
// Puntos , segmentos, lineas

// Modulo de vector (0,0) -> p
double abs(point p){	return hypot(p.x,p.y);	}

// Argumento (angle) de vector (0,0) -> 
double arg(point p){	return atan2(p.y,p.x);	}

// Counterclockwise comparison
_inline(int ccw)(point p, point q, point r){
	/* input : vector RP, vector RQ
	 * output: 1,0,-1
	 * descripción: evalua si angulo (theta) de RP hacia RQ va en sentido contrario a las agujas del rejos.
	                theta CCW : 1
	                theta CW	: -1
	                theta = 0 (P,Q,R colineales): 0
	 */
	return cmp((p - r) % (q - r));
}


_inline(double angle)(point p, point q, point r){
	/* input : vector QP, vector QR
	   ouput : ángulo con signo (double)
	   descripción : devuelve ángulo entre QP y QR. CCW (+), CW (-).
	 */
	point u = p-q, v = r-q;
	return atan2( u%v,u*v );
}


_inline(double angle)(point p, point q){
	/* input : vector OP, vector OQ
	   ouput : ángulo con signo (double)
	   descripción : devuelve ángulo entre OP y OQ. CCW (+), CW (-).
	 */
	return atan2( p%q,p*q );
}


bool between(point p, point q, point r){
	/* input : segment PR, point Q
	   ouput : False (no esta en medio); True (está en medio)
	   descripción : True si Q pertenece a segmento PR. ---p----q-----r---
	                 True si P, Q y R son colineales
	 */
	return ccw(p,q,r) == 0 && cmp((p - q) * (r - q)) <= 0;
}


bool seg_intersect(point p, point q, point r, point s){
	/* input : Linea 1 (P,Q), Linea 2 (R,S)
	 * ouput : bool
	 * descripción :  True si segmento PQ se intersecta con segmento RS.
	 */
	point A = q - p,
	      B = s - r,
        C = r - p,
        D = s - q;
	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);
	// si al unir pr y qs se forma un cuadrilatero, false
	if (a == 3 || a == -3 || b == 3 || b == -3)	return false;
	// si pq esta unido a rs
	if (a || b || p == r || p == s || q == r || q == s)	return true;
	// si pq esta debajo de rs o viceversa, false
	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}


double Point2SegmentDist(point p, point q, point r){
	/* input : segment PQ, point R
	 * ouput : distancia de R a segmento PQ.
	 *         Se puede quitar <fabs>. Si Dist es (+), el punto esta encima de PQ, sino esta debajo
	 */
	point A = r - q,
	       B = r - p,
	       C = q - p;
	double a = A * A, b = B * B, c = C * C;
	if (cmp(b, a + c) >= 0)			return sqrt(a);
	else if (cmp(a, b + c) >= 0)	return sqrt(b);
	// proyección de R cae sobre PQ
	else							return fabs(A % B) / sqrt(c);
}


double Point2LineDist(point p, point q, point r){
	/* input : line PQ, point R
	 * ouput : distancia de R a linea PQ
	 *         Se puede quitar <fabs>. Si Dist es (+), el punto esta encima de PQ, sino esta debajo
	 */
	return fabs((r-p) % (q-p)) / abs(q-p);
}


bool parallel(point p, point q, point r, point s){
	/* input : line PQ, line RS
	 * ouput : True si PQ y RS son paralelas. False si no son paralelas o si son colineales
	 */
	// A partir de igualdad de pendientes
	double m = (p.x - q.x)*(s.y - r.y) - (p.y - q.y)*(s.x - r.x);
	// que no sean colineales
	if(cmp(m) == 0 && ccw(p,q,r) != 0)	return true;
	return false;
}


bool collineal(point p, point q, point r, point s){
	/* input : line PQ, line RS
	 * ouput : True si PQ y RS son colineales.
	 */
	return ccw(p,q,r) == 0 && ccw(p,q,s) == 0;
}


point line_intersect(point p, point q, point r, point s){
	/* input : line PQ, line RS
	 * ouput : punto de intersección entre PQ y RS. CONSULTAR COMO FUNCIONA xD !!!
	 					 retorna (-INF,-INF) si son paralelas o colineales
	 */
	// si es paralelo o colineal, Punto infinito
	if (parallel(p,q,r,s) || collineal(p,q,r,s))
		return point(-oo,-oo);
		
	point a = q - p,
	      b = s - r,
	      c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}


point proyect2Line(point p, point q, point r){
	/* input : Linea PQ, punto R
	 * output: punto proyectado sobre linea PQ
	 */
	point u = q - p, v = r - p;
	return p + u * ((u * v) / (u * u));
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Poligonos , Areas
typedef vector <point> polygon;

double signed_area(polygon& T){
	/* input  : poligono <vector de int>
	 * output : double area con signo
	 * descrip: Poligono simple (no se entrecruza): CCW(+), CW(-)
	 * 			Poligono no siemple, parte recorrida en CCW (+), parte en CW (-)
	 */
	double atotal = 0;
	int n = T.size();
	for(int i=0;i<T.size();++i)
		atotal += T[i] % T[(i+1)%n];
	return atotal / 2.0;
}


int in_poly(point p, polygon& T){
	/* input  : punto P, poligono T con puntos ordenados CCW o CW
	 * output : -1, 0, 1
	 * descrip: -1: punto exterior al poligono
	 * 			 0: punto en frontera
	 * 			 1: punto dentro
	 */
	double a=0;
	int n = T.size();
	for(int i=0;i<n;++i){
		if(between(T[i], p, T[(i+1)%n]))
			return -1;
		a += angle(T[i], p, T[(i+1)%n]);
	}
	return cmp(a) != 0;
}


int main(){
	point a[4] = {point(0,0),point(0,7),point(7,7),point(7,0)};
	polygon pol(a,a+4);
	
	cout << signed_area(pol) << endl;

	cout<<"::"<<in_poly(point(3,0),pol)<<endl;
	
	return 0;
}

