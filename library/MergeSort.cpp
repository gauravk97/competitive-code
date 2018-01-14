/*input
8
1 4 2 9 12 1 88 23
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std; 

void merge(int *A, int start, int mid, int end){
	int n1 = mid - start + 1, n2 = end - mid, Left[n1+2], Right[n2+2];
	for (int i = 1; i <= n1; ++i)
	{
		Left[i] = A[start+i-1];
	}
	for (int i = 1; i <= n2; ++i)
	{
		Right[i] = A[mid+i];
	}
	Left[n1+1] = INT_MAX;
	Right[n2+1] = INT_MAX;

	int i = 1, j = 1;
	for (int k = start; k <= end; ++k)
	{
		if (Left[i] < Right[j])
		{
			A[k] = Left[i];
			++i;
		}
		else{
			A[k] = Right[j];
			++j;
		}
	}


}

void mergesort(int* A, int start, int end){
	if (start < end)
	{
		int mid = (start + end)/2;
		mergesort(A, start, mid);
		mergesort(A, mid+1, end);
		merge(A, start, mid, end);
	}
}

int main() {
	ios::sync_with_stdio(false);	

	int t;
	cin>>t;
	int a[t];
	for (int i = 1; i <= t; ++i)
		cin>>a[i];
	mergesort(a, 1, t);
	for (int i = 1; i <= t; ++i)
		cout<<a[i]<<" ";
	
	return 0;
}

/*comments on the ques: >

*/