int n1 = q-p+1, n2 = r-q+1, L[n1+1], R[n2+1];
	cout<<"merge called:"<<endl;
	cout<<"n1 :"<<n1<<" n2:"<<n2<<" p:"<<p<<" q:"<<q<<" r:"<<r<<endl;

	// for (int i = p; i <= r; ++i)
	// {
	// 	cout<<A[i]<<endl;
	// }

	for (int i = 1; i <= n1; ++i)
	{	L[i] = A[p+i-1];
		cout<<"i: "<<i<<" :"<<L[i]<<endl;		
	}
	for (int i = 1; i <= n2; ++i)
	{	R[i] = A[q+i];
		cout<<"i: "<<i<<" :"<<R[i]<<endl;
	}
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	int i = 1, j = 1;

	// for (int i = 0; i <= n1; ++i)
	// {cout<<L[i]<<"  :";
	// }
	// cout<<"\n";
	// for (int i = 0; i <= n2; ++i)
	// {
	// 	cout<<R[i]<<"  :";
	// }
	// cout<<endl;

	for (int k = p; k <= r ; ++k)
	{
		if(L[i]<=R[j])
		{
			A[k] = L[i];
			++i;
		}
		else
		{
			A[k] = R[j];
			++j;
		}
	}
	cout<<"merge : ends"<<endl;



while((l<=mid)&&(j<=high))
{
	if(a[h]<=a[j]){
		b[i] = a[h];
		++h;
	}
	else
	{
		b[i] = a[j];
		++j;

	}
	++i;


}

if(h>mid){
	for (int k = h; k <= high ; ++k)
	{
		b[i] = A[k];
		i++;
	}
}
else{
	for (int k = 0; k <= mid ; ++k)
	{
		b[i] = A[k];
		++i;
	}
}

for (int i = low; i <= high; ++i)
{
	A[k] = b[k];
}
