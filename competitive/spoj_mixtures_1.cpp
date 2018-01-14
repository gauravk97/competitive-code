/*input
2
18 19
3
40 60 20
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std;
int cost;
//memoize
int AR[101][101];
void init(){
	cost = INT_MAX;
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			AR[i][j] = 101;
		}
	}
}
//recursion
int DP(int ar[], int i, int j){ 
	cout<<"DP starts para : "<<i<<" "<<j<<endl;
	if(j == i+1){
		AR[i][j]= ar[i];
		return 0;
	}
	if (j == i+2)
	{
		AR[i][j-1] = (ar[i]+ar[j-1])%100;
	}

	for(int k = i+1; k < j; k++){
		cost = min(cost, DP(ar, i, k) + DP(ar, k, j) + AR[i][k]*AR[k][j]);	
		if(j != i+2) AR[i][j-1] = (AR[i][k-1] + AR[k][j-1])%100;
	}

	
	// else{
	// 	;
	// }
	cout<<"DP ends"<<endl;
	return cost;
}

int main() {
	ios::sync_with_stdio(false);	

	int n, t = 2;
	cin>>n;
	while(t--){
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		init();
		// cost = 0; //memo init
		cout<<DP(a, 0, n)<<endl;
		cin>>n;
	}	
	return 0;
}