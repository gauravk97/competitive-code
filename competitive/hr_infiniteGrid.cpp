#include <bits/stdc++.h>

using namespace std;

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int i = 1, result = 0;
    while(i<X.size()){
        int  d = abs(X[i]-X[i-1])+abs(Y[i]-Y[i-1]);
        while( d > 0 ){
            
            if(  (abs(X[i]-X[i-1]))>0 && (abs(Y[i]-Y[i-1]))>0  ){
                int a = X[i-1], b = Y[i-1];
                int d1 = abs(X[i]-X[i-1]-1)+abs(Y[i]-Y[i-1]-1), d2 = abs(X[i]-X[i-1]+1)+abs(Y[i]-Y[i-1]-1), d3 = abs(X[i]-X[i-1]-1)+abs(Y[i]-Y[i-1]+1), d4 = abs(X[i]-X[i-1]+1)+abs(Y[i]-Y[i-1]+1), dmin = d1;
                X[i-1] = a+1;Y[i-1] = b+1;
                
                if(d2<dmin){
                    dmin = d2;
                    X[i-1] = a-1;Y[i-1] = b+1;
                }
                
                if(d3<dmin){
                    dmin = d3;
                    X[i-1] = a+1;Y[i-1] = b-1;
                }

                if(d4<dmin){
                    dmin = d4;
                    X[i-1] = a-1;Y[i-1] = b-1;
                }

                    
            }
            
            else{
                int a = X[i-1], b = Y[i-1];
                int d1 = abs(X[i]-X[i-1]-1)+abs(Y[i]-Y[i-1]), d2 = abs(X[i]-X[i-1]+1)+abs(Y[i]-Y[i-1]), d3 = abs(X[i]-X[i-1])+abs(Y[i]-Y[i-1]+1), d4 = abs(X[i]-X[i-1])+abs(Y[i]-Y[i-1]-1), dmin = d1;
                X[i-1] = a+1;Y[i-1] = b;
                
                if(d2<dmin){
                    dmin = d2;
                    X[i-1] = a-1;Y[i-1] = b;
                }
                
                if(d3<dmin){
                    dmin = d3;
                    X[i-1] = a;Y[i-1] = b-1;
                }

                if(d4<dmin){
                    dmin = d4;
                    X[i-1] = a;Y[i-1] = b+1;
                }
                
            }
            result++;
            d = abs(X[i]-X[i-1])+abs(Y[i]-Y[i-1]);
        }
        ++i;
    }
    return result;
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