#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;
string heap[100];
int heap_size = 0;

stack<string> joinStacks(stack<string> current,string* heap){
	printf("cur:%d  -  heap:%d\n",current.size(),heap_size);

	stack<string> temp,res;
	for(int i=heap_size-1;i>=0;i--)
//	for(int i=0;i<heap_size;++i)
		res.push(heap[i]);
	
	while(!current.empty()){
		temp.push(current.top());
		current.pop();
	}
	while(!temp.empty()){
		res.push(temp.top());
		temp.pop();
	}
	return res;
}

int main(){
	string a;
	
	while(cin>>a, a[0]!='#'){
		// 0: dealer | 1: non-dealer
		stack<string> players[2];
		heap_size = 0;
		players[1].push(a);
		
		for(int i=1;i<52;++i){
			cin>>a;
			if(i&1)
				players[0].push(a);
			else
				players[1].push(a);
		}
		
		int id = 1, veces = 0;
		int id_join = -1;
		bool reset = true;
		
		while(!players[id].empty()){
			printf("player: %d | heap:%s | id_join:%d\n",id,heap_size==0?"-":heap[heap_size-1].c_str(),id_join);

			if(id_join!=-1 && !reset){
				players[id_join] = joinStacks(players[id_join],heap);
				heap_size = 0;
				id = id_join;
				id_join = -1;
			}
		
			if(heap_size==0)
				veces = 1;
			else if(heap[heap_size-1][1]=='Q')
				veces = 2;
			else if(heap[heap_size-1][1]=='K')
				veces = 3;
			else if(heap[heap_size-1][1]=='A')				
				veces = 4;
			else
				veces = 1;
				
			string cur;
			reset = false;
			
			for(int i=0;i<veces;++i){
				if(players[id].empty()){
					id = (id+1)%2;
					break;
				}
				cur = players[id].top();
				heap[heap_size++] = cur;
				
				players[id].pop();
				if(cur[1]=='J' || cur[1]=='Q' || cur[1]=='K' || cur[1]=='A'){
					id_join = id;
					reset = true;
					break;
				}
			}
			id = (id+1)%2;
		}
		id = (id+1)%2;

		printf("%d%3d\n",id+1,players[id].size());
	}
	return 0;
}
