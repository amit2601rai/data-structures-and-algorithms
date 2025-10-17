/*Amit Rai(IIIT Hyderabad)*/
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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

bool checkX(int x){
    if(x > 0)return (x%2 != 0);
    else return (x%2 == 0);
}

bool checkY(int y){
    return (y%2 == 0);
}


bool isOil(int x,int y){
    bool isX,isY;
    isX = checkX(x);
    isY = checkY(y);
    if(isX){
        if(x == 0)return isY;
        if(x > 0)if(y >= (-1)*(x-1) && y <= x+1) return true;
        if (x < 0)if(y >= x && y <= (-1)*x) return true;;
    }
    if(isY){
        if(y == 0)return isX;
        if(y > 0)if(x >= (-1)*y && x <= y-1)return true;
        if(y < 0)if(x >= y && x <= (-1)*y+1)return true;
    }
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(isOil(x,y))printf("YES\n");
        else printf("NO\n");
    }
return 0;
}
