/*input
16
99999999999999
3
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std;

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
	// cout<<"l :"<<nDig<<endl;
	char c;
	for (int i = nDig-1; i >= 0; --i)
	{	
		// cout<<s1[i]<</" :"<<s2[i]<<endl;
		A = s1[i] - '0' + s2[i] - '0' + carry;
		// cout<<A<<endl;
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
	// while(res.front() == '0') res.erase(res.begin());

	return res;
}

string str(string s){
	string s2 = "2", s4;
	strEq(s, s2);
	s4 = addS(s, subS(s, s2));
	return s4;
}

int main() {
	ios::sync_with_stdio(false);	

	string t, n;
	while(cin>>t){
		if(t == "0")cout<<"0"<<endl;
		else if(t == "1")cout<<"1"<<endl;
		else cout<<str(t)<<endl;
	}

	
	return 0;
}

/*comments on the ques: >

*/