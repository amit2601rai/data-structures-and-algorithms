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


int main(){
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<vector<int> > input(2, vector<int>(m, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> input[i][j];
                if (j-1 >= 0)input[i][j] += input[i][j-1];
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            //j+1 -> m-1
            // 0 -> j-1
            int left = INT_MIN, right = INT_MIN;
            if (j < m-1) right = input[0][m-1] - input[0][j];
            if (j-1 >= 0) left = input[1][j-1];
            ans = min(ans, max(left,right));
        }
        if (ans == INT_MAX || ans == INT_MIN ) cout << "0\n";
        else cout << ans << endl;
    }
    return 0;
}
