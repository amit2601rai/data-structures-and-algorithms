#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

         if (x == 1 && y == 1) {
            cout << "NO" << endl;
            continue;
        } 
        else if (x == 0 && y == 0) {
            cout << "YES" << endl;
            continue;
        } else if (x == 0 || y == 0) {
            cout << "NO" << endl;
            continue;
        }
        if (max(x, y) <= 2 * min(x, y) && (x + y) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" <<endl;
    }
    return 0;
}