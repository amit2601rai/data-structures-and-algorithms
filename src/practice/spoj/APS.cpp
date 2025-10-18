#include<iostream>
#include<cstdio>

using namespace std;

int prime[10000001];
long long int a[10000001];

void sieve(int n)
{
   for (int i=2; i*i<=n; i++){
      if (prime[i]==0){
          prime[i]=i;
            for (int k=2*i; k<=n; k=k+i){
                 if(prime[k]==0)
                    prime[k]=i;
            }
        }
    }
    for(int i=2;i<=10000000;i++)
        if(prime[i]==0)
           prime[i]=i;
}

void compute(){
        a[0]=0;
        a[1]=0;
    for(int i=2;i<=10000000;i++){
        a[i]=a[i-1]+prime[i];
    }
}

int main(){
    sieve(10000000);
    compute();
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<a[n]<<endl;
    }
return 0;
}
