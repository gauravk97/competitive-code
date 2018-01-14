/*input

*/

// question::
// ideone::
// #include <unordered_map>

#include <bits/stdc++.h>

using namespace std;

std::unordered_map<char, int> m;

void processStr(string s){
	for (int i = 0; i < s.length(); ++i)
		m.insert(make_pair(s[i], 1));
}

string processStr2(string s){
	for (int i = 0; i < s.length(); ++i)
		{if(m.find(s[i]) == m.end())
			{
				return "No\n";
			}
		}
	return "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);	
	string s;
	int t;
	cin>>s;
	processStr(s);
	cin>>t;
	

	string s1;
	while(t--){
		cin>>s1;
		cout<<processStr2(s1);	
	}
	
	return 0;
}

/*comments on the ques: >

*/