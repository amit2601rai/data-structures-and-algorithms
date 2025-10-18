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
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        int x = (a1+a3);
        int y = 2*a2; 
        if (abs(x - y) == 0 || abs(x - y) == 1) cout << abs(x-y) << endl;
        else if (abs(x - y) % 3 == 0) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
