/*input
8 10
1 2
1 3
1 8
2 6
3 4
3 5
4 5
6 5
5 7
8 7
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
 	vector<int> adjList;
 	int indegree, parent;
}Dag[101];

int N, M;

void Init(){
	for (int i = 0; i <= 100; ++i)
	{
		Dag[i].indegree = 0;
		Dag[i].parent = -1;
	}
}

void Addedge(int i, int j){
	Dag[i].adjList.push_back(j);
}

//show node and graph 
void Topo(){
	cout<<"topo start"<<endl;
	Init();

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
			if(Dag[k].indegree == 0) toExplore.push(k);
		}
	}
	cout<<"topo exit"<<endl;

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

	Topo();
	return 0;
}

/* comments on the question :>

*/