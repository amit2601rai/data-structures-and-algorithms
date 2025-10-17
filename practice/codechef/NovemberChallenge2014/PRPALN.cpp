/*Amit Rai(IIIT Hyderabad)*/
 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef set<int> si;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;
typedef priority_queue<ii, vii, greater<ii> > pminHeap;
typedef priority_queue<ii> pmaxHeap;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)
#define init_1D(a,n,value) FOR(i,0,n)a[i]=value;
#define init_2D(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define tr(type,container) type :: iterator it; for(it = container.begin(); it!= container.end(); it++)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

/*
Stack Overflow
bool palin(string str, int low, int high, bool flag){
    if(low == high) return true;
    if(low == high - 1) {
        if(flag) return str[low] == str[high];
        else return true;
    }
    if(str[low] == str[high]) return palin(str, low+1, high-1, flag);
    if(flag) return false;
    return palin(str,low,high-1,true) || palin(str, low+1, high, true);
}*/

bool isPalin(string str, int low, int high){
    while(low <= high){
        if(str[low] == str[high]){
            high--;
            low++;
            continue;
        }
        return false;
    }
return true;
}

int main(){
    int T;
    s(T);
    while(T--){
        string str;
        cin>>str;
        int low , high;
        low = 0;
        high = str.size() - 1;
        bool flag = true;
        while(low <= high){
            if(str[low] == str[high]){low++; high--; continue;}
            else{
                if(isPalin(str,low,high-1) || isPalin(str,low+1,high))flag = true;
                else flag = false;
                break;
            }
        }
        //bool flag = palin(str, 0, str.size() -1, false);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
   return 0;
}
