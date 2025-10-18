#include<iostream>

using namespace std;

int main()
{
   	while(1)
	{
 	    int n,k;
	    cin>>n>>k;
	    if(n==0&&k==0)break;
	     int p=1,q;
	   for(int i=1;i<=n;i++)
	       {
                   q=(p+k-1)%i+1;
                   p=q;
               }              
           cout<<n<<" "<<k<<" "<<p<<endl;
      }
return 0;
}

