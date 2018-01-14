/*input
100
12
2
*/

#include <bits/stdc++.h>

using namespace std; 

map<int, int> value;

int exchange(int n){
	
	int res = n;
	if(n == 0) return 0;

	if (!value.empty())
	{	if(value.find(n) != value.end()){
			res = value[n];
		}
	}

	else
	{
		int r = exchange(n/2) + exchange(n/3) + exchange(n/4);
		if (r > n)
		{
			res = r;
		}		
		value[n] = res;

	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);	

	int t, n;
	while(cin>>t){
		cout<<exchange(t)<<endl;
	}
	return 0;
}