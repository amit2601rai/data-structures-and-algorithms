#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        int len = s.length();
        int ans = INT_MAX;
        for (int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                int cnt = 0;
                bool flag = false;
                for (int k = 0; k < len; k++) {
                    if(!flag && s[k] - 48 == i) cnt++, flag = true;
                    else if(flag && s[k] - 48 == j) cnt++, flag = false;
                }
                if (cnt % 2 != 0 && i != j) cnt--;
                ans = min(ans, len - cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}