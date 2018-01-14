#include <iostream>
using namespace std;
long feynmann(int n){
 return n*(n+1)*(2*n+1)/6;
}
int main()
{
	int t;

	while(1){
		cin>>t;
		if(t==0) return 0;//ideone solved it even thru exit(0), but spoj didnt check sometme later
	 	cout<<feynmann(t)<<endl;

	}

	return 0;
}
