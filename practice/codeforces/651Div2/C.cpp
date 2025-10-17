/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair

bool isEven(int x) {
	return ((x^1) == x+1);
}

bool is2pow(int x) {
	return ((x & (x-1)) == 0);
}

bool isPrime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(n == 1) cout<<"FastestFinger"<<endl;
		else if(n == 2) cout<<"Ashishgup"<<endl;
		else if (is2pow(n) || (isEven(n) && isPrime(n/2))) cout<<"FastestFinger"<<endl;
	    else cout<<"Ashishgup"<<endl; 
	}
	return 0;
}
