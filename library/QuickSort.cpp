/*input

*/

#include <bits/stdc++.h>

using namespace std;

int partition(int a[], start, end){
	int p = a[start], i, j;

}

void quick(int a[], int start, int end){
	while(start<end){
		int p = partition(a, start, end);
		quick(a, start, p);
		quick(a, p, end);
	}
}


void QuickSort(int a[], int n){
	quick(a, 0, n);
}

int main() {
	ios::sync_with_stdio(false);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];

		QuickSort(a, n);

		for (int i = 0; i < n; ++i)
			cout<<a[i];
	}


	return 0;
}

/*comments on the ques: >

*/