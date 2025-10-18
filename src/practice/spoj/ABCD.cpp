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

int main()
{
	int N;
	cin>>N;
	char tab[2][2*N];
	cin>>tab[0];
	for(int i=0;i<2*N;){
		int a=0,b=0,c=0,d=0;
		int k=i;
		if(tab[0][i]=='A' || tab[0][i+1]=='A')
			a=1;
		if(tab[0][i]=='B' || tab[0][i+1]=='B')
			b=1;
		if(tab[0][i]=='C' || tab[0][i+1]=='C')
			c=1;
		if(tab[0][i]=='D' || tab[0][i+1]=='D')
			d=1;	
		if(a==0)
			tab[1][i++]='A';
		if(b==0)
			tab[1][i++]='B';
		if(c==0)
			tab[1][i++]='C';
		if(d==0)
			tab[1][i++]='D';
		if(k>0){
			char temp;
			if(tab[1][k]==tab[1][k-1]){
				temp=tab[1][k];
				tab[1][k]=tab[1][k+1];
				tab[1][k+1]=temp;
			}
		}
	}
	tab[1][2*N]='\0';
	cout<<tab[1]<<endl;
	return 0;
}

