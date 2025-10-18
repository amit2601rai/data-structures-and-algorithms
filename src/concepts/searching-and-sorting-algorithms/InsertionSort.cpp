#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void insertionsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && a[j]>=temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}

}

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	insertionsort(a,n);
	print(a,n);
return 0;
}
