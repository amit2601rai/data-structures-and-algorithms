/*Amit Rai(IIIT Hyderabad)*/
 #include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
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
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

struct node{
    vi s;
    vi e;
    int num_substr;
};

struct node segTree[4*100001];

void buildTree(int root, int low, int high, string input){
    if(low == high){
        struct node tmp;
        tmp.num_substr = 0;
        tmp.s.pb(input[low] - 48);
        tmp.e.pb(input[low] - 48);
        if((input[low] - 48 ) % 3 == 0)tmp.num_substr = 1;
        segTree[root] = tmp;
        return;
    }
    int mid = (low + high)/2;
    buildTree(2*root, low, mid, input);
    buildTree(2*root + 1, mid + 1, high, input);
    struct node tmp;
    tmp.s = segTree[2*root].s;
    tmp.e = segTree[2*root + 1].e;
    int cal_num_substr = 0;
    if(segTree[2*root].e.size() != 0 && segTree[2*root + 1].s.size() != 0){
        for(int i = 0; i < segTree[2*root].e.size(); i++){
        for(int j = 0; j < segTree[2*root + 1].s.size(); j++){
            if((segTree[2*root].e[i] + segTree[2*root + 1].s[j]) % 3 == 0) cal_num_substr++;
        }
      }
    }
    tmp.num_substr = segTree[2*root].num_substr + segTree[2*root + 1].num_substr + cal_num_substr;
    segTree[root] = tmp;
}

/*
void updateTree(int root, int x, int y, int low, int high){
}*/

struct node queryTree(int root, int a, int b, int low, int high){
    struct node tmp;
    tmp.num_substr = 0;

    if(a > high || b < low)
        return tmp;

    if(a <= low && high <= b){
        return segTree[root];
    }

    int mid = (low+high)/2;
    struct node left_substr;
    left_substr.num_substr = 0;
    struct node right_substr;
    right_substr.num_substr = 0;
    if(a <= mid)
        left_substr = queryTree(2*root, a, b, low, mid);
    if(b > mid)
        right_substr = queryTree(2*root+1, a, b, mid+1, high);
    tmp.s = left_substr.s;
    tmp.e = right_substr.e;
    int cal_num_substr = 0;
    if(left_substr.e.size() != 0 && right_substr.s.size() != 0){
        for(int i = 0; i < left_substr.e.size(); i++){
        for(int j = 0; j < right_substr.s.size(); j++){
            if((left_substr.e[i] + right_substr.s[j]) % 3 == 0) cal_num_substr++;
        }
      }
    }
    tmp.num_substr = left_substr.num_substr + right_substr.num_substr + cal_num_substr;
return tmp;
}

int main(){
    int n, m;
    s(n);
    s(m);
    string input;
    cin>>input;
    buildTree(1, 0, n-1, input);
    while(m--){
        int x, y, z;
        cin>>x>>y>>z;
        if(x == 1){
            input[y-1] = z;
            buildTree(1, 0, n-1, input);
        }else{
            cout<<queryTree(1, y-1, z-1, 0, n-1).num_substr<<endl;
        }
    }
return 0;
}
