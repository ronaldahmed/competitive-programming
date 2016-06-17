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

using namespace std;
string line;
int hant=0,hac=0;

struct TreeNode{
    int key;
    TreeNode *right;
    TreeNode *left;
    TreeNode *pat;
};

void traslate(TreeNode*,int);
int toi(string);

int main(){
	freopen("112.in","r",stdin);
	//freopen("112.out","w",stdout);

    while(getline(cin,line)){

        TreeNode* A=(TreeNode*)malloc(sizeof(TreeNode));
        traslate(A,1);
        cout<<(A->key)<<endl;
    }

	return 0;
}
int toi(string s){
    stringstream ss;
    int n;
    ss<<s;
    ss>>n;
    return n;
}

void traslate(TreeNode* A,int r){
    if(r==(line.size()-1) )     return;
    if(line[r]==')')            traslate(A->pat,r+1);

    int f=r;

    while(isdigit(line[f])) f++;

    if(line[r]=='('){
        if(f==r+1){
            if(line[r-1]==')'){
                A->right=NULL;
                traslate(A->pat,f+1);
            }else
                A->left=NULL;
        }else{
            int data=toi(line.substr(r,f-r));
                A->key=data;
            if(line[r-1]==')')
                A->right=A;
            else
                A->left=A;
        }
    }
    traslate(A,f+1);

}
