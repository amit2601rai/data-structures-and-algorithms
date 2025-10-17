/*Amit Rai(IIIT Hyderabad)*/
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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef set<int> si;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;
typedef priority_queue<ii, vii, greater<ii> > pminHeap;
typedef priority_queue<ii> pmaxHeap;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)
#define init_1D(a,n,value) FOR(i,0,n)a[i]=value;
#define init_2D(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define mod 1000000007

//Calculating Power
int power(int a, int b){
    LL x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y=(y*y)%mod;
        b /= 2;
    }
    return x%mod;
}


//Euler Totient
int phi(int n){
	int result = n;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0)result -= result/i;
		while(n%i == 0)n /= i;
	}
	if(n > 1)result -= result/n;
	return result;
}

//Modular Inverse
int modInverse(int a){
    return power(a,phi(1000000007)-1);
}

int main(){
	int n, k;
	cin>>n>>k;
	LL mp = 0;
	for(int i = 1; i*i <= n; i++) {
		if( n % i == 0) {
			LL phiV = phi(i);
			LL powerV = power(k, n/i);
			LL prod = phiV * powerV;
			prod %= mod;
			mp += prod;
			mp %= mod;
			if (i != n/i) {
				phiV = phi(n/i);
			    powerV = power(k, i);
			    prod = phiV * powerV;
			    prod %= mod;
			    mp += prod;
			    mp %= mod;
			}
		} 
	}
    LL modInv = modInverse(n);
	LL ans = (mp * modInv) %  mod;
	ans %= mod;
	cout<<ans<<endl;
return 0;
}
