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
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main(){
	int t;
	cin>>t;
	while(t--) {
		int s, w1, w2, w3;
		cin>>s>>w1>>w2>>w3;
		if (w1 > w3)  swap(w1, w3);
		if (s >= w1+w2+w3) {
			cout<<"1"<<endl;
		} else if (s >= w1+ w2) {
			cout<<"2"<<endl;
		} else {
			cout<<"3"<<endl;
		}
	}
	return 0;
}
