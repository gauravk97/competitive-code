/*input
4
1 4 3 2
5
2 3 4 5 1
1
1
0
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std; 

int main() {
	ios::sync_with_stdio(false);	

	int t, n, flag = 0;
	cin>>t;
	while(t){
		int a[t+1], b[t+1];
		for (int i = 1; i < t+1; ++i){	
			cin>>a[i];
			b[a[i]]=i;
		}
		
		for (int i = 1; i < t+1; ++i){
		// {	cout<<a[i]<<" :"<<b[i]<<" "<<i<<" "<<t<<endl;
			if(a[i] != b[i]) {flag = 1;break;}
			else flag = 0;
		}
		if(flag == 1)cout<<"not ambiguous"<<endl;
		else cout<<"ambiguous"<<endl;

		cin>>t;
	}
	return 0;
}

/*comments on the ques: >

*/