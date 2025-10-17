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
        int a, b, c , d;
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            cout << "Tidak Tidak Tidak Tidak\n";
        }
        else if ((a+b) % 2 == 0) {
            if (b > 0 || c > 0) {
                if (d > 0 || a > 0) {
                    cout << "Tidak Tidak Ya Ya\n";
                } else {
                    cout << "Tidak Tidak Ya Tidak\n";
                }
            } else cout << "Tidak Tidak Tidak Ya\n";
        } else {
            if (b > 0 || c > 0) {
                if (a > 0 || d > 0) {
                    cout << "Ya Ya Tidak Tidak\n";
                } else {
                    cout << "Tidak Ya Tidak Tidak\n";
                }
            } else cout << "Ya Tidak Tidak Tidak\n";
        }
    }
    return 0;
}
