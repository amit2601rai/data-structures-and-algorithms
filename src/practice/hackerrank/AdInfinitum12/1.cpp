#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, sum, prod;
    cin>>n;
    int input[n+1];
    for(int i = 0; i <=n; i++) cin>>input[i];
    if(n == 1) {
        prod = sum = (-1)*(input[0]/input[1]);
    } else {
        sum = (-1)*(input[n-1]/input[n]);
        prod = input[0]/input[n];
        if(n % 2 != 0)prod *= (-1); 
    }
    cout<<sum<<" "<<prod<<endl;
    return 0;
}
