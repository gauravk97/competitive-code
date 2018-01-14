/*input
3
a1 c2
a1 h8
h8 c3
*/

// question::
// ideone::
 
#include <bits/stdc++.h>
// #include <string>
using namespace std; 
typedef vector<int> VI;  typedef vector<vector<int> > VVI; 
typedef vector<string> VS;  typedef vector<vector<string> > VVS; 
typedef signed long long i64;  typedef unsigned long long u64; 

bool checkLimit(int n){
	// cout<<"string input ::"<<s<<endl;
	if( 1 <= n%10 && n%10 <= 8 && n/10 <= 8 && 1 <= n/10)
	{	
		// cout<<"passed ::"<<s<<endl;
		return 1;
	}
	else { 
		// cout<<"check string/"<<endl;
	}
	return 0;
}


int level[101];

void Init(){
	for (int i = 0; i < 101; ++i)
	{
		level[i] = -1;
	}
}



int Nakanj(int n1, int n2){

	Init();
	queue<int> toExplore;
	toExplore.push(n1);
	level[n1] = 0;
	int  pop;
	while(!toExplore.empty()){
		pop = toExplore.front();
		// cout<<"popped string S :"<<s<<endl;
		toExplore.pop();
		int Next[8] = {pop+12, pop+21, pop+19, pop+8, pop-8, pop-12, pop-19, pop-21};
		for (int i = 0; i < 8; ++i)
		{
			if (checkLimit(Next[i]) && level[Next[i]] == -1)
			{
				toExplore.push(Next[i]);
				level[Next[i]] = level[pop] + 1;

			}
		}

		
		if (pop == n2)
			{
				return level[pop];
			}	
	}


	
}

int main() {
	ios::sync_with_stdio(false);	

	int t;
	string s1, s2;
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		int a = 10*(s1[0]-'a'+1) + (s1[1] - '1' +1), b =10*(s2[0] -'a' +1) + (s2[1] - '1' +1);	
		cout<<Nakanj(a,b)<<endl;
	}
	return 0;
}

/*comments on the ques: >
fucking string parsing, I suck at dealing with strings

*/

/*
my initial foolishness
if(s == s2) return d;
		d++;
		cout<<d<<endl;
		sNext = s;
		sNext[0] += 2;
		sNext[1] += 1;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] += 2;
		sNext[1] -= 1;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] -= 2;
		sNext[1] += 1;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] -= 2;
		sNext[1] -= 1;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] += 1;
		sNext[1] += 2;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] += 1;
		sNext[1] -= 2;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] -= 1;
		sNext[1] += 2;
		if(checkLimit(sNext))Q.push(sNext);
		sNext = s;
		sNext[0] -= 1;
		sNext[1] -= 2;
		if(checkLimit(sNext))Q.push(sNext);
	
yp*/