/*input
141240110
0
*/
#include <bits/stdc++.h>

using namespace std;
int a[5001];

void init(){
	for (int i = 0; i < 5001; ++i)
		a[i] = -1;
}

int Rec(string s, int start){
	int res = 0, res1 = 0, res2 = 0, len = s.length() - start  ;
	if (len<=0 || s[0] == '0'){
		a[start] = 0;
		return 0;
	}
	else if (a[start] != -1){
		return a[start];
	}
	else if (len == 1 ){	
		a[start] = 1;
		return 1;
	}
	else if( len == 2 && (( s[start]<'2' && '0'<=s[start] ) || ( s[start] == '2' && s[start + 1]<'7' && '0'<=s[start + 1]))){
		res1++;
	}

	if(len>1){
		if (s[start + 1] != '0')
			res1 += Rec(s, start + 1);
		
		if( (s[start + 2] != '0') && ((s[start]!='2' && s[start]<'3' && '0'<=s[start] )||( s[start] == '2' && s[start + 1]<'7' && '0'<=s[start + 1])) ){
				res2 += Rec(s, start + 2);
			}
	}
	res = res1 + res2;
	a[start] = res;
	return  res;
}

int main() {
	ios::sync_with_stdio(false);	
	string t;
	cin>>t;
	// t = "";
	while(t != "0"){
		init();
		cout<<Rec(t, 0)<<endl;
		cin>>t;
	}
	return 0;
}

