/*input
2

aba

ab
*/

#include <iostream>
#include <cstring>
using namespace std;

bool magi(string str){
	int n = str.length(),t=1,j;

	for(int i = 0;i<n/2;++i){
		j=n-i-1;
		if(str[i]!=str[j]){t=0;break;}
	}
	return t;
}

int main() {
	int t;
	string str, ans = "NO";
	bool magic;
	cin>>t;
	while(t--){
		cin>>str;
		magic = magi(str);
		if(magic){ ans = "YES";}
		else ans = "NO";
		cout<<ans<<endl;
	}
	return 0;
}

