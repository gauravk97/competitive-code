#include <bits/stdc++.h>
using namespace std; 

struct node{
	int  level, isWhite, colour;
	}graph[183][183];

struct tup{
	int i,j;
	tup(int a = 0, int b = 0)
		{i = a; j = b;}
};

int N, M, dis = 0;

void Initialize(){
	for (int i = 0; i < N+1; ++i)
	{
		for (int j = 0; j < M+1; ++j)
		{
			graph[i][j].colour = -1;
			graph[i][j].level = -1;
		}
	}
}

void BFS(tup t1){
	queue<tup> Q;
	graph[t1.i][t1.j].level = 0;
	dis = 0;
	Q.push(t1);
	tup a, b, c;
 
 	while(!Q.empty()){
 		a = Q.front();
 		Q.pop();
 		graph[a.i][a.j].colour = 1;
 		tup c(a.i, a.j + 1);
 		tup b(a.i + 1, a.j);
 		tup d(a.i, a.j - 1);
 		tup e(a.i - 1, a.j);

 		if (graph[a.i][a.j].isWhite)
 		{
 			dis = graph[a.i][a.j].level;
 			break;
 		}
 		if (graph[b.i][b.j].level == -1 && 0<b.i && b.i<N+1 && 0<b.j && b.j<M+1)
 		{
 				graph[b.i][b.j].level = graph[a.i][a.j].level + 1;
 				graph[b.i][b.j].colour = 0;				
 				Q.push(b);
 		}
 		if (graph[c.i][c.j].level == -1 && 0<c.i && c.i<N+1 && 0<c.j && c.j<M+1)
 		{
 				graph[c.i][c.j].level = graph[a.i][a.j].level + 1;
 				graph[c.i][c.j].colour = 0;				
 				Q.push(c);
 		}
 		if (graph[d.i][d.j].level == -1 && 0<d.i && d.i<N+1 && 0<d.j && d.j<M+1)
 		{
 				graph[d.i][d.j].level = graph[a.i][a.j].level + 1;
 				graph[d.i][d.j].colour = 0;				
 				Q.push(d);
 		}
 		if (graph[e.i][e.j].level == -1 && 0<e.i && e.i<N+1 && 0<e.j && e.j<M+1)
 		{
 				graph[e.i][e.j].level = graph[a.i][a.j].level + 1;
 				graph[e.i][e.j].colour = 0;				
 				Q.push(e);
 		}
 	}
}

int main() {
	ios::sync_with_stdio(false);	
	int t;
	string ip;
	cin>>t;
	while(t--){
		cin>>N>>M;
		for (int i = 1; i < N+1; ++i)
		{
			cin>>ip;
			for (int j = 1; j < M+1; ++j)
			{
				graph[i][j].isWhite = ip[j-1] - '1' + 1;
			}

		}

		for (int i = 1; i < N+1; ++i)
		{
			for (int j = 1; j < M+1; ++j)
			{
				tup t1(i, j);
				Initialize();

				BFS(t1);
				cout<<dis<<" ";
			}
			cout<<endl;
		}

	}
	return 0;
}