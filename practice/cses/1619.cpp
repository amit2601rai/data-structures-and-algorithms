#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > intervals;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intervals.push_back(make_pair(x, 1));
        intervals.push_back(make_pair(y, -1));
    }
    sort(intervals.begin(), intervals.end());
    stack<pair<int, int>> st;
    st.push(intervals[0]);
    int ans = 1;
    for (int i = 1; i < intervals.size(); i++) {
        if (st.empty()) {st.push(intervals[i]); continue;}
        pair<int, int> e = st.top();
        if (e.second * (-1) == intervals[i].second) st.pop();
        else st.push(intervals[i]);
        ans = max(ans, (int)st.size());
    }
    cout << ans << endl;
    return 0;
}