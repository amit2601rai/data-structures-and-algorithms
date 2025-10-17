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
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define For(a, b) for (int i = a; i <= b; i++)
#define Rep(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define Fill_1d(a,n,value) For(0,n){a[i]=value;}
#define Fill_2d(a,m,n,value) For(0,m) Rep(0,n){a[i][j]=value;}

mi M;
int minInWindow(int a[],int low,int high){
    int minValue = a[low];
    for(int i=low;i<=high;i++)
        minValue = min(a[i],minValue);
    return minValue;
}

void preCompute(int a[],int n){
    for(int windowSize=1;windowSize<=n;windowSize++){
        int low = 0;
        int high = windowSize-1;
        while(high<n){
            M[minInWindow(a,low,high)]++;
            low++;
            high++;
        }
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    preCompute(a,n);
    int Q;
    cin>>Q;
    while(Q--){
        int K;
        cin>>K;
        cout<<M[K]<<endl;
    }
return 0;
}
