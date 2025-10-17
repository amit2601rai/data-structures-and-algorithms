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

int gcd(int x,int y){
    int r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        int maxel = INT_MIN;
        int maxidx;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] > maxel) maxidx = i, maxel = v[i];
        } 
        if (n == 1) {
            cout << v[0] << "\n"; 
            continue;
        }
        swap(v[maxidx], v[0]);
        int gcdsofar = v[0];
        for (int i = 0; i < n; i++) {
            int maxgcd = INT_MIN;
            int k = -1;
            for (int j = i+1; j < n; j++) {
                int cumgcd = gcd(gcdsofar, v[j]);
                if (cumgcd > maxgcd) maxgcd = cumgcd, k = j;
            }
            if (k != -1 && i+1 < n) gcdsofar = gcd(gcdsofar, v[k]), swap(v[k], v[i+1]);
        }
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << "\n";

    }
    return 0;
}