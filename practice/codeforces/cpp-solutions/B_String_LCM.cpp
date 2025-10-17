#include<bits/stdc++.h>

using namespace std;

int occurences(string s, string t) {
    int occurrences = 0;
    string::size_type start = 0;
    while ((start = s.find(t, start)) != string::npos) {
        ++occurrences;
        start += t.length(); // see the note
    }
    return occurrences;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        if (t.size() > s.size()) swap(s, t);
        
        string ans;
        ans += s;
        bool flag = true;
        while (ans.size() <= 400) {
            int a = occurences(ans, t);
            if (a * t.size() == ans.size()) {
                cout << ans << endl;
                flag = false;
                break;
            }
            ans += s;
        }
        if(flag) cout << "-1" << endl;
    }
    return 0;
}