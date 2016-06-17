#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int t;
    long long n;

    scanf("%d\n",&t);
    while(t--){
        priority_queue<long long> q;
        long long temp;
        scanf("%lld\n",&n);
        for(int i=0;i<n;++i)    scanf("%lld",&temp),q.push(-temp);
        long long res=0LL;

        while(!q.empty()){
            if(q.size()==1){
                res+=(-q.top());
                q.pop();
                break;
            }
            int a,b;
            a=-q.top();
            q.pop();
            b=-q.top();
            q.pop();
            res+=(a+b);
            if(q.size()!=0)     q.push(-a-b);
        }

        printf("%lld\n",res);

    }
    return 0;
}
