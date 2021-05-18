#include<iostream>
#include"adjList.cpp"
using namespace std;
int main(){
	int n ,e ,c=0;
	cout<<"input node number\n";
	cin>>n;
	
	if(c == 0){
		adjMatrix a1(n); 
		int num = combination(n ,2)/2;
	
		cout<<"Here is adjMatrix ,input edge less than "<<num<<endl;
		cin>>e;
		a1.set(n ,e);
		while(e > num){
			cout<<"your edge is bigger than "<<num<<" plese input again\n";
			cin>>e;
			a1.set(n ,e);
			//b1.start_E(n ,e);
		}
		
		a1.out();
		
		cout<<"dfs:";
		a1.dfs(0);
		cout<<endl;
		cout<<"bfs:";
		a1.bfs(0);	
	}
	else{
		adjList b1;
		b1.start(n);
		
		int num = combination(n ,2)/2;
		cout<<"Here is adjList ,input edge less than "<<num<<endl;
		cin>>e;
		b1.start_E(n ,e);
		while(e > num){
			cout<<"your edge is bigger than "<<num<<" plese input again\n";
			cin>>e;
			b1.start_E(n ,e);
		}
		
		b1.set();
		b1.PrintList();
		cout<<"dfs:\n";
		b1.dfs(1);
		cout<<endl<<"bfs:\n";
		b1.bfs(1);
	}
	
	
	
	
	return 0;
}
