#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#define     _USE_MATH_DEFINES
#define     pi      M_PI

#define  F(a,i)     a[i].first
#define  S(a,i)     a[i].second
using namespace std;
double det(double a, double b, double c,double d){
    return (a*d - b*c);
}

int main(){
	int n,length;
	double x,y,tpoly;
	double r,t;
	vector<double>     px,py;

    while(cin>>n,n!=0){

        double area,vol=0.0;
        while(n--){
            area=0.0;
            cin>>tpoly;
            cin>>x>>y;
            px.push_back(x);
            py.push_back(y);

            do{
                cin>>x>>y;
                px.push_back(x);
                py.push_back(y);
            }while(px[0]!=x or py[0]!=y);
            length=px.size();

            for(int i=1;i<length;i++){
                area+=det(px[i-1],py[i-1],px[i],py[i])+1e-10;
            }
            area=abs(area/2.0);
            vol+=area*tpoly;
            px.clear();
            py.clear();
        }
        cin>>r>>t;
        cout<<(int)(vol/(pi*r*r*t))<<endl;

    }
	return 0;
}
