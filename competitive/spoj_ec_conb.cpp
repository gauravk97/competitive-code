/*input
11
16
1
10
8
3
5
2
10000000 
5000000
100000
9999999
*/

//ideone:: https://i...content-available-to-author-only...e.com/8uz1t4
//spoj http://w...content-available-to-author-only...j.com/problems/EC_CONB
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int binary(int n){
	int num=n,Number=0,i;
	vector <int> s;
	//s.clear();	
	for(i=0;i<=log2(num);++i){
		if(n%2==0) s.push_back(0);
		else if(n%2==1) s.push_back(1);
		n/=2;
	}
	
	reverse(s.begin(), s.end());
	i=0;
	for(vector<int>::iterator j = s.begin(); j != s.end(); j++)
	{
		Number += pow(2,i)*(*j);
		++i;
	}
	
	return Number;
}

int main() {
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2==0)
		cout<<binary(n)<<endl;
		else
		cout<<n<<endl;
	}
	return 0;
}

