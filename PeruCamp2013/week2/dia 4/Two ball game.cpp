#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define eps 1e-7

struct point{
    double x,y;
    
    point(){}
    point(double _x, double _y):
        x(_x), y(_y){}
    
    bool operator < (point P)const{
        if(abs(x - P.x) > eps) return x < P.x;
        return y < P.y;
    }
};

vector<point> P;

double area(point a, point b, point c){
    return (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

bool cross(point a, point b, point c, point d){
    return area(a,c,b) * area(a,b,d) > 0 && area(c,b,d) * area(c,d,a) > 0;
}

vector<point> convex_hull(vector<point> &P){
    int n = P.size();
    sort(P.begin(),P.end());
    
    point H[2 * n];
    int sz = 0;
    
    for(int i = 0;i < n;++i){
        while(sz >= 2 && area(H[sz - 2],H[sz - 1],P[i]) < 0) --sz;
        H[sz++] = P[i];
    }
    
    for(int i = n - 1,t = sz;i >= 0;--i){
        while(sz > t && area(H[sz - 2],H[sz - 1],P[i]) < 0) --sz;
        H[sz++] = P[i];
    }
    
    return vector<point>(H,H + sz);
}

bool on(vector<point> &P, point X){
    int n = P.size();
    
    for(int i = 0;i < n;++i)
        if(fabs(P[i].x - X.x) < eps && fabs(P[i].y - X.y) < eps)
            return true;
    
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    
    int T,n;
    double x,y;
    
    cin >> T;
    
    while(T--){
        cin >> n;
        
        P.clear();
        
        for(int i = 0;i < n;++i){
            cin >> x >> y;
            P.push_back(point(x,y));
        }
        
        point s0 = P[0],t0 = P[1],s1 = P[2],t1 = P[3];
        
        if(!cross(s0,t0,s1,t1)) cout << "POSSIBLE\n";
        else{
            vector<point> H = convex_hull(P);
            
            if(!on(H,s0) || !on(H,s1) || !on(H,t0) || !on(H,t1)) cout << "POSSIBLE\n";
            else cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}
