/*input
3
23 + 47 = machula
3247 + 5machula2 = 3749
machula13 + 75425 = 77038
*/
 
#include <bits/stdc++.h>

using namespace std; 

bool findS(string& s, string& f){
	for (int i = 0; i < s.length(); ++i)
		if(s[i]==f[0]) return 1;
	return 0;
}
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
string addS(string s1, string s2){
	string res = s1;
	int nDig = s1.length(), carry = 0, A;
	char c;
	for (int i = nDig-1; i >= 0; --i)
	{
		A = s1[i] - '0' + s2[i] - '0' + carry;
		carry = A/10;
		A = A % 10;
		c = A + 48;
		res[i] = c;
	}
	if(carry) res.insert(0, 1, '1');
	return res;
}

string subS(string s1, string s2){
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
	int tc;
	cin>>tc;
	string q, w, e, r, t, key = "machula", s1, s2;
	while(tc--){
		cin>>q>>w>>e>>r>>t;
		if(findS(q, key)){
			s1 = t; s2 = e;
			strEq(s1, s2);
			q = subS(s1, s2);
		}
		else if(findS(e, key)){
			s1 = t; s2 = q;
			strEq(s1, s2);
			e = subS(s1, s2);
		}
		else if(findS(t, key)){
			s1 = q; s2 = e;
			strEq(s1, s2);
			t = addS(s1, s2);
		}

		cout<<q<<" "<<w<<" "<<e<<" "<<r<<" "<<t<<endl;
	}
	return 0;
}
