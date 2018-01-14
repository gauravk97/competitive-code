/*input
999
29
*/

// question::
// ideone::
 
#include <bits/stdc++.h>
using namespace std; 

string ans1, ans2;

string addStr(string s1, string s2){
	string res; s1.push_back('0'); s2.push_back('0');
	int nDig = s1.length(), carry = 0, A;
	char c;
	for (int i = 0; i < nDig; ++i)
	{
		A = s1[i] - '0' + s2[i] - '0' + carry;
		carry = A/10;
		A = A % 10;
		c = A + 48;
		res.push_back(c);
	}
	return res;
}

string subStr(string s1, string s2){
	string res;
	int nDig = s1.length(), borrow = 0, B, given = 0;
	char c;
	for (int i = 0; i < nDig; ++i)
	{	
		if (s1[i] - s2[i] - given < 0)borrow = 10;
		else borrow = 0;
		B = s1[i] - s2[i] - given + borrow;
		if (borrow)	given = 1;
		else given = 0;
		c = B + 48;
		res.push_back(c);
	}
	return res;
}

string divStr(string s1){
	reverse(s1.begin(), s1.end());
	int nDig = s1.length(), l, C, remainder = 0;
	string res;
	char c;
	for (int i = 0; i < nDig; ++i)
	{
		C = remainder * 10 + s1[i] - '0';
		remainder = C % 2;
		C = C/2;
		c = C + 48;
		res.push_back(c);
	}
	return res;
}

void strEq(string& s1, string& s2){
	int l1 = s1.length(), l2 = s2.length();
	while(l1>l2){
		s2.push_back('0');
		l2 = s2.length();
	}
}


void rTzeroes(){ // remove trailing zeroes
	reverse(ans1.begin(), ans1.end());
	reverse(ans2.begin(), ans2.end());
	while(ans1.back() == '0') ans1.pop_back();
	while(ans2.back() == '0') ans2.pop_back();

}

int main() {
	ios::sync_with_stdio(false);	

	int t = 1;
	string s1, s2, s3;
	while(t--){
		cin>>s1>>s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		strEq(s1, s2);
		ans1 = divStr(addStr(s1, s2));
		ans2 = divStr(subStr(s1, s2));
		rTzeroes();	
		cout<<ans1<<endl<<ans2<<endl;
		}
	
	return 0;
}

/*comments on the ques: >

*/