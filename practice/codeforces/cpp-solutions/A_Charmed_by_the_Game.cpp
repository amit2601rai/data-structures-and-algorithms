#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define tr(c, val) for (const auto &val : c)
#define ispresent(c, val) if(c.find(val) != c.end())
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;


int main(){
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b % 2 == 0) {
            cout << "1\n" << b/2 << endl;
        } else if (a == 0 && b % 2 != 0) {
            cout << "2\n" << (b-1)/2 << " " << (b+1)/2 << endl; 
        } else if (b == 0 && a % 2 == 0) {
            cout << "1\n" << a/2 << endl;
        } else if (b == 0 && a % 2 != 0) {
            cout << "2\n" << (a-1)/2 << " " << (a+1)/2 << endl; 
        } else if (a == b) {
            cout << b+1 << "\n" << "0 ";
            for (int i = 1; i <= b; i++) cout << 2*i << " ";
            cout << endl;
        } else if (a < b) {
            //b-a, (0 , 2*a)
            //(a a<-), (->a, a)
            set<int> ans;
            if ((b-a)%2 == 0) {
                ans.insert(0+(b-a)/2);
                for (int i = 1; i <= a; i++) ans.insert(2*i+(b-a)/2);
            }
            else {
                ans.insert(0+(b-a-1)/2);
                ans.insert(0+(b-a+1)/2);
                for (int i = 1; i <= a; i++) {
                    ans.insert(2*i+(b-a-1)/2);
                    ans.insert(2*i+(b-a+1)/2);
                }
            }
            cout << ans.size() << endl;
            set<int>::iterator itr;
            for (itr = ans.begin(); itr != ans.end(); itr++) {
                cout << *itr << " ";
            }
            cout << endl;
            
        } else {
            set<int> ans;
            if ((a-b)%2 == 0) {
                ans.insert(0+(a-b)/2);
                for (int i = 1; i <= b; i++) ans.insert(2*i+(a-b)/2);
            }
            else {
                ans.insert(0+(a-b-1)/2);
                ans.insert(0+(a-b+1)/2);
                for (int i = 1; i <= b; i++) {
                    ans.insert(2*i+(a-b-1)/2);
                    ans.insert(2*i+(a-b+1)/2);
                }
            }
            cout << ans.size() << endl;
            set<int>::iterator itr;
            for (itr = ans.begin(); itr != ans.end(); itr++) {
                cout << *itr << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
