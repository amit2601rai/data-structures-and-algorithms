#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define tr(c, val) for (const auto &val : c)
#define ispresent(c, val) if(c.find(val) != c.end())
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

#define MAX 1000005
vi primes(MAX);

void sieve(){
    for (int i = 2; i < MAX; i++) primes[i] = i;
	for(int i = 2; i*i < MAX ; i++){
		if(primes[i] == i){
			for(int j = i*i ; j < MAX ; j++) {
                if(j%i == 0) primes[j] = i;
            }
		}
	}
}

int main(){
	int t;
	cin>>t;
	sieve();
    while (t--) {
        int n, e;
        cin >> n >> e;
        vi nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        vi trackone(n, 0);
        vi dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                trackone[i] = 1;
                if (i - e >= 0) {
                    trackone[i] += trackone[i-e];
                    dp[i] = dp[i-e];
                    if (primes[nums[i-e]] == nums[i-e]) {
                        dp[i]++;
                    } 
                }
            } else if (primes[nums[i]] == nums[i]) {
                if (i - e >= 0) {
                    if (primes[nums[i-e]] != nums[i-e] && trackone[i-e] > 0) {
                        dp[i] = trackone[i-e];
                    } 
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += dp[i];
        cout << ans << endl;
    }	
return 0;
}