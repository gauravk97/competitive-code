/*input
*/


#include <bits/stdc++.h>

using namespace std;

// vector<string> convertToStrings(vector<int> powers){
	// for(int i = 0; i<powers.size(); ++i){

	// }
// }

vector<int> breakIntoPowers(int a){
	int r = a, t;
	vector<int> res;
	while(r>1){
		t = pow(2, floor(log2(r)));
		r = r%t;
		res.push_back(t);
	}
	if(r == 1)res.push_back(1);
	return res;
}


void convert(int a){
	// cout<<"Rec convert start a = "<<a<<endl;
	vector<int> v = breakIntoPowers(a);
	for (int i = 0; i < v.size(); ++i)
	{
		int t = log2(v[i]);
		if(t>2){ 
			if(i == 0)cout<<"2(";
			else cout<<"+2(";
			convert(t);
			cout<<")";
		}
		else if(t == 2){
			if(i == 0)cout<<"2(2)";
			else cout<<"+2(2)";
		}
		else if(t == 1) {
			if(i == 0)cout<<"2";
			else cout<<"+2";
			// cout<<"  t = "<<t<<endl;
		} 
		else if(t == 0) {
			if(i == 0)cout<<"2(0)";
			else cout<<"+2(0)";
		}
	}
	// cout<<"Rec ends a = "<<a<<endl;
}


int main()
{
	ios::sync_with_stdio(false);

	int arr[7] ={137, 1315, 73, 136, 255, 1384, 16385};
	// vector<int> v = breakIntoPowers(t);

	// for (int i = 0; i < v.size(); ++i)
	// {
		// cout<<v[i]<<" ";
	// }
	for (int i = 0; i < 7; ++i)
	{
		cout<<arr[i]<<"=";
		convert(arr[i]);
		cout<<endl;
	}
	return 0;
}