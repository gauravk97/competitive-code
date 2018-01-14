/*input
4
*/

#include <bits/stdc++.h>

using namespace std; 
typedef unsigned long long ull;

void strEq(string& s1, string& s2){
	int l1 = s1.length(), l2 = s2.length();
	while(l1>l2){
		s2.insert(0, 1, '0');
		l2 = s2.length();
	}
	while(l1<l2){
		s1.insert(0, 1, '0');
		l1 = s1.length();
	}

}


string addStr(string s1, string s2){
	string res = s1;
	int nDig = s1.length(), carry = 0, A;
	char c;
	for (int i = nDig-1; i >= 0; --i)
	{
		A = s1[i] - '0' + s2[i] - '0' + carry;
		// cout
		carry = A/10;
		A = A % 10;
		c = A + 48;
		res[i] = c;
	}
	if(carry) res.insert(0, 1, '1');
	return res;
}

string subStr(string s1, string s2){
	string res = s1;
	int nDig = s1.length(), borrow = 0, B, given = 0;
	char c;
	for (int i = nDig-1; i >= 0; --i)
	{	
		if (s1[i] - s2[i] - given < 0)
			borrow = 10;
		else borrow = 0;
		
		B = s1[i] - s2[i] - given + borrow;
		
		if (borrow)	given = 1;
		else given = 0;
		
		c = B + 48;
		res[i] = c;

	}
	while(res.front() == '0') res.erase(res.begin());

	return res;
}

int main() {
	ios::sync_with_stdio(false);	
	string s1 = "99999", s2 = "90000";
	strEq(s1, s2);

	cout<<s1<<endl;
	cout<<s2<<endl;
	// cout<<s1.front()<<endl;

	cout<<subStr(s1, s2)<<endl;

	return 0;
}