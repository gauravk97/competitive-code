#include <bits/stdc++.h>

using namespace std;

struct Node
{
	vector <int> adjList;
	int parent, indegree, longestPath;
}Dag[101];

int N, M;

void Init(){
	for (int i = 0; i < 101; ++i)
	{
		Dag[i].parent = -1;
		Dag[i].indegree = 0;
		Dag[i].longestPath = 0;
	}
}

void Addedge(int p, int q){
	Dag[p].adjList.push_back(q);
}

//show node and graph 
int Longest(){
	cout<<"topo start"<<endl;
	Init();


	int res = 0;
	queue<int> toExplore;
	
	for (int i = 1; i <= N ; ++i)
	{
		for (int j = 0; j < Dag[i].adjList.size(); ++j)
		{
			int k = Dag[i].adjList[j];
			++Dag[k].indegree;
		}
	}

	for (int i = 1; i <= N ; ++i)
	{
		if(Dag[i].indegree == 0) toExplore.push(i);
	}

	while(!toExplore.empty()){
		int j = toExplore.front();
		toExplore.pop();
		cout<<"Performing Activity : "<<j<<endl;
		Dag[j].indegree = -1;

		for (int i = 0; i < Dag[j].adjList.size(); ++i)
		{
			int k = Dag[j].adjList[i];
			--Dag[k].indegree;
			longestPath[k] = max(longestPath[k], 1 + longestPath[j]);
			res = max(res, longestPath[k]);
			if(Dag[k].indegree == 0) toExplore.push(k);
		}
	}
	cout<<"topo exit"<<endl;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	int p, q, r;
	for (int i = 1; i <= M; ++i)
	{
		cin>>p>>q;
		if(i == 1)r = p;
		Addedge(p,q);
	}
	cout<<Longest()<<endl;
	return 0;
}

/* comments on the question :>

*/