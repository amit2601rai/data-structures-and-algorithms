#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

int primes[MAX];

void sieve(int n){
	for(int i=0; i<=n ; i++)
		primes[i] = i;
	for(int i=2 ; i*i <= n ; i++){
		if(primes[i] == i){
			for(int j = i*i ; j <= n ; j++)
				if(j%i == 0)
					primes[j] = i;
		}
	}
}


int main(){
	int n;
	cin>>n;
	sieve(n);
	for(int i=2; i<=n ;i++)
		if(primes[i] == i)
			cout<<primes[i]<<" ";
	cout<<endl;
return 0;
}
