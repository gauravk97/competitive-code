/*input
3 2
1 2
2 3
1
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std; 

typedef vector<int> VI;  typedef vector<vector<int> > VVI; 
typedef vector<string> VS;  typedef vector<vector<string> > VVS; 
typedef signed long long i64;  typedef unsigned long long u64; 

struct node{
	vector <int> adjList;
	int parent, colour, level, pre, post;
 
	}graph[100];

int N, M, ctr =0;

void Initialize(int z){
	for (int i = 0; i < N+1; ++i)
	{
		graph[i].parent = -1;
		graph[i].colour = -1;
		graph[i].level = -1;
		graph[i].pre = 0;
		graph[i].post = 0;

	}

	graph[z].level = 0;
	graph[z].colour = 0;

}

void showNode(int i){
	cout<<"Showing node"<<endl;
	cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") with pre("<<graph[i].pre<<") and post("<<graph[i].post<<") has neighbours:"<<endl;
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
		cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") with pre("<<graph[i].pre<<") and post("<<graph[i].post<<") has neighbours:"<<endl;

		for (int j = 0; j < graph[i].adjList.size(); ++j)
		{
			cout<<"    >"<<graph[i].adjList[j]<<endl;
		}
	}
}


void AddEdge(int i, int j){
	graph[i].adjList.push_back(j);
}


void DFS(int i){
	int v;
	// cout<<"DFS starts with i: "<<i<<", ctr: "<<ctr<<endl;

	ctr++;

	graph[i].pre = ctr; 
	// showNode(i);
	for (int j = 0; j < graph[i].adjList.size(); ++j)
	{	

		v = graph[i].adjList[j];
		// showNode(v);
		if (graph[v].level == -1)
		{

			graph[v].level = graph[i].level + 1;
			graph[v].parent = i;
			graph[v].colour = 0;
			DFS(v);
		}
		// else cout<<"pass, already visited"<<endl;


	}
	graph[i].colour = 1;

	ctr++;
	graph[i].post = ctr;
	// cout<<"DFS with node i: "<<i<<" exits."<<endl;
}

int main() {
	ios::sync_with_stdio(false);	

	int x, y;
	cin>>N>>M;

	for (int i = 0; i < M; ++i)
	{
		cin>>x>>y;
		AddEdge(x,y);
		AddEdge(y,x);
	}
	
	cin>>x;
	
	Initialize(x);
	DFS(x);
	ShowGraph();

	return 0;
}

