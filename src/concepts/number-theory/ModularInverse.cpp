#include<iostream>

using namespace std;

int phi(int n){
	int result = n;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0)result -= result/i;
		while(n%i == 0)n /= i;
	}
	if(n > 1)result -= result/n;
	return result;
}

int power(int a,int b,int m){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = (x*y)%m;
        }
        y = (y*y)%m;
        b /= 2;
    }
    return x%m;
}
/* a and m should be co-prime*/
int modInverse(int a,int m){
    return power(a,phi(m)-1,m);
}

int main(){
    int a,m;
    cin>>a>>m;
    cout<<(modInverse(a,m))<<endl;
return 0;
}
