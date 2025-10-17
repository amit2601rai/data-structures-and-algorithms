#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v(26,0);
    for (int i = 1; i <= k; i++) {
        char c;
        cin>>c;
        v[c-'a']++;
    }

    long long ans = 0;
    long long cur = 0;
    long long one = 1;
    long long two = 2;

    for (int i = 0; i < s.length(); i++) {
        if (v[s[i]-'a'] == 1) {
            cur++;
        } else {
            ans = ans + (cur*(cur+one))/two;
            cur = 0;
        }
    }
    ans = ans + (cur*(cur+one))/two;
    cout<<ans<<endl;
    return 0;
}