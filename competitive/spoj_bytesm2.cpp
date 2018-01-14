#include <bits/stdc++.h>

using namespace std;

int withoutpadding(){
	int h, w;
	cin>>h>>w;
	int matrix[h][w], score[h][w]={0}, result;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin>>matrix[i][j];
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if(i>0 && j>0 && j<w-1){
				score[i][j] = matrix[i][j]+max(max(score[i-1][j], score[i-1][j-1]),score[i-1][j+1]);
			}
			
			else if(i>0 && j==w-1){
				score[i][j] = matrix[i][j]+max(score[i-1][j], score[i-1][j-1]);	
			}

			else if(i>0 && j==0){
				score[i][j] = matrix[i][j]+max(score[i-1][j], score[i-1][j+1]);	
			}

			else if(i==0){
				score[i][j] = matrix[i][j];	
			}
			else {
				cout<<"dafuq"<<endl;
			}
		}

	}
	for (int i = 0; i < w; ++i)
	{
		if(score[h-1][i]>result)result=score[h-1][i];
	}
	return result;
}

int withpadding(){
	int h, w;
	cin>>h>>w;
	int matrix[h+1][w+2], score[h+1][w+2], result=0;
	for (int i = 0; i < h+1; ++i)
	{
		
		for (int j = 0; j < w+2; ++j)
		{
			score[i][j]=0;
			if(i==0) matrix[i][j]=0;
			else if(j==w+1 || j==0) matrix[i][j]=0;
			else cin>>matrix[i][j];
		}
	}
	// for (int i = 0; i < h+1; ++i)
	// {
	// 	for (int j = 0; j < w+2; ++j)
	// 	{
	// 		// cout<<matrix[i][j]<<" ";
	// 		// score[i][j]=0;
	// 	}
	// 	// cout<<endl;
	// }

	for (int i = 1; i < h+1; ++i)
	{
		for (int j = 1; j < w+1; ++j)
		{
			score[i][j] = matrix[i][j]+max(max(score[i-1][j], score[i-1][j-1]),score[i-1][j+1]);
		}
	}
	// cout<<"afterwards "<<endl;
	// for (int i = 0; i < h+1; ++i)
	// {
	// 	for (int j = 0; j < w+2; ++j)
	// 	{
	// 		cout<<score[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for (int i = 0; i < w; ++i)
	{
		if(score[h][i]>result)result=score[h][i];
	}
	return result;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int result = withpadding();
		cout<<result<<endl;
	}
	return 0;
}

