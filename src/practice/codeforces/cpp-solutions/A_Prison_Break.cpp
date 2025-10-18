#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;


int dist(int x, int y, int r, int c) {
    return abs(r - x) + abs(c - y);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n, m, r, c;
        cin>>n>>m>>r>>c;
        //(1,1), (n,1), (1, m), (n, m)
        cout<<max(dist(1, 1, r, c), max(dist(n, 1, r, c), max(dist(1, m, r, c), dist(n, m, r, c))))<<endl;
    }
}