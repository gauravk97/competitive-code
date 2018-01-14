/*input
9
1 2 3 1 4 5 2 3 6
3
*/
#include<iostream>
using namespace std;
 
int maxx(int a[],int i,int m)
{	int mmax = a[i];
	for(int j=i; j<m; j++) 
	{
		mmax = a[j]>mmax?a[j]:mmax;
	}
	return mmax;
}
int main()
{
	int n,k,a[100000]; 
	cin>>n;
	for(int i=0; i<n; i++)
	 {
	 	cin>>a[i];
	 }
 
	cin>>k;
 
	for(int i=0; i<=(n-k); i++)
	 {
	 	cout<<maxx(a,i,i+k)<<" ";
	 }
}