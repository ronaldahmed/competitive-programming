#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	int n,temp,t2,cur,maxc=0;

	cin>>n;

	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	maxc=0;
	cin>>temp;
	cur=0;
	int ind=-1,cur_ix=0;
	for(int i=1;i<n;++i){
		cin>>t2;
		cur++;	

		if(t2<temp){
			temp=t2;

//			cout<<"changed to temp:"<<temp<<endl;

			if(maxc<cur){
				maxc=cur;
				ind=cur_ix;
//				cout<<"changed to i:"<<cur_ix<<endl;
			}
			cur=1;
			cur_ix=i;
		}
	}

	if(maxc<cur){	ind=cur_ix; maxc=cur;}

//	cout<<maxc<<endl;
	cout<<ind+1<<endl;
	return 0;
}
