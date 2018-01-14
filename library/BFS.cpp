/*input
10 13
1 2
1 3
1 4
2 3
4 5
4 8
5 6
5 7
6 7
7 8
6 9
8 9
9 10
4
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;



struct node{
	vector <int> adjList;
	int parent, colour, level, d;// pre = 0, post = 0;
 
	}graph[100];

int N, M;

void Initialize(){
	for (int i = 0; i < N+1; ++i)
	{
		graph[i].parent = -1;
		graph[i].colour = -1;
		graph[i].level = -1;

	}

}

void showNode(int i){
	cout<<"Showing node"<<endl;
	cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") has neighbours:"<<endl;
	for (int j = 0; j < graph[i].adjList.size(); ++j)
	{
		cout<<"    >"<<graph[i].adjList[j]<<endl;
	}
	cout<<"exit"<<endl;
}

void ShowGraph(){
	cout<<"Showing complete graph"<<endl;
	for (int i = 1; i < N + 1; ++i)
	{
		cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") has neighbours:"<<endl;
		for (int j = 0; j < graph[i].adjList.size(); ++j)
		{
			cout<<"    >"<<graph[i].adjList[j]<<endl;
		}
	}
}


void AddEdge(int i, int j){
	graph[i].adjList.push_back(j);
}


void BFS(int i){
	// cout<<"BFS starts with initial node :"<<i<<endl;
	Initialize();
	queue<int> Q;
	graph[i].level = 1;
	graph[i].colour = 0;
	Q.push(i);
	int j, v;
 
 	while(!Q.empty()){
 		j = Q.front();
 		Q.pop();
 		// cout<<"popped from the queue :>"<<j<<endl;
 		graph[j].colour = 1;
 		// showNode(j);
 		for(int k = 0; k < graph[j].adjList.size(); ++k){

 			v = graph[j].adjList[k];
 			// cout<<"node k = "<<k<<" extracted from j("<<j<<")'s list with value :"<<v<<endl;
 			if(graph[v].level == -1){
 				// showNode(v);
 				graph[v].level = graph[j].level + 1;
				graph[v].parent = j;
				graph[v].colour = 0;				
 				Q.push(v);

 			}
 			// else cout<<"pass; already visited"<<endl;
 		}
 	}
}



int main(){
	int x, y;
	cin>>N>>M;
	for (int i = 0; i < M; ++i)
	{
		cin>>x>>y;
		AddEdge(x,y);
		AddEdge(y,x);
	}
	// cout<<"enter the parent node ::";
	cin>>x;
	BFS(x);
	ShowGraph();

	return 0;

}