/*input
1
0220
*/
// ideone::
 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void leadingZeros(string &s){
	for (int i = 0; i < s.length(); ++i)
	{	
		if(s[0]=='0')
			s.erase(s.begin());
		else break;
	}
}

string add(string s){
	char c = '1';
	int carry = 0;
	string ans = s;
	
	for (int i = ans.length()-1; i >= 0 ; --i)
	{
		if(carry + (c - '0') + (ans[i] - '0') > 9){
			ans[i] = char((ans[i] - '0' + c - '0' + carry)%10 + 48);
			carry = 1;  c = '0';
		}
		else{
			ans[i] = ans[i] + c - '0' + carry;
			carry = 0; c = '0';
		}
	}
	if(carry != 0) ans.insert(0, 1, '1');
	return ans;
}

int compare(string s, string nextp){
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if(s[i] > nextp[i]) return 0;
		else if(s[i] < nextp[i]) return 1;
	}
	return 0;
} 

string makeP(string s){
	string left, mid, right, ans;
	int len = s.length();
	if(len%2==0){
		left = s.substr(0,(s.length())/2);
		mid = "";
		// right = s.substr((s.length())/2,(s.length())/2);
	}
	else{
		left = s.substr(0,(s.length()-1)/2);
		mid = s.substr((s.length()-1)/2,1);
		// right = s.substr((s.length()+1)/2,(s.length()-1)/2);
	}

	right = left;
	reverse(right.begin(), right.end());
	ans.append(left);
	ans.append(mid);
	ans.append(right);
	return ans;
}

string nextP(string s){
	string left, mid, right, ans;
	int len = s.length();
	if(len%2==0){
		left = s.substr(0,(s.length())/2);
		mid = "";
		left = add(left);
	}
	else{
		left = s.substr(0,(s.length()-1)/2);
		mid = s.substr((s.length()-1)/2,1);
		if(mid[0] == '9'){ 
			mid[0] = '0';
			left = add(left);
		}
		else mid[0] = mid[0] + '1' - '0';
	}
	right = left;
	reverse(right.begin(), right.end());
	ans.append(left);
	ans.append(mid);
	ans.append(right);
	return ans;
}

string Palin(string s){
	string check, ans;
	int len = s.length();
	check = string(len, '9');
	
	if(check == s) {
		string res = string(len+1, '0');
		res[0]='1';
		res[len]='1';
		return res;
	}
	
	check = makeP(s);
	if(compare(s, check)) 
		ans = check;
	else{
		ans = nextP(s);
	}
	leadingZeros(ans);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);	

	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		cout<<Palin(s)<<endl;
	}
	return 0;
}
