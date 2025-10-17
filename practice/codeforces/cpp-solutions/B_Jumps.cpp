#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        int k = 1;
        int sum = 1;
        while(sum < x) {
            k++;
            sum += k;
        }
        if (sum - 1 == x) cout<<k+1<<endl;
        else cout<<k<<endl;
    }
    return 0;
}