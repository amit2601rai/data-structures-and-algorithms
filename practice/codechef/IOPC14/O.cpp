#include<iostream>

using namespace std;

int gcd(int x,int y){
    int r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

bool isPowerOf2(int n){
    if((n & (n-1)) == 0)return true;
    else return false;
}

int numberOfTrailingZeros(int n){
    int counter = 0;
    while(n != 1){
        n /= 2;
        counter++;
    }
    return counter;
}

bool firstCase(int p,int q){
    int m,t,k;
    if(isPowerOf2(q+1) && isPowerOf2(p)){
        m = numberOfTrailingZeros(q+1);
        t = numberOfTrailingZeros(p);
        k = m-t;
        if(k>=0 && m>=1)return true;
    }
    return false;
}

bool secondCase(int p,int q){
    if(p==1 && isPowerOf2(q+1) &&  numberOfTrailingZeros(q+1)>=1)return true;
    else return false;
}

bool thirdCase(int p,int q){
    if(p != 1)return false;
    int t = 0;
    while(q%2==0){
        q /= 2;
        t++;
    }
    if(!isPowerOf2(q+1))return false;
    int m = numberOfTrailingZeros(q+1);
    int k = m+t;
    if(k>=0 && m>=1)return true;
    else return false;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int pp,qq,p,q;
        cin>>pp>>qq;
        p = pp/gcd(pp,qq);
        q = qq/gcd(pp,qq);
        if(firstCase(p,q)||secondCase(p,q)||thirdCase(p,q))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
