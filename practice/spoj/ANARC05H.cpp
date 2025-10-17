//@uthor : Amit Rai (IIIT-H)

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
#include<climits>

#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n) 
#define sl(n) scanf("%lld",&n) 
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF MAX_INT
#define LINF MAX_LONG
#define all(v) v.begin(), v.end()
#define fil(x,v,n)for(int i=0;i<n;i++)x[i]=v
#define fill(x,v,m,n) for(int i=0;i<m;i++)for(int j=0;j<n;j++)x[i][j]=v

typedef long long LL;

using namespace std;

struct node{
			int sum;
			int prev_sum;
			bool flag;
};

int cal(char num[50])
{
	int val,len;
	int n=strlen(num);
	vector<struct node>dp[n];
	struct node v;
	v.prev_sum=0;
	v.sum=num[0]-48;
	v.flag=1;
	dp[0].pb(v);
	for(int i=1;i<n;i++)
	{
		val=num[i]-48;
		len=dp[i-1].size();
	    for(int j=0;j<len;j++)
	    {
			//if group is valid
			  struct node a,b;
			if(dp[i-1][j].flag==1)
			{

				a.sum=val;
				a.prev_sum=dp[i-1][j].sum;
				if(val>=dp[i-1][j].sum)
					a.flag=1;
				else 
					a.flag=0;
				dp[i].pb(a);


				b.sum=val+dp[i-1][j].sum;
				b.prev_sum=dp[i-1][j].prev_sum;
				b.flag=1;
				dp[i].pb(b);
			}
		   else//group is not valid
		    {
				 struct node a;
				 a.sum=val+dp[i-1][j].sum;
				 a.prev_sum=dp[i-1][j].prev_sum;
				 if(a.sum>=a.prev_sum)
					  a.flag=1;
				 else 
					  a.flag=0;
				 dp[i].pb(a);
		    }
        }
     }
	int ans=0;
	int siz=dp[n-1].size();
	for(int j=0;j<siz;j++)
		if(dp[n-1][j].flag==1)
		   ans++;
	return ans;
}


int main()
{
	int k=1;
	while(1){
		char num[50];
		ss(num);
		if(strcmp("bye",num)==0)break;
		cout<<k<<". "<<cal(num)<<endl;
		k++;
	}
	return 0;
}

