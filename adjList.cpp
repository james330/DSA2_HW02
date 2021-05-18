#include<iostream>
#include <stdlib.h> 
#include <time.h>
#include"adjMatrix.cpp"

using namespace std;

class adjNode{
	private:
		int data;
		int pos;
		adjNode *next;
		adjNode *edge;
	public:
		adjNode():data(0) ,next(0) ,edge(0){};
		adjNode(int a):data(a) ,next(0) ,edge(0){};
	
		friend class adjList;
};

class adjList{
	private:
		adjNode *first;
		int *visited;
		int *visit;
		int  **list;
		int num;
		int detc;
	public:
		adjList():first(0){};
		void start(int x);
		void start_E(int n ,int e);
		void PrintList();
		void Push_N(int x);
		void Push_E(adjNode *now ,int x);
		
		void set();
		void dfs(int v);
		void ddfs(int v);
		void bfs(int v);
		void bbfs(int v);
		
		~adjList();
		
};

void adjList::start(int x){
	num = x;
	ti =0;
	t=0;
	detc = 0;
	q=0;
	qq=0;
	
	sta = new int [x];
	nst = new int [x];
	que = new int [x];
	
	list = new int*[x];
	visited = new int [x];
	visit = new int[x];
	for(int i=0 ;i<x ;i++)
		visited[i]=0;
	
	for(int i=0 ;i<x ;i++)
		visit[i]=0;
		
	for(int i=0 ;i<x ;i++)
		list[i] = new int [x];
	
	for(int i=1 ;i<=x ;i++)
		Push_N(i);
		
	for(int i=0 ;i<num ;i++)
		for(int j=0 ;j<num ;j++){
			list[i][j] = 0;
		}	
	
}

void adjList::start_E(int n ,int e){
	adjMatrix a2(n);
	int e_max = combination(n ,2)/2;
	int arr[e*2];
	int n1 ,n2;
	
	for(int i=0 ;i<2*e ;i+=2){
		adjNode *current = first;
		n1 = rand()%n+1;
		n2 = rand()%n+1;	
			
		for(int k=0 ;k<2*e ;k+=2){
			if(arr[k] == n1){
				if(arr[k+1] == n2){
					n1 = rand()%n+1;
					n2 = rand()%n+1;
					k=0; 
				}
			}
			
			if(arr[k] == n2){
				if(arr[k+1] == n1){
					n1 = rand()%n+1;
					n2 = rand()%n+1;
					k=0; 
				}
			}
		}
		arr[i]=n1;
		arr[i+1]=n2;
		
	
		if(n1 == n2){
			for(int j=1 ;j<n1 ;j++)
				current = current->next;
				
			Push_E(current ,n2);
			current = first;	
		}
		else{
			for(int j=1 ;j<n1 ;j++){
				current = current->next;
			}
			Push_E(current ,n2);
			
			current = first;
			for(int j=1 ;j<n2 ;j++){
				current = current->next;
			}
			Push_E(current ,n1);
			current = first;
		}	
	}
}

void adjList::PrintList(){
	if (first == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    adjNode *current = first;             // 用pointer *current在list中移動
    adjNode *c2 = current;
    
    while (current != 0) {                 // Traversal
    	cout << current->data << " ";
    	c2 = c2->edge;
    	while(c2 != 0){	
			cout << c2->data << " ";
    		c2 = c2->edge;
		}
		cout<<endl;
        current = current->next;
        c2 = current;
    }
}

void adjList::Push_N(int x){
	 adjNode *newNode = new adjNode(x);   // 配置新的記憶體

    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }

    adjNode *current = first;
    while (current->next != 0) {           // Traversal
        current = current->next;
    }
    current->next = newNode;  
}

void adjList::Push_E(adjNode *now ,int x){
	adjNode *newNode2 = new adjNode(x);
	
	if(now == 0){
		return;
	} 
	
	adjNode *current2 = now;
	while(current2->edge != 0){
		current2 = current2->edge;
	} 
	current2->edge = newNode2;
}

void adjList::dfs(int v){
	ddfs(v);
	for(int i=0 ;i<num ;i++){
		if(visited[i] == 0)
			ddfs(i+1);
	}
		
}

void adjList::ddfs(int v){
	int j=1;
	stack_in(v);
	cout<<v<<"->";
	detc++;
	visited[v-1]=1;
	while(list[v-1][j]<0 && j<num)j++;
	//cout<<"j "<<v-1<<","<<j<<" ";
	int w = list[v-1][j];
	while(w>0){
		if(visited[w-1] != 1)
			ddfs(w);
		int i=j+1;
		if(i==num)break;
		while(list[v-1][i]<0 && i<num)i++;
		j++;
		//cout<<"i "<<v-1<<","<<i<<"\n";
		w = list[v-1][i];
	}
}

void adjList::set(){
	int i=0 ,j=0;
	adjNode *current = first;             // 用pointer *current在list中移動
    adjNode *c2 = current;
    
    while (current != 0) {                 // Traversal
    	list[i][0] = current->data; 
    	c2 = c2->edge;
    	j++;
    	while(c2 != 0){	
			list[i][j] = c2->data ;
    		c2 = c2->edge;
    		j++;
		}
        current = current->next;
        i++;
        c2 = current;
        j=0;
    }
    
    /*for(int i=0 ;i<num ;i++){
    	for(int j=0 ;j<num ;j++){
			cout<<list[i][j] << " ";
		}cout<<endl;
	}*/
		
    
}

void adjList::bfs(int v){
	bbfs(v);
	for(int i=0 ;i<num ;i++){
		if(visit[i-1] == 0)
			bbfs(i);
	}
}

void adjList::bbfs(int v){
	queue_in(num ,v);
	visit[v-1] = 1;
	
	while(queue_empty() == 1){
		int temp = queue_front();
		queue_out(num);
		cout<<temp<<"->";
		
		for(int i=0 ;i<num ;i++){
			for(int j=1 ;j<num ;j++){
				int w = list[temp-1][j];
				if(w==0)break;
				if(visit[w-1]==0 && list[temp-1][j] >0){
					queue_in(num ,w);
					visit[w-1]=1;
				}
			}
		}
	}
}

adjList::~adjList(){;}
