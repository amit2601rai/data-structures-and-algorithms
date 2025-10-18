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
    while(t--) {
        int n;
        string s;
        cin  >> n >> s;
        int low = 0, high = n - 1;
        vi ans;
        while (low < high) {
            if (s[low] > s[high]) {
                ans.push_back(low + 1);
                ans.push_back(high + 1);
                low++, high--;
            } else if (s[low] == '0') {
                low++;
            } else {
                high--;
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() > 0){
            cout << "1" << endl;
            cout << ans.size() << " ";
            for (int x : ans) cout << x << " ";
            cout << endl; 
        } 
        else cout << "0" << endl;
    
    }
    return 0;
}
