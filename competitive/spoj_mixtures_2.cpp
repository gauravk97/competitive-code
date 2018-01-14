/*input
3
40 60 20
*/
#include <iostream>
using namespace std;

int Memo[101][101];

void init(){
	for (int i = 1; i < 101; ++i)
		for (int j = 1; j < 101; ++j)
			Memo[i][j] = -1;
}

int Pdt(int ar[], int a, int b){
	cout<<"PDT IN a: "<<a<<" b: "<<b<<endl;
	int result = 0;
	for(int i = a; i <= b; ++i){
		result += ar[i];
		result %= 100;
	}
	cout<<"PDT OUT result: "<<result<<endl;
	return result;
}

int DP(int ar[],int a, int b){
	cout<<"DP IN a : "<<a<<" b : "<<b<<endl;
	int result, min = -1, temp;
	
	if(Memo[a][b] != -1) result = Memo[a][b];

	else if(a==b)
		result = 0;
	else{
		for(int k = a; k < b; ++k){
			cout<<"a: "<<a<<" k: "<<k<<" min :: "<<min<<endl;
			temp = DP(ar,a,k)+DP(ar,k+1,b)+Pdt(ar,a,k)*Pdt(ar,k+1,b);
			cout<<"temp :"<<temp<<endl;
			if(min == -1) min = temp;
			if(temp<=min) min = temp;
		}
		result = min;
	}
	Memo[a][b] = result;
	cout<<"DP OUT with a : "<<a<<" b : "<<b<<" result : "<<result<<endl;
	return result;
}

int main() {
	int j;
	while(cin>>j){
		int ar[j+1];
		init();
		for(int i = 1; i < j+1; ++i)cin>>ar[i];
		cout<<"working 1"<<endl;
		cout<<DP(ar,1,j)<<endl;
		
	}


	return 0;
}