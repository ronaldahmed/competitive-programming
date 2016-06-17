#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	bool open=0;
	while(getline(cin,line)){
		for(int i=0;i<line.size();++i){
			if(line[i]=='"')
				if(open){
					line.erase(i,1);
//					char t[2]={(char)44,(char)44};
					line.insert(i,"''");
					open=0;
				}else{
					line.erase(i,1);
					line.insert(i,"``");
					open=1;
				}			
		}
		cout<<line<<endl;
	}
	return 0;
}
