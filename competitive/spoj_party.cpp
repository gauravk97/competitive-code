/*input

*/

#include <bits/stdc++.h>

using namespace std;

int DP(int* cost, int* fun, int budget, int noP){
	int maximiseFun = 0;
	int totalCost = 0;
	for (int i = 0; i < noP; ++i)
	{
		if()
		maximiseFun
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;//n == budget, m == no. of parties
	while(n!=0 && m!=0){
		int a[m], b[m]; // a == cost, b == fun
		for (int i = 0; i < m; ++i)
		{
			cin>>a[i]>>b[i];
		}

		DP(*a, *b, n, m);

		cin>>n>>m;
	}
	return 0;
}