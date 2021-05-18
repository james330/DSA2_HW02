#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"tool.cpp";

using namespace std;



class adjMatrix {
	private:	
		int num;//arr_length;
		int edge;
		int detc;
		int **arr;
		int *visited;
		int *visit;
	public:
		adjMatrix();
		adjMatrix(int n);
		void set(int n ,int e); 
		void setArr(int **a ,int n ,int e);
		void out();
	
		void dfs(int v);
		void ddfs(int v);
		int getfirstedge(int v);
		int getnextedge(int v,int w);
		
		void bfs(int v);
		void bbfs(int v);
		~adjMatrix();
};

adjMatrix::adjMatrix(){;}

adjMatrix::adjMatrix(int n){
	
	srand(time(NULL));
	num=n;
	ti =0;
	t=0;
	detc = 0;
	q=0;
	qq=0;
	
	sta = new int [n];
	nst = new int [n];
	que = new int [n];
	qu1 = new int [n];
	arr = new int *[n];
	visited = new int [n];
	visit = new int[n];
	
	for(int i=0 ;i<n ;i++){
		arr[i] = new int [n];
		visit[i] = 0;
		visited[i] = 0;
		que[i] = 0;
	}
	
	edge=combination(num ,2)/2; 
}

void adjMatrix::set(int n ,int e){
	setArr(arr ,n ,e);
}

void adjMatrix::setArr(int **a ,int n ,int e){
	int nn = n*n;
	int x;
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			a[i][j]=0;
		}
	}
	
	for(int i=0 ;i<e ;i++){
		x= rand()%nn;
		while(a[x/n][x%n] == 1)
			x=rand()%nn;
		
		a[x/n][x%n]=1;
		a[x%n][x/n]=1;
	}
}

void adjMatrix::out(){
	for(int i=0 ;i<num ;i++){
		for(int j=0 ;j<num ;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void adjMatrix::dfs(int v){
	ddfs(v);
    for(int i=0 ;i<num ;i++){
    	if(visited[i] == 0)
    		ddfs(i);
	}
}

void adjMatrix::ddfs(int v){
	cout<<v<<"->";
    visited[v]=1;
    int w=getfirstedge(v);
    while(w>=0&&w<num)
    {
        if(visited[w]!=1)
        	ddfs(w);
        w=getnextedge(v,w);
    }
}
int adjMatrix::getfirstedge(int v){
		if(v>num||v<0)    return -1;
        int i=0;
        while(arr[v][i]<=0&&i<num)    i++;
        if(i>num||i<0)    return -1;
        return i;
}

int adjMatrix::getnextedge(int v ,int w){
		int i=w+1;
        if(v>num||v<0||i>num||i<0)    return -1;
        while(arr[v][i]<=0&&i<num)    i++;
        if(i>num||i<0)    return -1;
        return i;
}

void adjMatrix::bfs(int v){
	bbfs(v);
	for(int i=0 ;i<num ;i++){
		if(visit[i] == 0)
			bbfs(i);
	}
}

void adjMatrix::bbfs(int v){
	queue_in(num ,v);
	visit[v] = 1;
	
	while(queue_empty() == 1){
		int temp = queue_front();
		queue_out(num);
		cout<<temp<<"->";
		
		for(int i=0 ;i<num ;i++){
			if(!visit[i] && arr[temp][i] ==1){
				queue_in(num ,i);
				visit[i]=1;
			}
		}
	}
}

adjMatrix::~adjMatrix(){;}

