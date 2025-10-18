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

int main(){
    int T;
    s(T);
    while(T--){
        string w;
        cin>>w;
        int wlen = w.size();
        bool flag = false;
        int mark_index = -1;
        for(int i = wlen-1; i>=0; i--){
            if(i >0 && w[i-1] >= w[i]) continue;
           else {mark_index = i-1;break;}
        }
        if(mark_index == -1){printf("no answer\n");continue;}
        int tmp = 1000000;
        int ans_index = -1;
        for(int i = mark_index + 1; i < wlen; i++){
            if(w[mark_index] < w[i]){
                if(w[i] - w[mark_index] < tmp){tmp = w[i] - w[mark_index];ans_index = i;}
            }
        }
        swap(w[mark_index],w[ans_index]);
        vector<char>v;
        for(int i = mark_index + 1; i<wlen; i++)
            v.pb(w[i]);
        sort(v.begin(),v.end());
        int k = mark_index + 1;
        for(int i=0; i<v.size(); i++)w[k++] = v[i];
        cout<<w<<endl;
    }
return 0;
}


