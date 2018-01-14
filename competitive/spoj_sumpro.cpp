/*input
1
100
*/
#include <iostream>
using namespace std;
typedef unsigned long long u64;
#define M 1000000007


u64 sumpro(u64 n){
	u64 sum = 0, k, count = 0, last = 0;
	cout<<"n: "<<n<<" :";
	for (u64 i = 1; i <= n; ++i)
	{

		k = n/i;
		cout<<k<<": "<<i<<endl;
		sum += k*i;
		if(last != k){last = k; count++;}
	}
	// cout<<"number :"<<count-2<<endl;
	return sum;

}

int main()
{
	ios::sync_with_stdio(false);
	u64 t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<sumpro(n)%M<<endl;

	}
	return 0;
}