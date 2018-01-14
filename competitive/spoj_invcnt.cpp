/*input
2

3
3
1
2

5
2
3
8
6
1


*///

// question:: http://www.spoj.com/problems/INVCNT/
// ideone:: 
 
#include <bits/stdc++.h>

using namespace std; 


long long int merge(long long int *A, long long int start, long long int mid, long long int end){
	// cout<<"merge starts start:"<<start<<" mid:"<<mid<<" end:"<<end<<endl;
	long long int n1 = mid - start + 1, n2 = end - mid, Left[n1+2], Right[n2+2];
	long long int inversion = 0;
	for (long long int i = 1; i <= n1; ++i)
	{
		Left[i] = A[start+i-1];
	}
	for (long long int i = 1; i <= n2; ++i)
	{
		Right[i] = A[mid+i];
	}
	Left[n1+1] = INT_MAX;
	Right[n2+1] = INT_MAX;
	long long int i = 1, j = 1;
	for (long long int k = start; k <= end; ++k)
	{
		if (Left[i] <= Right[j])
		{
			A[k] = Left[i];
			++i;
		}
		else{
			A[k] = Right[j];
			// cout<<"(inv)comparing L("<<i<<"):"<<Left[i]<<" R("<<j<<"):"<<Right[j]<<endl;		
			if ( i <= n1 && j <= n2)
			{
				inversion += n1 - i + 1;
				// cout<<"add/ing: inv = "<<inversion<<endl;
			}
			++j;
		}
	}
	// cout<<"merge /ends with inv: "<<inversion<<endl;
	return inversion;


}

long long int mergesort(long long int* A, long long int start, long long int end){
	long long int inversion = 0;
	// cout<<"mergesort starts :"<<start<<"  "<<end<<endl;
	if (start < end)
	{
		long long int mid = (start + end)/2;
		inversion += mergesort(A, start, mid);
		inversion += mergesort(A, mid+1, end);
		inversion += merge(A, start, mid, end);
	}
	// cout<<"MS ends :"<<start<<"  "<<end<<" inv : "<<inversion<<endl;
	return inversion;
}

int main() {
	ios::sync_with_stdio(false);	

	long long int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		long long int a[n];
		for (long long int i = 1; i <= n; ++i)
			cin>>a[i];
		long long int inversion = mergesort(a, 1, n);
		// for (long long int i = 0; i < n; ++i)
		// {cout<<a[i+1]<<" ";
		// }
		cout<<inversion<<endl;
	}
	return 0;
}

/*comments on the ques: >
woah, this ine though conceptually simple took a toll from me, 
the equal L52
mergesort problems in long long interpretation
the start , end , +1 fuckers
*/