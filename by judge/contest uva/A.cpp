#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n,a;
	vector<int> ss,sn;
	bool ord;
	cin>>n;

	cout<<"Lumberjacks:"<<endl;
	while(n--){
		ord=true;
		int k=10;
		while(k--){
			cin>>a;
			ss.push_back(a);
			sn.push_back(a);
		}
		sort(ss.begin(),ss.end());

		int l=ss.size();
		
//for(int i=0;i<l;i++)	cout<<ss[i]<<" ";
//cout<<endl;

		
		for(int i=0;i<l;i++){
			if(ss[i]!=sn[i]){ ord=false; break;}
		}

		if(!ord){
			ord=true;
			for(int i=0;i<l/2;i++){
				swap(ss[i],ss[l-1-i]);
			}
//for(int i=0;i<l;i++)	cout<<ss[i]<<" ";
//cout<<endl;

			for(int i=0;i<l;i++){
				if(ss[i]!=sn[i]){ ord=false; break;}
			}	
			if(!ord)	cout<<"Unordered";
			else		cout<<"Ordered";
		}else	cout<<"Ordered";
		
		cout<<endl;
				
		ss.clear();
		sn.clear();
	}

	return 0;
}
