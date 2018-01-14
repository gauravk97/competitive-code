/*input
1
3 4
0001
0011
0110
*//*
4 6
100001
100001
100001
100001
*//*
3 4
0001
0011
0110
*/

#include <bits/stdc++.h>
using namespace std; 

struct node{
	int  dis, isWhite;
	}graph[183][183];

struct tup{
	int i,j;
	tup(int a = 0, int b = 0)
		{i = a; j = b;}
};

int N, M;

void Initialize(){
	for (int i = 0; i < N+1; ++i)
	{
		for (int j = 0; j < M+1; ++j)
		{
			graph[i][j].dis = 10000;
		}
	}
}

// void showNode(tup a){
// 	cout<<"    Showing node"<<endl;
// 	cout<<"    (level: "<<graph[a.i][a.j].level<<", col: "<<graph[a.i][a.j].colour<<" and isWhite:"<<graph[a.i][a.j].isWhite<<")"<<endl;
// 	cout<<"    exit"<<endl;
// }
void showTup(tup t){cout<<t.i<<" "<<t.j<<endl;}

void BFS(tup t1){
	queue<tup> Q;
	int distance = 0;
	Q.push(t1);
	graph[t1.i][t1.j].dis = 0;
	tup a, b, c;
 
 	while(!Q.empty()){
 		a = Q.front();
 		Q.pop();
 		distance = graph[a.i][a.j].dis + 1;
 		tup c(a.i, a.j + 1);
 		tup b(a.i + 1, a.j);
 		tup d(a.i, a.j - 1);
 		tup e(a.i - 1, a.j);
 		// cout<<"popping a: ";showTup(a);
 		// showTup(b);
 		// showTup(c);
 		// showTup(d);
 		// showTup(e);

 		if (distance < graph[b.i][b.j].dis &&  b.i<N+1 && b.j<M+1)//0<b.i && && 0<b.j 
 		{
 			// cout<<"pushing b"<<endl;showTup(b);
 			// cout<<graph[b.i][b.j].dis<<endl;
 			graph[b.i][b.j].dis = distance;
 			// cout<<graph[b.i][b.j].dis<<endl;
 			Q.push(b);
 		}
 		if (distance < graph[c.i][c.j].dis && c.i<N+1 && c.j<M+1)//0<c.j &&  0<c.i &&
 		{
 			// cout<<"pushing c"<<endl;showTup(c);
 			// cout<<graph[c.i][c.j].dis<<endl;
 			graph[c.i][c.j].dis = distance;
 			// cout<<graph[c.i][c.j].dis<<endl;
 			Q.push(c);
 		}
 		if (distance < graph[d.i][d.j].dis && 0<d.i && 0<d.j)//&& d.j<M+1 && d.i<N+1 
 		{
 				// cout<<"pushing d"<<endl;showTup(d);
 				// cout<<graph[d.i][d.j].dis<<endl;

 				graph[d.i][d.j].dis = distance;
 				// cout<<graph[d.i][d.j].dis<<endl;

 				Q.push(d);
 		}
 		if (distance < graph[e.i][e.j].dis && 0<e.i && 0<e.j)// && e.j<M+1 && e.i<N+1  
 		{
 				// cout<<"pushing e"<<endl;showTup(e);
 				// cout<<graph[e.i][e.j].dis<<endl;
 				graph[e.i][e.j].dis = distance;
 				// cout<<graph[e.i][e.j].dis<<endl;
 				
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
		Initialize();
		for (int i = 1; i < N+1; ++i)
		{
			cin>>ip;
			for (int j = 1; j < M+1; ++j)
			{
				graph[i][j].isWhite = ip[j-1] - '0';
				if (graph[i][j].isWhite == 1)
				{
					graph[i][j].dis = 0;
				}
			}


		}


		for (int i = 1; i < N+1; ++i)
		{
			for (int j = 1; j < M+1; ++j)
			{
				tup t1(i, j);
				if (graph[t1.i][t1.j].isWhite)
				{
					// cout<<"looping :";
					BFS(t1);
				}
				
			}
		}

		for (int i = 1; i < N+1; ++i)
		{
			for (int j = 1; j < M+1; ++j)
			{
				cout<<graph[i][j].dis<<" ";
			}
			cout<<endl;
		}

	}
	return 0;
}
/*comments on the ques: >
*/
