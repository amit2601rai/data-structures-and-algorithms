#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
    	int n;
    	cin>>n;
    	long long input[n+1];
    	input[0] = 0;
    	long long sum = 0;
    	for(int i = 1; i<=n; i++){
    		long long x;
    		cin>>x;
    		sum += x;
    		input[i] = x+input[i-1];
    	}
    	int ans = n;
    	for(int i = n; i >= 1; i--){
    		long long t1 = input[i-1];
    		long long t2 = sum - input[i];
    		if(t1 <= 2*t2){
    			ans = i;
    			break;
    		}
    	}
    		cout<<ans<<" "<<n-ans<<endl;
    }
    return 0;
}
