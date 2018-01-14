/*input
1
FOOD
MONEY
*/
#include <bits/stdc++.h>

using namespace std;

// std::map<std::pair<string,string>, int> myMap;

int Memo[2001][2001];

// int minFour(int a, int b, int c, int d){
// 	int Min = a;
// 	if(Min > b) Min = b;
// 	if(Min > c) Min = c;
// 	if(Min > d) Min = d;
// 	return Min;
// }

void init(int lengthA, int lengthB){
	for (int i = 0; i <= lengthA; ++i)
	{
		for (int j = 0; j <= lengthB; ++j)
		{
			Memo[i][j] = -1;
		}
	}
}

// int keyExists(string a, string b){
	// map<std::pair<string,string>, int>::iterator it = myMap.find(make_pair(a,b));
	// if(it != myMap.end()){
   		// return myMap[make_pair(a,b)];
	// }
	// return -1;
// }

int EDIST(string A, string B){
	int lengthA = A.length(), lengthB = B.length(), result;
	cout<<"EDIST Open with A :"<<A<<" lengthA:"<<lengthA<<" and B:"<<B<<" lengthB:"<<lengthB<<endl;
	// int m = keyExists(A,B);
	if (Memo[lengthA][lengthB] != -1){
		cout<<"fuck it dip"<<endl;
		return Memo[lengthA][lengthB];
	}
	else if(A == B){
		cout<<"bypass"<<endl;
		result = 0;
	}
	else if(lengthB == 0){
		result = lengthA;
	}
	else if (lengthA == 0){
		result = lengthB;
	}
	else{
		
		int res1 = INT_MAX, res2 = INT_MAX , res3 =	INT_MAX, res4 = INT_MAX, res;
	
		if( A[0] == B[0] ){
			res1 = EDIST(A.substr(1, lengthA), B.substr(1, lengthB));
			result = res1;
		}
		else{
			string E = A.substr(0, lengthA), F = B.substr(0, lengthB);
				// insertion
			E = A.substr(0, lengthA), F = B.substr(1, lengthB);;
			cout<<"insert #1 : E :"<<E<<" and F : "<<F<<"; A :"<<A<<" B:"<<B<<endl;
			res2 = 1+EDIST(E, F);
			cout<<"insertion #1 successful :"<<res2<<"; A :"<<A<<" B:"<<B<<endl;
				//delete
			E = A.substr(1, lengthA), F = B.substr(0, lengthB);
			int lengthE = E.length(), lengthF = F.length();
			cout<<"lengthE : "<<lengthE<<" F:"<<lengthF<<"; A :"<<A<<" B:"<<B<<endl;
			cout<<"delete #1 : E :"<<E<<" and F : "<<F<<"; A :"<<A<<" B:"<<B<<endl;
			res3 = 1+EDIST(E, F);
			cout<<"delete #1 successful :"<<res3<<"; A :"<<A<<" B:"<<B<<endl;
				//replace
			E = A.substr(1, lengthA), F = B.substr(1, lengthB);
			cout<<"replace #1 E :"<<E<<" and F : "<<F<<"; A :"<<A<<" B:"<<B<<endl;
			res4 = 1+EDIST(E, F);
			cout<<"replace #1 successful : "<<res4<<"; A :"<<A<<" B:"<<B<<endl;
			result = min(min(res2, res3), res4);
		}		
			// res = minFour(res1, res2, res3, res4);
			// int t = (result==res)?1:0; 
			// cout<<"result overall min :"<<result<<" : "<<" result inner min : "<<res<<" equal  : "<<t<<endl;
	}

	
	cout<<"EDIST Close with A "<<A<<" lengthA:"<<lengthA<<" and B:"<<B<<" lengthB:"<<lengthB<<" result:"<<result<<endl;;
	// myMap[make_pair(A,B)]=result;
	Memo[lengthA][lengthB]=result;
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
		cout<<EDIST(A,B)<<endl;
	}
	return 0;
}