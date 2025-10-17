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

void preProcess(string &a, string &b) {
	if(a.size() >= b.size()) {
		b.insert(0, a.size() - b.size(), '0');
	} else {
		a.insert(0, b.size() - a.size(), '0');
	}
}

int countWhileLoops(string a, string b) {
	if(b.find("1") == -1) return 0;
	int n = a.size();
	bool flag = false;
	int loopWindowSize = 0;
	int maxLoopWindowSize = 0;
	r(i, 0, n-1) {
		if(a[i] == '1' && b[i] == '1') {
			loopWindowSize = 1;
			flag = true;
		}
		else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')) {
			if(flag) loopWindowSize++;
		} 
		else{
			loopWindowSize = 0;
			flag = false;
		} 
		 maxLoopWindowSize = max(loopWindowSize, maxLoopWindowSize);
	}
	return ++maxLoopWindowSize;
}

int main(){
	int T;
	cin>>T;
	while(T--) {
		string a, b;
		cin>>a>>b;
		preProcess(a,b);
		int loops = countWhileLoops(a, b);
		cout<<loops<<endl;
	}
	return 0;
}