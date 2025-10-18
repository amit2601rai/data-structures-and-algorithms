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

bool comp(pair<char, int>p, pair<char, int>q) {
    if(p.second < q.second) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        string s;
        for (int i = 0; i <n; i++) cin >> v[i];
        cin >> s;
        vector <pair<char, int>> br;
        for (int i = 0; i < n; i++) {
            br.pb(mp(s[i], v[i]));
        }
        sort(br.begin(), br.end());
        int k = -1;
        for (int i = 0; i < br.size(); i++) {
            if (br[i].first == 'R') break;
            k++;
        }
        if (k == -1 || k == br.size()-1) {
            sort(br.begin(), br.end(), comp);
        } 
        else {
            sort(br.begin(), br.begin()+k+1, comp);
            sort(br.begin()+k+1, br.end(), comp);
        }
        int l = 1;
        int flag = true;
        for (pair<char, int>q:br) {
            char x = q.first;
            int y = q.second;
            if ((l == y) || (l < y && x == 'B') || (l > y && x == 'R')) {
                l++;
            }             
            else {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
