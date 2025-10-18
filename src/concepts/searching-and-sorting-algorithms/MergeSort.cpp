#include<iostream>
#include<cstdio>

using namespace std;

void print(int a[],int low,int high){
	for(int i=low;i<=high;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void merge(int a[],int low,int mid,int high){
	int m=mid-low+1;
	int n=high-mid;
	int b[m];
	int c[n];
	for(int i=low;i<=mid;i++)
		b[i-low]=a[i];
	for(int i=mid+1;i<=high;i++)
	    c[i-mid-1]=a[i];
	int i=0,j=0,k=low;
	while(i<m&&j<n){
		if(b[i]<c[j]){
			a[k++]=b[i];
			i++;
		}
		else{
			a[k++]=c[j];
			j++;
		}
	}
    while(i<m){
		a[k++]=b[i];
		i++;
	}
	while(j<n){
		a[k++]=c[j];
		j++;
	}
}

void mergesort(int a[],int low,int high){
	int mid;
 	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	print(a,0,n-1);
return 0;
}
