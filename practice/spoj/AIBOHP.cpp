//Author:Amit

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define fill(a,v) memset(a,v,sizeof a)

using namespace std;

int lcs(char *x,char *y,int n)
{
    int *a,*b,*c;
    a=new int[n+1];
    b=new int[n+1];
    fill(a,0);
    fill(b,0);
    for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
	    {
	       if(x[i-1]==y[j-1])
		  b[j]=a[j-1]+1;
               else
                  b[j]=max(a[j],b[j-1]);
           }
          c=b;
          b=a;
          a=c;
      }		
return a[n];
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
	{
	  char x[7000],y[7000];
          scanf("%s",x);
          n=strlen(x);
	  for(int i=n-1;i>=0;i--)
              y[n-1-i]=x[i];
              y[n]='\0';
          cout<<n-lcs(x,y,n)<<endl;
	}
   return 0;
}

