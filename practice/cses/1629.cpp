#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > intervals;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intervals.push_back(make_pair(y, x));
    }
    sort(intervals.begin(), intervals.end());
    int ans = 1;
    int val = intervals[0].first;
    for (int i = 1; i < n; i++) {
        if (intervals[i].second < val) continue;
        else {
            ans++;
            val = intervals[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}