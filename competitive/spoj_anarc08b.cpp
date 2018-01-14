/*input
010079010+010079=
106010+010=
107107107+107107=
010093079106103+119011127107063=
BYE
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
string n1, n2;
 
void parseString(string str){
	n1.clear(); n2.clear();
	int l = str.length(), ctr1=0, ctr2=0;
	for(int i = 0; i < l; ++i){
		if(str[i]=='+')ctr1 = 1;
		else if(str[i]=='=')ctr2 = 1;
		else if(!ctr1){
			n1.push_back(str[i]);
		}
		else if(!ctr2){
			n2.push_back(str[i]);
		}
		// else cout<<"check"<<endl;
	}
}
 
int createNo(string s1){
	string sub;
	int len = s1.length(), noDig = len/3, dig[noDig], i = 0, j = 0, num = 0;
	while(i < len){
		sub = s1.substr(i,3);
		// cout<<"substring :"<<sub<<endl;
		if(sub == "063") dig[j] = 0;
		else if(sub == "010") dig[j] = 1;
		else if(sub == "093") dig[j] = 2;
		else if(sub == "079") dig[j] = 3;	
		else if(sub == "106") dig[j] = 4;
		else if(sub == "103") dig[j] = 5;
		else if(sub == "119") dig[j] = 6;
		else if(sub == "011") dig[j] = 7;
		else if(sub == "127") dig[j] = 8;	
		else if(sub == "107") dig[j] = 9;	
 
		i+=3;
		++j;
	}
	
	for(int k = noDig-1, l = 0; k >= 0; --k, ++l){
		num += dig[k]*pow(10,l); 
	}	
	return num;
}//from three char strings
 
string convert(int p){
	string result, str; result.clear();
	int dig = log10(p)+1, t = 0, q;
	for (int i = 0, j = dig-1; i < dig; ++i, j--)
	{
		q = pow(10,j);
		t = p / q % 10;
		switch(t){
			case 0: str = "063"; break;
			case 1: str = "010"; break;
			case 2: str = "093"; break;
			case 3: str = "079"; break;
			case 4: str = "106"; break;
			case 5: str = "103"; break;
			case 6: str = "119"; break;
			case 7: str = "011"; break;
			case 8: str = "127"; break;
			case 9: str = "107"; break;
		}
		result.append(str);
	}
	return result;
} 
 
int main() {
	string str;
	cin>>str;
	while(str != "BYE"){
 
		parseString(str);

		int res = createNo(n1)+createNo(n2);
		// cout<<res<<endl;
		string s = convert(res);
 		cout<<str<<s<<endl;
		cin>>str;
	}
	return 0;
}