/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

#define pb push_back
#define mp make_pair
#define f(i,a, b) for (int i = a; i <= b; i++)
#define r(i,a,b) for(int i = b; i >= a; i--)
#define init1d(a,n,value) f(i,0,n)a[i]=value;
#define init2d(a,m,n,value) f(i,0,m) f(j,0,n) a[i][j]=value;
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


void print(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int n, t;
	cin>>n>>t;
	cout<<t<<endl;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = i+1;
	}
	do {
		t--;
		cout<<n<<" "<<6<<endl;
		print(a, n);
		if(t == 0) break;
  } while (next_permutation(a,a+n) );

}