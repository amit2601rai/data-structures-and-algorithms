/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<ss> vss;
typedef map<string, string> mss;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef unordered_map<string, string> umss;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umi;
typedef set<int> sti;
typedef set<string> sts;
typedef stack<int> stki;
typedef stack<string> stks;
typedef queue<int> qi;
typedef queue<string> qs;
typedef deque<int> dqi;
typedef deque<string> dqs;
typedef unordered_set<int> usi;
typedef unordered_set<string> uss;
typedef priority_queue<int, vi, greater<int> > iMinHeap;
typedef priority_queue<int> iMaxHeap;
typedef priority_queue<ii, vii, greater<ii> > iiMinHeap;
typedef priority_queue<ii> iiMaxHeap;

#define pb push_back
#define mp make_pair


void dfs(vi v[], vi &subtree, vi vis, int s) {

	cout<<"-------"<<endl;

    cout<<"source : "<<s<<endl;

	for(int i = 1; i < subtree.size(); i++) {
	    	cout<<i<<":"<<subtree[i]<<endl;
	}

	cout<<"-------"<<endl;

	for(int i = 0; i < v[s].size(); i++) {
		if (vis[v[s][i]] == 0) {
			vis[v[s][i]] = 1;
			dfs(v, subtree, vis, v[s][i]);
		    subtree[s] = subtree[s] + 1 +  subtree[i];
		}		
	}
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
	    vi v[n+1];
	    int x, y;
	    for (int i = 0; i < n; i++) {
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
	    }
	    vi subtree(n+1, 0);
	    vi vis(n+1, 0);
	    vis[x] = 1;
	    dfs(v, subtree, vis, x);
	    for(int i = 1; i <=n; i++) {
	    	cout<<i<<":"<<subtree[i]<<endl;
	    }
	}
	return 0;
}
