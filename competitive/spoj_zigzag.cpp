/*input
6
6 1 7 4 9 2 5
10 1 17 5 10 13 15 10 5 16 8
1 44
9 1 2 3 4 5 6 7 8 9
19 70 55 13 2 99 2 80 80 80 80 100 19 7 5 5 5 1000 32 32
50 374 40 854 203 203 156 362 279 812 955 600 947 978 46 100 953 670 862 568 188 67 669 810 704 52 861 49 640 370 908 477 245 413 109 659 401 483 308 609 120 249 22 176 279 23 22 617 462 459 244
*/

#include <iostream>
using namespace std;

// class ZigZag
// {
// public:
// 	ZigZag();
// 	~ZigZag();
	

int isPositive(int diff){
	if(diff>0)return 1;
	else if(diff ==0) return 0;
	else if(diff<0) return -1;

	}

// };
int longestZigZag(int seq[],int nOfElements){
	
	if (nOfElements<=2)
	{
		return nOfElements;
	}
	//init these \/ 2 arrays
	int S[nOfElements], sign[nOfElements], max=0, diff, currentsign;
	for (int i = 0; i < nOfElements; ++i)
	{
		S[i]=0;
		sign[i]=1000;
	}



	for (int i = 0; i < nOfElements; ++i)
	{
		S[i]=1;
		for (int j = 0; j < i; ++j)
		{
			diff=  seq[j]-seq[i];
			currentsign = isPositive(diff);
			if (j == 0){
				if(currentsign>0) sign[j]=-1;
				else if(currentsign<0) sign[j]=1;
			}
			if ( (currentsign==(-1)*sign[j]) && currentsign)
			{

				if(S[j]+1>S[i]) { S[i]=S[j]+1; sign[i]=currentsign;}
			}

			//cout<<currentsign<<"  "<<sign[i]<<"  "<<diff<<"  "<<i<<"  "<<j<<endl;
		}

		if(max<S[i])max = S[i];
	
	}


	return max;
	}



int main(){
	int t,nOfElements;
	cin>>t;
	while(t--){
		cin>>nOfElements;
		int seq[nOfElements];
		for (int i = 0; i < nOfElements; ++i)
		{
			cin>>seq[i];
		}

		cout<<longestZigZag(seq,nOfElements)<<endl;


	}


}