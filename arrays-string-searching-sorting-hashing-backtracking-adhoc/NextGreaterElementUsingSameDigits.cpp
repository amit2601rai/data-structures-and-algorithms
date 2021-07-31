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

void nextGreaterNumber(int val){
    vector<int> v;
    while(val){
        int tmp = val%10;
        v.pb(tmp);
        val /= 10;
    }
    reverse(v.begin(), v.end());
    int len = v.size();
    int prev = v[len - 1];
    int idx = -1;
    for(int i = len - 2; i >= 0; i--){
        if(v[i] < prev ){
            swap(v[i], v[len-1]);
            idx = i;
            break;
        }else prev = v[i];
    }
    if(idx == -1) {cout<<"NO ANSWER"<<endl; return;}
    sort(v.begin()+idx+1, v.end());
    reverse(v.begin(), v.end());
    int sum = 0;
    int k = 1;
    for(int i = 0; i < v.size(); i++){
        int tmp = k*v[i];
        sum += tmp;
        k *= 10;
    }
    cout<<sum<<endl;
}

int main(){
    int num;
    cin>>num;
    nextGreaterNumber(num);
}
