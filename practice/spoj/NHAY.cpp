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


int* prefix(string P){
	int m,cur=0;
	m = P.size();
	int *lps = new int[m];
	lps[0]=0;
	for(int i=1;i<m;i++){
	    if(P[cur]==P[i]){
	        lps[i] = lps[i-1]+1;
	        cur++;
		}
		else{
            cur=0;
            if(P[cur]==P[i]){
               lps[i]=1;
               cur++;
            }
            else lps[i]=0;
        }
	}
return lps;
}


/*kmp matcher*/
vi kmp(string T,string P){
    vi ans;
	int i=0,j=0,n,m,l=0;
	n = T.size();
	m = P.size();
	int *lps = prefix(P);
	while(i < n){
      if(P[j]==T[i]){
           j++,i++;
           if(j == m){
            ans.pb(i-j);
            i = i-lps[j-1];
            j = 0;
           }
      }
      else{
         if(j==0) i++;
         else j = lps[j-1];
		}
	}
return ans;
}


int main(){
    while(true){
        int m;
        if(scanf("%d", &m) == -1)break;
        string pattern;
        string text;
        cin>>pattern;
        cin>>text;
        vi ans = kmp(text, pattern);
        vi::iterator it;
        for(it  = ans.begin(); it != ans.end(); it++)cout<<*it<<endl;
        cout<<endl;
    }
return 0;
}


