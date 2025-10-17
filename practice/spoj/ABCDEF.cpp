#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long long int64;
#define For(i,x) for(int i=0;i<x;i++)
#define Forr(i,y,x) for(int i=y;i>=x;i--)
#define Forn(i,y,x) for(int i=y;i<=x;i++)
 
int N;
int Array[101];
int A[1000009];
int B[1000009];
int main()
{
	scanf("%d",&N);
	For(i,N)
	{
		scanf("%d",&Array[i]);
	}
	int l=0,l1=0;
	For(i,N)
	{
		For(j,N)
		{
			For(k,N)
			{
				A[l++]=Array[i]*Array[j]+Array[k];
				if(Array[i]!=0)B[l1++]=Array[i]*(Array[j]+Array[k]);
			}
		}
	}
	sort(A,A+l);
	sort(B,B+l1);
	int64 ans = 0;
	int i=0 , j = 0;
	for (;i<l && j<l;)
	{
		while(A[i]!=B[j] && i<l && j<l)
		{
			if(A[i]<B[j])i++;
			else j++;
		}
		if(i>=l || j>=l)continue;
		{
			int cnt1 = 1 , cnt2 = 1;
			while(i+cnt1<l && A[i+cnt1]==A[i])cnt1++;
			while(j+cnt2<l && B[j+cnt2]==B[j])cnt2++;
			i+=cnt1;
			j+=cnt2;
			ans = ans + (cnt1*cnt2);
		}
	}
	cout << ans << endl;
	return 0;
}

