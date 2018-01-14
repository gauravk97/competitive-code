/*input
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0
*/

// question::
// ideone::
 
#include <bits/stdc++.h>
using namespace std;

void strRev(string& s, int start, int end){
	char temp;
	for (int i = 0; i <= (end - start)/2; ++i)
	{
		temp = s[start+i -1];
		s[start+i -1] = s[end - i -1];
		s[end - i -1] = temp;
	}

}

void stringParse(string& s, int col){
	int l = s.length(), nRow = l/col;
	for (int i = 0; i < nRow; ++i)
	{	
		if (i%2 != 0)
		{	
			strRev(s, (i)*col+1, (i)*col+col);
		}
	}
}


string decode(string s, int column){
	int rows = s.length()/column, l = s.length();
	string res;
	res.clear();
	stringParse(s, column);
	for (int i = 0, k = 0, j = k; i < l; ++i, j+=column)
	{
		if(j>l-1){ j = j%l-1; k++; j = k;
		}

		res.push_back(s[j]);
	}
	
	return res;
}





int main() {
	ios::sync_with_stdio(false);	
	string s1;
	int t, n;
	cin>>t;
	while(t){
		cin>>s1;
		cout<<decode(s1, t)<<endl;
		cin>>t;
	}
	
	return 0;
}

/*comments on the ques: >

*/