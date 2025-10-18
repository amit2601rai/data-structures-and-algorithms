#include<iostream>
#include<cstdio>

using namespace std;

void extendedEuclid(int a,int b){
    int xLast = 1 , yLast = 0, x = 0, y=1;
    int q,r,m,n;
    while(b != 0){
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;
        xLast = x;
        yLast = y;
        x = m;
        y = n;
        a = b;
        b = r;
    }
    cout<<xLast<<" "<<yLast<<" "<<a<<endl;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b) != -1){
        extendedEuclid(a,b);
    }
return 0;
}
