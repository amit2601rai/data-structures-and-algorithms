// CSES Problem 1068 - Weird Algorithm (Collatz Conjecture)
#include <iostream>

using namespace std;
typedef long long ll;
 
int main() {
    long long n;
    cin>>n;
    while(n > 1) {
        cout << n << " ";
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    cout << n <<endl;
    return 0;
}