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

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		string input;
		cin>>input;
		int len = input.size();
		vector<int> freq[k];
		int ans = 0;
		for(int i = 1; i <= k; i++) {
			int c = i-1;
			int total = 0;
			int maxFreq = INT_MIN;
			//k period
			while(c < len) {
				if(freq[i-1].size() == 0) {
					vi v(27, 0);
					v[input[c]-97]++;
					freq[i-1] = v;
					maxFreq = max(maxFreq, freq[i-1][input[c]-97]);
					total++;
					
				} else {
					freq[i-1][input[c]-97]++;
					maxFreq = max(maxFreq, freq[i-1][input[c]-97]);
					total++;
				}
				c += k;
			}

			//cover palindrome
			c = n - i;
			while(c >=0 ) {
				freq[i-1][input[c]-97]++;
				maxFreq = max(maxFreq, freq[i-1][input[c]-97]);
				total++;
				c -= k;
			}
			ans += (total - maxFreq);
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
