#include<iostream>
#include<stack>
#include<string>

using namespace std;
stack<string> back, forw;

int main(){
	string command, page,current;
	string ig="Ignored";
	
	current="http://www.acm.org/";

	while(cin>>command,command!="QUIT"){
		if(command=="VISIT"){
			cin>>page;
			back.push(current);
			current=page;
			while(forw.empty()!=1)	forw.pop();
			cout<<current<<endl;

		}else if(command=="BACK"){
			if(back.empty())	cout<<ig<<endl;
			else{
				forw.push(current);
				current=back.top();
				back.pop();
				cout<<current<<endl;	
			}
		}else if(command=="FORWARD"){
			if(forw.empty())	cout<<ig<<endl;
			else{
				back.push(current);
				current=forw.top();
				forw.pop();
				cout<<current<<endl;
			}
		}
	}

	return 0;
}
