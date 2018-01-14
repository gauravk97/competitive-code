/*input
1
3 5 28
*/

#include <bits/stdc++.h>
typedef long long uLL;
using namespace std; 

int main() {
	ios::sync_with_stdio(false);	

	uLL t, n3, nlast3, sum;
	cin>>t;
	while(t--){
		uLL a, d, n;
		cin>>n3>>nlast3>>sum;
		if(sum%(nlast3+n3) == 0){
			n = 2*sum/(nlast3+n3);
			d = (nlast3-n3)/(n-5);
			a = n3-2*d;
		}
		else {
			n = 2*(sum/(nlast3+n3))+1;
			d = (nlast3-n3)/(n-5);
			a = n3-2*d;
		}
		cout<<n<<endl;
		for (uLL i = 1; i <= n; ++i)
			cout<<a+(i-1)*d<<" ";
		cout<<endl;
	}
	return 0;
}
