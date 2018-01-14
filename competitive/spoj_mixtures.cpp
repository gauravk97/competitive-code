/*input
3
40 60 20
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std;
int cost;
//memoize
int fn(int ar[], int i, int k){
	int res = 0;
	for (int j = i; j < k; ++j)
	{
		res += ar[j]%100;
	}
	res = res%100;
	return res;
}
//recursion
int start = 0, endq;
int DP(int ar[], int i, int j){ 
	start++;
	cout<<"DP starts para : "<<i<<" "<<j<<" "<<start<<endl;
	if(j == i+1){
		cout<<"esc"<<endl;
		return 0;
	}
	endq = start;
	for(int k = i+1; k < j; k++){
		cout<<"k = "<<k<<endl;
		cout<<fn(ar,i,k)<<"\n"<<fn(ar,k,j)<<endl;
		cost = min(cost, DP(ar, i, k) + DP(ar, k, j) + fn(ar,i,k)*fn(ar,k,j));	
	}

	
	// else{
	// 	;
	// }
	cout<<"DP ends with cost "<<cost<<" end : "<<endq<<endl;
	endq--;
	return cost;
}

int main() {
	ios::sync_with_stdio(false);	

	int n, t = 1;
	cin>>n;
	while(t--){
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		// init();
		// cost = 0; //memo init
		cost = INT_MAX;
		cout<<DP(a, 0, n)<<endl;
		cin>>n;
	}	
	return 0;
}