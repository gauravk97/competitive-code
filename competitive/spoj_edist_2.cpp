/*input
2
auger
boring
convenient
saturated
*/
#include <bits/stdc++.h>

using namespace std;

int Memo[2001][2001];

void init(int lengthA, int lengthB){
	for (int i = 0; i <= lengthA; ++i)
	{
		for (int j = 0; j <= lengthB; ++j)
		{
			Memo[i][j] = -1;
		}
	}
}

string PrintStr(string A, int a){
	string s;
	for (int i = a; i < A.length(); ++i)
	{
		s.append(1, A[i]);
	}
	return s;
}

int EDIST(string A, string B){
	int lengthA = A.length(), lengthB = B.length(), result;
	// cout<<"EDIST Open with A :"<<PrintStr(A, 0)<<" lengthA:"<<lengthA<<" and B:"<<PrintStr(B, 0)<<" lengthB:"<<lengthB<<endl;
	for (int i = lengthA; i >= 0; --i)
		{
		for (int j = lengthB; j >= 0; --j){
			
			if(j == lengthB){
				Memo[i][j] = lengthA-i;
			}
			else if (i == lengthA){
				Memo[i][j] = lengthB-j;
			}
			else{
				
				int res1 = INT_MAX, res2 = INT_MAX , res3 =	INT_MAX, res4 = INT_MAX, res;
			
				if( A[i] == B[j] ){
					Memo[i][j] = Memo[i+1][j+1];//EDIST(A, B, i+1, j+1);
				}
				else{
					// string E = A.substr(0, lengthA), F = B.substr(0, lengthB);
		//insertion
					// E = A.substr(0, lengthA), F = B.substr(1, lengthB);;
					// cout<<"insert #1 ; E :"<<PrintStr(A, a)<<" F:"<<PrintStr(B, b+1)<<endl;
					res2 = 1+Memo[i][j+1];//EDIST(A, B, i, j+1);
					// cout<<"insertion #1 successful :"<<res2<<"; E :"<<PrintStr(A, a)<<" F:"<<PrintStr(B, b+1)<<endl;
		//delete
					// E = A.substr(1, lengthA), F = B.substr(0, lengthB);
					// int lengthE = E.length(), lengthF = F.length();
					// cout<<"lengthE : "<<lengthE<<" F:"<<lengthF<<"; A :"<<A<<" B:"<<B<<endl;
					// cout<<"delete #1 ; E:"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b)<<endl;
					res3 = 1+Memo[i+1][j];//EDIST(A, B, i+1, j);
					// cout<<"delete #1 successful :"<<res3<<"; E:"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b)<<endl;
		//replace
					// E = A.substr(1, lengthA), F = B.substr(1, lengthB);
					// cout<<"replace #1 ; E :"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b+1)<<endl;
					res4 = 1+Memo[i+1][j+1];//EDIST(A, B, i+1, j+1);
					// cout<<"replace #1 successful : "<<res4<<"; E :"<<PrintStr(A, a+1)<<" F :"<<PrintStr(B, b+1)<<endl;
					Memo[i][j] = min(min(res2, res3), res4);
				}		
					// res = minFour(res1, res2, res3, res4);
					// int t = (result==res)?1:0; 
					// cout<<"result overall min :"<<result<<" : "<<" result inner min : "<<res<<" equal  : "<<t<<endl;
			}

		}
	}
	// cout<<"EDIST Close with A "<<PrintStr(A, a)<<" a:"<<a<<" and B:"<<PrintStr(B, b)<<" b:"<<b<<" result:"<<result<<endl;;
	// myMap[make_pair(A,B)]=result;
	// Memo[a][b]=result;
	return Memo[0][0];
}



int main()
{
	ios::sync_with_stdio(false);
	int t;
	string A, B;
	cin>>t;
	while(t--){
		cin>>A>>B;
		int la = A.length(), lb = B.length();
		init(la,lb);
		cout<<EDIST(A,B)<<endl;
		// for (int i = 0; i < 10; ++i)
	// {for (int j = 0; j < 10; ++j){
		// cout<<Memo[i][j]<<" ";	
	// }
	// cout<<endl;
	// }
	}

	return 0;
}