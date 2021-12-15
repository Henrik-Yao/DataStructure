#include<iostream>
using namespace std;

void Qsort(int *arr,int begin,int end){
	if(begin>end) return;
	int temp=arr[begin];
	int i=begin;
	int j=end;
	while (i!=j)
	{
		while(arr[j]>=temp&&j>i) j--;
		while(arr[i]<=temp&&j>i) i++;
		if(j>i){
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}	
	}
	arr[begin] = arr[i];
	arr[i] = temp;
	Qsort(arr,begin,i-1);
	Qsort(arr,i+1,end);
	
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Qsort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}
