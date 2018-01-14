/*input
4 3
1 2 5
2 3 2
1 4 9
*/

#include <bits/stdc++.h>
using namespace std;


struct node{
	vector <int> adjList;
	vector <int> weight;
	int parent, colour, level, distance, time;// pre = 0, post = 0;
	}graph[100];

int N, M;

void Initialize(){
	for (int i = 0; i < N+1; ++i)
	{
		graph[i].parent = -1;
		graph[i].colour = -1;
		graph[i].level = -1;
		graph[i].distance = INT_MAX;
	}

}

void showNode(int i){
	cout<<"Showing node"<<endl;
	cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") has neighbours (and weights):"<<endl;
	for (int j = 0; j < graph[i].adjList.size(); ++j)
	{
		cout<<"    >"<<graph[i].adjList[j]<<" ( "<<graph[i].weight[j]<<") "<<endl;
	}
	cout<<"exit"<<endl;
}

void ShowGraph(){
	cout<<"Showing complete graph"<<endl;
	for (int i = 1; i < N + 1; ++i)
	{
		cout<<"node:"<<i<<"(level: "<<graph[i].level<<", col: "<<graph[i].colour<<") dist: "<<graph[i].distance<<" has neighbours:"<<endl;
		for (int j = 0; j < graph[i].adjList.size(); ++j)
		{
			cout<<"    >"<<graph[i].adjList[j]<<" ( "<<graph[i].weight[j]<<") "<<endl;
		}
	}
}


void AddEdge(int i, int j, int k){
	graph[i].adjList.push_back(j);
	graph[i].weight.push_back(k);
}

void Djikstra(int source){
	int distCovered=0;
	vector <pair<int,int>> OnGoing;
	graph[source].colour=0;
	OnGoing.push_back(make_pair(source,0));
	while(!OnGoing.empty()){
		int minW = INT_MAX, minValue, minIndex;
		//find min of the distances ongoing has.
		for (int i = 0; i < OnGoing.size(); ++i)
		{
			if(minW>OnGoing[i].second){
				minW = OnGoing[i].second;
				minValue = OnGoing[i].first;
				minIndex = i;
			}
		}

		cout<<"Opening with "<<minValue<<endl;

		for (int i = 0; i < graph[minValue].adjList.size(); ++i){
			if(graph[graph[minValue].adjList[i]].colour == -1){
				OnGoing.push_back(make_pair(graph[minValue].adjList[i], graph[minValue].weight[i]));
				graph[graph[minValue].adjList[i]].colour = 0;
			}
		}
			
		//subtract wt
		for (int i = 0; i < OnGoing.size(); ++i)
		{
			OnGoing[i].second -= minW;
		}
		//set Distance of source
		graph[minValue].distance = distCovered+minW;
		distCovered+=minW;
		//pop the element
		graph[minValue].colour=1;
		OnGoing.erase(OnGoing.begin()+minIndex);
	}

}

int main()
{
	int from, to, wt;
	cout<<"Enter a graph"<<endl;
	cin>>N>>M;
	Initialize();
	for (int i = 0; i < M; ++i)
	{
			cin>>from>>to>>wt;
			cout<<from<<" "<<to<<" "<<wt<<endl;
			AddEdge(from,to,wt);
			AddEdge(to, from, wt);
	}
	
	Djikstra(1);
	ShowGraph();

	return 0;
}