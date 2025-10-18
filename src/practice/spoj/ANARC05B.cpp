/*Author: Amit(IIIT-H)*/
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>

using namespace std;
 
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n) 
#define sl(n) scanf("%lld",&n) 
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF MAX_INT
#define all(v) v.begin(), v.end()
#define fill_1(x,v,n)for(int i=0;i<n;i++)x[i]=v
#define fill_2(x,v,m,n) for(int i=0;i<m;i++)for(int j=0;j<n;j++)x[i][j]=v

typedef long long ll;


/*main code starts from here*/

int main()
{
	while(1)
	{
		int counting[20001];
		int index_1[20001];
		int index_2[20001];
		fill_1(counting,0,20001);
		fill_1(index_1,0,20001);
		fill_1(index_2,0,20001);
        int m,n,x;
		cin>>m;
		if(!m)break;
		int a[m+1];
		fill_1(a,0,m+1);
		for(int i=1;i<=m;i++)
		{
			cin>>x;
			counting[x+10000]++;
			index_1[x+10000]=i;
            a[i]=a[i-1]+x;
		}
       cin>>n;
	   int b[n+1];
	   fill_1(b,0,n+1);
	   for(int i=1;i<=n;i++)
	   {
	   		cin>>x;
			counting[x+10000]++;
			index_2[x+10000]=i;
			b[i]=b[i-1]+x;
	   }
	     int prev_index_1=0,prev_index_2=0,k=1,temp1,temp2,temp3,temp4;
		 int ans[10001],flag=0;
		 fill_1(ans,0,10001);
	   for(int i=0;i<20001;i++)
	   {
	   		if(counting[i]==2 && flag==0)
			{
				  temp1=index_1[i];
				  temp2=index_2[i];
                  ans[k]=max(a[temp1],b[temp2]);
				  prev_index_1=temp1;
				  prev_index_2=temp2;
                  flag++;
				  k++;
			}
			else if(counting[i]==2)
			{
				   temp1=index_1[i];
				   temp2=index_2[i];
				   temp3=a[temp1]-a[prev_index_1];
				   temp4=b[temp2]-b[prev_index_2];
				   ans[k]=max(ans[k-1]+temp3,ans[k-1]+temp4);
				   prev_index_1=temp1;
				   prev_index_2=temp2;
				   k++;
			}
	    }
	     temp1=ans[k-1];
		 temp2=ans[k-1];
	     int flag1=0,flag2=0;
		 if(m>prev_index_1)
			temp1=ans[k-1]+a[m]-a[prev_index_1];
		 if(n>prev_index_2)
		    temp2=ans[k-1]+b[n]-b[prev_index_2];
        cout<<max(temp1,temp2)<<endl;
	}
	return 0;
}

