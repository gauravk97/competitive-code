/*input
5 4
1 1
2 2
3 4
3 5
*/

//spoj: is it a tree ?


#include <bits/stdc++.h>
using namespace std;

struct node
{
	vector<int> adjList;
	int level, colour, parent, pre, post;
}graph[10001];

int N, M, ctr = 0;



void init(int p){
	for (int i = 0; i < 10001; ++i)
	{
		graph[i].level = -1;
		graph[i].parent = -1;
		graph[i].colour = -1;
		graph[i].pre = 0;
		graph[i].post = 0;
	}

	graph[p].level = 0;
	graph[p].colour = 0;

}


void showNode(int i){
	cout<<"Showing node"<<endl;
	cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") with pre("<<graph[i].pre<<") and post("<<graph[i].post<<") has neighbours:"<<endl;
	for (int j = 0; j < graph[i].adjList.size(); ++j)
	{
		cout<<"    >"<<graph[i].adjList[j]<<endl;
	}
	cout<<ctr<<":: counter"<<endl;
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


void DFS(int root, int& flag){
	// cout<<"DFS s :"<<flag<<" and root :"<<root<<endl;
	ctr++;
	// showNode(root);
	for (int i = 0; i < graph[root].adjList.size(); ++i)
	{
		int k = graph[root].adjList[i];
		// showNode(k);
		if (graph[k].colour == 0 && graph[root].parent != k)
			flag = 1;
		

		// cout<<flag<<" :Flag"<<endl;
	 	if (graph[k].level == -1)
		{
			graph[k].level = graph[root].level + 1;
			graph[k].parent = root;
			graph[k].colour = 0;
			DFS(k, flag);
		}


	}
	graph[root].colour = 1;

	// cout<<"DFS E"<<endl;
}

int main(){
	vector<int> v;
	int t, first, f, l, flag = 0;
	cin>>N>>M;
	if(N-1 == M){

		for (int i = 0; i < N; ++i)
		{
			cin>>f>>l;
			if (i == 0) first = f;
			// if (f == l)
			// {
			// 	flag = 1;
			// }
			AddEdge(f, l);
			AddEdge(l, f);

		}

		init(first);
		DFS(first, flag);
		// cout<<flag<<"::flag"<<endl;
		if (flag == 0 && ctr == N)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else cout<<"NO"<<endl;
	// cout<<ctr<<endl;	

//forest check


	return 0;
}


/*comments on the ques: >
couple of problems occured, the crux was revealed to me, using colours instead of pre & post
parent check
gray check
forest check
*/