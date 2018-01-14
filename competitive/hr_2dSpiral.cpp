#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int L = 0, T = 0, B = A.size()-1, R = A[0].size()-1, dir = 0;
	// if(A[0].size() == 1){
 //        for(int i = 0; i < A.size(); ++i){
 //            result.push_back(A[i][0]);
 //        }
 //        return result;
 //    }
    

	while(L<=R && T<=B){
		// cout<<"L :"<<L<<" R:"<<R<<" T:"<<T<<" B:"<<B<<endl;
		if(dir == 0){
			for (int i = L; i <= R; ++i)
			{	
				// cout<<A[T][i]<<"  ";
				result.push_back(A[T][i]);
			}
			T++;

			// cout<<endl<<"T and dir "<<T<<"  "<<dir<<endl;
		}
		if(dir == 1){
			for (int i = T; i <= B; ++i)
			{
				// cout<<A[i][R]<<" ";
				result.push_back(A[i][R]);
			}
			R--;
			
			// cout<<endl<<"R and dir "<<R<<"  "<<dir<<endl;

		}
		if(dir == 2){
			for (int i = R; i >= L; --i)
			{
				// cout<<A[B][i]<<" ";
				result.push_back(A[B][i]);
			}
			B--;
			// cout<<endl<<"B and dir "<<B<<"  "<<dir<<endl;

		}
		if(dir == 3){
			for (int i = B; i >= T; --i)
			{
				// cout<<A[i][L]<<" ";
				result.push_back(A[i][L]);
			}
			L++;
			// cout<<endl<<"L and dir "<<L<<"  "<<dir<<endl;

		}
		dir = (dir+1)%4;
	}

	
	
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main()
{
	ios::sync_with_stdio(false);
	vector< vector<int> > A = {{1},{2},{3},{4}};
	// [133, 241, 22, 258, 187, 150, 79, 207, 196, 401, 366, 335, 198]
  // [401, 55, 260, 363, 14, 318, 178, 296, 333, 296, 45, 37, 10]
  // [112, 374, 79, 12, 97, 39, 310, 223, 139, 91, 171, 95, 126]
// ]
	
	vector<int> v = spiralOrder(A);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}

/* comments on the question :>

*/