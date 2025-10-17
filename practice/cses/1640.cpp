#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[i] = make_pair(val, i);
    }
    sort(v.begin(), v.begin() + n);
    int low = 0, high  = n-1;
    while (low < high) {
        if (v[low].first + v[high].first == sum) {cout << v[low].second + 1 << " " << v[high].second + 1 << endl; return 0;}
        else if (v[low].first + v[high].first < sum) low++;
        else high--;
    }
    cout << "IMPOSSIBLE"<<endl;
    return 0;
}