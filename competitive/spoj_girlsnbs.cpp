/*input
1 101
212 898
322 10
0 0
5 1
0 1000
-1 -1
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float i, j, k, min, max;
	cin>>i>>j;
	while(i!=-1){
		min = (i>j)?j:i;
		max = (i>j)?i:j;
		k = max/(min + 1);
		k = ceil(k);
		cout<<k<<endl;
		cin>>i>>j;
	}
	return 0;
}