#include<iostream>
#include<cstdio>


using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=a[1];
	for(int i=2;i<=n;i++)
		ans=ans^a[i];
	cout<<ans<<endl;
	return 0;
}
