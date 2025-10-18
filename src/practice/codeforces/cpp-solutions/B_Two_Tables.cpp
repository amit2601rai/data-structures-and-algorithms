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
        int W, H, w, h, x1, y1, x2, y2;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        int up = INT_MAX, down = INT_MAX, left = INT_MAX, right = INT_MAX;
        // up : H - y2 -> h - y1
        if (h - y1 <= H - y2){
            if (h - y1 < 0) up = 0;
            else up = h - y1;
        } 

        // down : y1 -> h - (H-y2)
        if (h - H + y2 <= y1) {
            if (h - H + y2 < 0) down = 0;
            else down = h - H + y2;
        }

        // left : x1 -> w - x1
        if (w - x1 <= W - x2) {
            if (w - x1 < 0) left = 0;
            else left = w - x1;
        }
        
        // right : W - x2 -> w - (W - x2)
        if (w - W + x2 <= x1) {
            if (w - W + x2 < 0) right = 0;
            else right = w - W + x2;
        }    
          
        if (up == INT_MAX && down == INT_MAX && left == INT_MAX && right == INT_MAX) cout << "-1\n";
        else {
            int finalans = min(up, min(down, min(left, right)));
            setp((double)finalans, 9);
        }
    }
    return 0;
}
