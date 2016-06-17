#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define		N	150

using namespace std;

int B[N];

void Merge(int *a, int p, int q, int r){
	int k=p,i=p;
	int j=q+1;
	
	while(i<=q && j<=r){
		if(a[i]<=a[j]){
			B[k]=a[i];
			i++;
		}else{
			B[k]=a[j];
			j++;
		}
		k++;
	}
//copiando elementos parte izq
	while(i<=q){
		B[k]=a[i];	i++;	k++;
	}
//copiando elemt parte der
	while(j<=r){
		B[k]=a[j];	j++;	k++;
	}
	for(int i=p;i<=r;i++){
		a[i]=B[i];
	}
}

void MergeSort(int *a, int p,int r){
	if(p<r){
		int q=(p+r)/2;
		MergeSort(a, p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}

int main(){
	int a[6]={10, 36, 37, 11, 9, 17};
	for(int i=0;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	MergeSort(a,0,5);
	
	for(int i=0;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
