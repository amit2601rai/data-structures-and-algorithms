#include<iostream>
#include<cstdio>

#define minval -1e9
#define marker 1e9
using namespace std;

int main()
{
	int t=1;
	while(1)
	{
		int n;
		cin>>n;
		if(!n)break;
		int dp[n+1][4];
		int dp_2[n+1][4];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			  {
			    	cin>>dp[i][j];
			    	dp_2[i][j]=marker;
			  }
		}

		dp_2[1][1]=minval;
		dp_2[1][2]=dp[1][2];
		dp_2[1][3]=dp[1][2]+dp[1][3];
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(i-1>=1 && j-1>=1 && dp_2[i-1][j-1]!=minval)
				{
				   if(dp_2[i][j]==marker)	
					  dp_2[i][j]=dp[i][j]+dp_2[i-1][j-1];
				   else
					  dp_2[i][j]=min(dp_2[i][j],dp[i][j]+dp_2[i-1][j-1]);
				}
			
				if(i-1>=1 && dp_2[i-1][j]!=minval)
				{
					if(dp_2[i][j]==marker)
					   dp_2[i][j]=dp[i][j]+dp_2[i-1][j];
					else
					  dp_2[i][j]=min(dp_2[i][j],dp[i][j]+dp_2[i-1][j]);
				}
			
				if(i-1>=1 && j+1<=3 && dp_2[i-1][j+1]!=minval)
				{
					if(dp_2[i][j]==marker)
					   dp_2[i][j]=dp[i][j]+dp_2[i-1][j+1];
					else
					   dp_2[i][j]=min(dp_2[i][j],dp[i][j]+dp_2[i-1][j+1]);
			    }

				if(j-1>=1 && dp_2[i][j-1]!=minval)
				{
					if(dp_2[i][j]==marker)
					   dp_2[i][j]=dp[i][j]+dp_2[i][j-1];
					else	
					  dp_2[i][j]=min(dp_2[i][j],dp[i][j]+dp_2[i][j-1]);
				}
				if(dp_2[i][j]==marker)
					dp_2[i][j]=minval;
			}
		}		

/*		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<dp_2[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<t<<". "<<dp_2[n][2]<<endl;
		t++;
	}
	return 0;
}

