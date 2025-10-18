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

struct triplet {
	int i, j, k;
};

void print(vector<triplet> triplets) {
	f(idx, 0, triplets.size()-1) {
		cout<<triplets[idx].i<< " "<<triplets[idx].j<<" "<<triplets[idx].k<<endl;
	}
}

void rightCyclicShift(int v[], int i, int j, int k, vector<triplet> &triplets, int &K) {
	int tmp = v[k];
	v[k] = v[j];
	v[j] = v[i];
	v[i] = tmp;
	triplet t;
	t.i = i;
	t.j = j;
	t.k = k;
	triplets.pb(t);
	K--;
}

void mergeCycles(int v[], int &x, int &y, int i, int j, vector<triplet> &triplets, int &K) {
	if(x == 0 && y == 0) {
		x = i;
		y = j;
		return;
	}

	rightCyclicShift(v, x, i, y, triplets, K);

	rightCyclicShift(v, y, j, i, triplets, K);
	
	x = 0;
	y = 0;
}

bool isSorted(int v[], int n) {
	f(i,2,n) {
		if(v[i-1] + 1 != v[i]) return false;
	}
	return true;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, K;
		cin>>n>>K;
		int v[n+1];
		f(i, 1, n) {
			cin>>v[i];
		}
		vector<triplet> triplets;
		int i = 1;
		while(K > 0 && i <= n) {
			int j = v[i];
			int k = v[j];
			if(i != k) {
				rightCyclicShift(v, i, j, k, triplets, K);

			} else {
				i++;
			}
		}

        i = 1;
		int x = 0, y = 0;
		while(K > 0 && i <= n) {
			int j = v[i];
			int k = v[j];
			if(i == k && i != j && y != i) {
				mergeCycles(v, x, y, i, j, triplets, K);
			}
			i++;
		}

		if(isSorted(v, n)) {
			int s = triplets.size();
			cout<<s<<endl;
			if(s > 0) print(triplets);
		} else {
			cout<<"-1"<<endl;
		}
	}
return 0;
}