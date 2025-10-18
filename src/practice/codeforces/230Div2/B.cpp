/*Author:Amit(IIIT-H)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)


int main(){
    int n;
    cin>>n;
    double W[n+1][n+1];
    double A[n+1][n+1];
    double  B[n+1][n+1];
    FOR(i,1,n)FOR(j,1,n)cin>>W[i][j];
    FOR(i,1,n)FOR(j,i,n){
        if(i == j){A[i][j] = W[i][j];B[i][j]=0;}
        else{
            A[j][i] = A[i][j] = (W[i][j] + W[j][i])/2;
            B[i][j] = (W[i][j] - W[j][i])/2;
            B[j][i] = (-1)*B[i][j];
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            printf("%.8lf ",A[i][j]);
        }
        cout<<endl;
    }
    FOR(i,1,n){
        FOR(j,1,n){
            printf("%.8lf ",B[i][j]);
        }
        cout<<endl;
    }

return 0;
}
