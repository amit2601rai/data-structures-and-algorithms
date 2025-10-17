#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string input;
    cin >> input;
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == input[i-1]) cur++;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
    cout<<ans<<endl;
    return 0;
}