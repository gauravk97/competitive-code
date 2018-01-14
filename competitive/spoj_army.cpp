/*input
2

1 1
1
1

3 2
1 3 2
5 5
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	

	int t, g, m;
	cin>>t;
	while(t--){
		cin>>g>>m;
		int a, b, maxg = -1, maxm = -1;
		for (int i = 0; i < g; ++i){
			cin>>a;
			if(a>maxg)maxg = a;
		}
		for (int i = 0; i < m; ++i){
			cin>>b;
			if(b>maxm)maxm = b;
		}
		if(g == 0 && m == 0) cout<<"uncertain"<<endl;
		if (maxm>maxg)
			cout<<"MechaGodzilla"<<endl;
		else cout<<"Godzilla"<<endl;		
	}
	return 0;
}