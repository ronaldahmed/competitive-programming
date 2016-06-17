#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define		N	150
#define	F(x,i)	(x[i]).first
#define	S(x,i)	(x[i]).second

using namespace std;

vector<pair<int,string> >	dna;
int		B[N];
string	S[N];

int uns(string s,int n){
	int c=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]>s[j])	c++;
		}
	}
	return c;
}

void Merge(int p, int q, int r){
	int k=p,i=p;
	int j=q+1;
	
	while(i<=q && j<=r){
		if(F(dna,i)<=F(dna,j)){
			B[k]=F(dna,i);
			S[k]=S(dna,i);
			i++;
		}else{
			B[k]=F(dna,j);
			S[k]=S(dna,j);
			j++;
		}
		k++;
	}
//copiando elementos parte izq
	while(i<=q){
		B[k]=F(dna,i);
		S[k]=S(dna,i);
		i++;	k++;
	}
//copiando elemt parte der
	while(j<=r){
		B[k]=F(dna,j);
		S[k]=S(dna,j);
		j++;	k++;
	}

	for(int i=p;i<=r;i++){
		F(dna,i)=B[i];
		S(dna,i)=S[i];
	}
}

void MergeSort(int p,int r){
	if(p<r){
		int q=(p+r)/2;
		MergeSort(p,q);
		MergeSort(q+1,r);
		Merge(p,q,r);
	}
}

int main(){
	int n,m;
	string d;
	cin>>n>>m;
//cout<<n<<" "<<m<<endl;

	while(m--){
		cin>>d;
		int us=uns(d,n);
		dna.push_back(make_pair(us,d));
	}
	m=dna.size();
//for(int i=0;i<m;i++)
//	cout<<F(dna,i)<<" "<<S(dna,i)<<endl;

	MergeSort(0,m-1);

for(int i=0;i<m;i++)
	cout<<S(dna,i)<<endl;

	return 0;
}
