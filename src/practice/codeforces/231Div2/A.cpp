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


int main(){
    int x=0,y=0,z=0;
    bool plusflag = false,equalflag = false;
    string input;
    cin>>input;
    int len = input.length();
    for(int i =0 ;i <len;i++){
        if(input[i] == '+')plusflag = true;
        else if(input[i] == '=')equalflag = true;
        else if(!plusflag)x++;
        else if(!equalflag)y++;
        else z++;
    }
    if(z == (x+y))cout<<input<<endl;
    else{
        if(z<(x+y)){
                if(x>y)x--;
                else y--;
                z++;
        }
        else{
                if(x>y)y++;
                else x++;
                z--;
        }

        if(z != x+y){cout<<"Impossible"<<endl;return 0;}
        while(x--)cout<<"|";
        cout<<"+";
        while(y--)cout<<"|";
        cout<<"=";
        while(z--)cout<<"|";
        cout<<endl;
    }
return 0;
}
