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



int bsl(int l, vector<pair<int,int>> v) {
	int low = 0, high = v.size() - 1;
	while (high - low > 1) {
		int mid = (low + high)/2;
		if (v[mid].first == l) return mid;
		else if(v[mid].first < l) low = mid + 1;
		else high = mid;
	}
	if(v[high].first > l) {
		return low;
	} else {
		return high;
	}
}


int bsr(int r, vector<pair<int,int>> v) {
	int low = 0, high = v.size() - 1;
	while (high - low > 1) {
		int mid = (low + high)/2;
		if (v[mid].second == r) return mid;
		else if(v[mid].second < r) low = mid + 1;
		else high = mid;
	}
	if(v[low].second > r) {
		return low;
	} else {
		return high;
	}
}

int numOfSeq(int l, int r, int seqL, int seqR, vector<pair<int, int>>v) {
	cout<<"l="<<l<<"r="<<r<<"seqL ="<<seqL<<"seqR = "<<seqR<<endl;
	int num = 0;
	if (seqL == seqR) {
		if (v[seqL].first != v[seqL].second) {
			num++;
		}
	} else {
		if (!(l == v[seqL].second || v[seqL].first == v[seqL].second)) {
			num++;
		}
		if (!(r == v[seqR].first || v[seqR].first == v[seqR].second)) {
			num++;
		}
		num += (seqR - seqL - 1);
	}
	cout<<"num ="<<num<<endl;
	return num;
}

 
bool isEqual(int l, int r, vector<pair<int, int>> vi, vector<pair<int, int>> vd) {
	int incL = bsl(l, vi);
	int incR = bsr(r, vi);
	
	int decL = bsl(l, vd);
	int decR = bsr(r, vd);
	
	return (numOfSeq(l, r, incL, incR, vi) == numOfSeq(l, r, decL, decR, vd));
}

int main(){
	int n, q;
	cin>>n>>q;
	vector<int>inc(n);
	vector<int>dec(n);
	int prev = 0;
	f (i, 0, n-1) {
		int val;
		cin>>val;
		if (prev == 0) {
			inc[i] = dec[i] = 0;
		} else {
			
		}
	}
	return 0;
}
