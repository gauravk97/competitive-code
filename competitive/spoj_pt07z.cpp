/*input
7
1 2
2 3
3 5
2 4
1 6
6 7
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std; 
typedef vector<int> VI;  typedef vector<vector<int> > VVI; 
typedef vector<string> VS;  typedef vector<vector<string> > VVS; 
typedef signed long long i64;  typedef unsigned long long u64; 

struct node{
	vector<int> adjList;
	int colour, level, parent;// pre, post;

}graph[10001];

int maxm = 0;

void showNode(int i){
	cout<<"Showing node"<<endl;
	cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<endl;//<<") with pre("<<graph[i].pre<<") and post("<<graph[i].post<<") has neighbours:"<<endl;
	for (int j = 0; j < graph[i].adjList.size(); ++j)
	{
		cout<<"    >"<<graph[i].adjList[j]<<endl;
	}
	cout<<"exit"<<endl;
}

void init(int p){
	for (int i = 0; i < 10001; ++i)
	{
		graph[i].level = -1;
		graph[i].parent = -1;
		graph[i].colour = -1;		 
	}
		graph[p].level = 0;
		graph[p].colour = 0;

}


void addEdge(int i, int j){
	graph[i].adjList.push_back(j);
}


void DFS(int root){
	// cout<<"DFS running "<<root<<endl;

	for (int i = 0; i < graph[root].adjList.size(); ++i)
	{


		int k = graph[root].adjList[i];
		// showNode(k);
		if (graph[k].colour == -1)
		{
			graph[k].parent = root;
			graph[k].level = graph[root].level + 1;
			graph[k].colour = 0;
			DFS(k);
		// cout<<"working "<<endl;

		}
	}
	// cout<<"max is "<<maxm<<endl;

	if (graph[maxm].level < graph[root].level)
	{
		maxm = root;
	}
	graph[root].colour = 1;


	// cout<<"DFS exit"<<endl;

}


int main() {
	ios::sync_with_stdio(false);	

	int t, n1, n2, n, first;
	cin>>t;
	n = t- 1;
	for (int i = 0; i < n; ++i)
	{	

		cin>>n1>>n2;
		if(i == 0) first = n1;
		addEdge(n1, n2);
		addEdge(n2, n1);
	}
	init(first);
	DFS(first);
	// cout<<maxm<<endl;
	init(maxm);	
	DFS(maxm);
	cout<<graph[maxm].level<<endl;
	
	return 0;
}

/*comments on the ques: >

*/