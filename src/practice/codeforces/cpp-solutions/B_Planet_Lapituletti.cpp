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

vi v = {3, 4, 6, 7, 9};
bool isPresent(int x) {
    for (int i = 0; i < 5; i++) if(v[i] == x) return true;
    return false;
}

int mirror(int x) {
    if (x == 0 || x == 1 || x == 8) return x;
    if (x == 2) return 5;
    else return 2;
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        int h, m;
        string s;
        cin >> h >> m;
        cin >> s;
        int mins = 10 * (s[3] - 48) + (s[4] - 48);
        int hrs = 10 * (s[0] - 48) + (s[1] - 48);
        bool flag = false;
        for (int i = hrs; i < h; i++) {
            for (int j = mins; j < m; j++) {
                int h1, h2, m1, m2;
                h1 = i/10;
                h2 = i%10;
                m1 = j/10;
                m2 = j%10;
                if (isPresent(h1) || isPresent(h2) || isPresent(m1) || isPresent(m2)) continue;
                int rhrs = 10*mirror(m2) + mirror(m1);
                int rmins = 10*mirror(h2) + mirror(h1);
                if (rhrs < h && rmins < m) {
                    cout << h1 << h2 << ":" << m1 << m2 << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            mins = 0;
        }
        if (!flag) cout << "00:00" << endl;
    }
    return 0;
}
