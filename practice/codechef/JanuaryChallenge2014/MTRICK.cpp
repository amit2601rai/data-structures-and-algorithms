//Author:Amit Rai (IIIT-Hyderabad)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define For(a, b) for (int i = a; i <= b; i++)
#define Rep(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define Fill_1d(a,n,value) For(0,n){a[i]=value;}
#define Fill_2d(a,m,n,value) For(0,m) Rep(0,n){a[i][j]=value;}



ll mulmod(ll a,ll b,ll c){
   ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = x+y;
            if(x>=c)x%=c;
        }
        y = y*2;
        if(y>=c)y%=c;
        b /= 2;
    }
    return x%c;
}

void rev(ll L[],int i,int n){
    int low = i;
    int high = n-1;
    while(low<=high){
        ll temp;
        temp = L[low];
        L[low] = L[high];
        L[high] = temp;
        high--;
        low++;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        ll L[n];
        ll Add[n];
        ll Mul[n];
        ll A,B,C;
        char P[n+1];
        for(int i=0;i<n;i++){
            scanf("%lld",&L[i]);
        }
        scanf("%lld%lld%lld",&A,&B,&C);
        scanf("%s",P);
        Fill_1d(Add,n-1,0);
        Fill_1d(Mul,n-1,1);
        for(int i=0;i<n;i++){
            if(P[i] == 'R'){
               rev(L,i,n);
               if(i!=0){
                    Add[i] = Add[i-1];
                    Mul[i] = Mul[i-1];
               }
             }else if(P[i] == 'M'){
                if(i == 0){
                        Mul[i] = B;

                }else{
                    Add[i] = mulmod(Add[i-1],B,C);
                    Mul[i] = mulmod(Mul[i-1],B,C);
                }
            }else{
                if(i==0)
                    Add[i] = A;
                else{
                        Add[i] = (Add[i-1] +A)%C;
                        Mul[i] = Mul[i-1];
                    }
            }
            L[i] = mulmod(L[i],Mul[i],C);
            L[i] = (L[i]+Add[i])%C;
          printf("%lld ",L[i]);
        }
        printf("\n");
    }
return 0;
}
