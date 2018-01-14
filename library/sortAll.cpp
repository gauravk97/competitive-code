/*input
2
5 11 1 8 5 5
6 5 25 94 9 8 1
*/

// question::
// ideone::
 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <queue> 
using namespace std; 
typedef vector<int> VI;  typedef vector<vector<int> > VVI; 
typedef vector<string> VS;  typedef vector<vector<string> > VVS; 
typedef signed long long i64;  typedef unsigned long long u64; 

void bubbleSort(int ar[], int n){
	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (ar[j+1]<ar[j])
			{
				temp = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = temp;
			}	
		}
		 
	}
}


void insertionSort(int ar[], int n){

	for (int i = 0; i < n; ++i)
	{
		int j = i, temp;
		 while(j>0 && ar[j-1]>ar[i]){
		 	j--;
		 	temp = ar[i];
		 	for (int k = i; k > j; --k)
		 	{
		 		ar[k] = ar[k-1];
		 	}
		 	ar[j] = temp;


		 }
	}
}

int[] mergeSort(int ar[], int n){
	if(n==1) return ar;
	middle = n/2;


int left[] = mergeSort(ar, middle - 1), right[] = mergeSort(*(ar+middle), n - middle);
int result[] = mergeSort()
}

	

int main() {
	

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int ar[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
		}

		insertionSort(ar,n);

		for (int i = 0; i < n; ++i)
		{
			cout<<ar[i]<<"  ";
			 
		}
		cout<<endl;
	}
	return 0;
}

