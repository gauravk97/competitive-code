/*input
3
abc
bcde
cdef
zscd
asfdpoil
qwera
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

int EDIST(string A, string B, int a, int b){
	int lengthA = A.length(), lengthB = B.length(), result;
	// cout<<"EDIST Open with A :"<<PrintStr(A, a)<<" lengthA:"<<lengthA<<" a : "<<a<<" and B:"<<PrintStr(B, b)<<" lengthB:"<<lengthB<<" b : "<<b<<endl;
	if (Memo[a][b] != -1){
		// cout<<"fuck it dip"<<endl;
		return Memo[a][b];
	}
	else if(A == B){
		// cout<<"bypass"<<endl;
		result = 0;
	}
	else if(b == lengthB){

		result = lengthA-a;
	}
	else if (a == lengthA){
		result = lengthB-b;
	}
	else{
		
		int res1 = INT_MAX, res2 = INT_MAX , res3 =	INT_MAX, res4 = INT_MAX, res;
	
		if( A[a] == B[b] ){
			res1 = EDIST(A, B, a+1, b+1);
			result = res1;
		}
		else{
			// string E = A.substr(0, lengthA), F = B.substr(0, lengthB);
//insertion
			// E = A.substr(0, lengthA), F = B.substr(1, lengthB);;
			// cout<<"insert #1 ; E :"<<PrintStr(A, a)<<" F:"<<PrintStr(B, b+1)<<endl;
			res2 = 1+EDIST(A, B, a, b+1);
			// cout<<"insertion #1 successful :"<<res2<<"; E :"<<PrintStr(A, a)<<" F:"<<PrintStr(B, b+1)<<endl;
//delete
			// E = A.substr(1, lengthA), F = B.substr(0, lengthB);
			// int lengthE = E.length(), lengthF = F.length();
			// cout<<"lengthE : "<<lengthE<<" F:"<<lengthF<<"; A :"<<A<<" B:"<<B<<endl;
			// cout<<"delete #1 ; E:"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b)<<endl;
			res3 = 1+EDIST(A, B, a+1, b);
			// cout<<"delete #1 successful :"<<res3<<"; E:"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b)<<endl;
//replace
			// E = A.substr(1, lengthA), F = B.substr(1, lengthB);
			// cout<<"replace #1 ; E :"<<PrintStr(A, a+1)<<" F:"<<PrintStr(B, b+1)<<endl;
			res4 = 1+EDIST(A, B, a+1, b+1);
			// cout<<"replace #1 successful : "<<res4<<"; E :"<<PrintStr(A, a+1)<<" F :"<<PrintStr(B, b+1)<<endl;
			result = min(min(res2, res3), res4);
		}		
			// res = minFour(res1, res2, res3, res4);
			// int t = (result==res)?1:0; 
			// cout<<"result overall min :"<<result<<" : "<<" result inner min : "<<res<<" equal  : "<<t<<endl;
	}

	
	// cout<<"EDIST Close with A "<<PrintStr(A, a)<<" a:"<<a<<" and B:"<<PrintStr(B, b)<<" b:"<<b<<" result:"<<result<<endl;;
	// myMap[make_pair(A,B)]=result;
	Memo[a][b]=result;
	return result;
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
		cout<<EDIST(A,B, 0, 0)<<endl;
	}
	return 0;
}