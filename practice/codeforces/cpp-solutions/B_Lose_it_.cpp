#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int end[] = {0,0,0,0,0,0};
    int values[] = {4,8,15,16,23,42};

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            if (v[i] == values[j]) {
                if (j-1 >= 0) {
                    if (end[j-1] >= 1) {
                        end[j] += 1;
                        end[j-1]--;
                    }
                } else {
                    end[j] += 1;
                }
                break;
            }
        }
    }
    cout<<(n-end[5]*6)<<endl;
    return 0;
}