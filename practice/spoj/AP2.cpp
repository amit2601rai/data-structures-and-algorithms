#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		long long int x,y,sum;
		cin>>x>>y>>sum;
		long long n,a,d;
		n=(sum*2)/(x+y);
		d=(x-y)/(5-n);
		a=x-2*d;
		cout<<n<<endl;
		for(int i=1;i<=n;i++)printf("%lld ",a+(i-1)*d);
                cout<<endl;
	}
return 0;
}

