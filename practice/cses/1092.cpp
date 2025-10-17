#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    long long nb = n;
    long long sum = (n*(n+1))/2;
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    long long half = sum/2;
    long long val = 0;
    long long skip;
    vector<long long> s;
    while (true) {
        if (val + n <= half) {
            s.push_back(n);
            val += n;
            n--;
        } else {
            skip = half - val;
            if (skip > 0) s.push_back(skip);
            break;
        }
    }

    cout<<"YES"<<endl;
    cout<<s.size()<<endl;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout<<endl;
    cout<<nb - s.size()<<endl;
    for (int i = 1; i <= n; i++) {
        if (i != skip) cout << i << " ";
    }
    cout<<endl;
    return 0;
}