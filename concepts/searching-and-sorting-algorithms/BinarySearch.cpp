#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;

int binary_search(int a[],int low,int high,int key)
{
	if(low<=high)
        {
		int mid=(low+high)/2;
		if(a[mid]==key)return mid;
		else if(a[mid]<key)return binary_search(a,mid+1,high,key);
		else return binary_search(a,low,mid-1,key);
	}
return -1;
}

int iter_binary_search(int a[],int low,int high,int key)
{

	int mid;
       while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)return mid;
		else if(a[mid]<key)low=mid+1;
		else high=mid-1;
	}
return -1;
}

int main()
{
  	int a[100];
	int n,key;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cin>>key;
	int index=binary_search(a,0,n-1,key);
	cout<<"index = "<<index<<endl;
	index=iter_binary_search(a,0,n-1,key);
	cout<<"index = "<<index<<endl;
return 0;  
}
