/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair



void dfs(int s, vector<int>tree[], vi &par, vi &vis) {
	for(int i = 0; i < tree[s].size(); i++) {
		if(vis[tree[s][i]] == 0) {
			vis[tree[s][i]] = 1;
			par[tree[s][i]] = s;
			dfs(tree[s][i], tree, par, vis);
		}
	}
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>tree[n+1];
	vi deg(n+1, 0);
	for(int i = 1; i < n; i++) {
		int u,v;
		cin>>u>>v;
		tree[u].pb(v);
		tree[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	vii nodedeg;
	for(int i = 1; i <=n; i++) {
		if(deg[i] > 0) {
			nodedeg.pb({deg[i], i});
		}
	}
	sort(nodedeg.begin(),nodedeg.end());


	unordered_map<int,int> indus;
	for (int i = 0; i <k; i++) {
		indus[nodedeg[i].second] = 1;
	}

   	int root;
	for(int i = n-1; i>=0; i--) {
		if(nodedeg[i].first > 0) {
			root = nodedeg[i].second;
			break;
		}
	}

	vi par(n+1, 0);
	vi vis(n+1, 0);
	vis[root] = 1;
	dfs(root, tree, par, vis);
   for(int i = 0; i <=n; i++) cout<<i<<" "<<par[i]<<" "<<endl;


	int ans = 0;
	for(auto &entry:indus) {
		int node = entry.first;
		while(par[node] != 0) {
			node = par[node];
			if(indus.find(node) == indus.end()) ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
