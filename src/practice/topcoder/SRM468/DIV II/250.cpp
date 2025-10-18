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

bool myComp(ii x,ii y){
    return x.first > y.first;
}

class RoadOrFlightEasy {
public:
	int minTime(int, vector <int>, vector <int>, int);
};

int RoadOrFlightEasy::minTime(int N, vector <int> roadTime, vector <int> flightTime, int K) {
	vector<ii>diff;
	FOR(i,0,N-1)diff.pb(mp(roadTime[i] - flightTime[i],i));
	sort(diff.begin(),diff.end(),myComp);
	bool flag[N];
	int ans = 0;
	memset1d(flag,N-1,false);
	FOR(i,0,K-1){
	    if(diff[i].first >= 0){
          ans += flightTime[diff[i].second];
	      flag[diff[i].second] = true;
	    }
	}
	FOR(i,0,N-1){
	    if(!flag[i])ans += roadTime[i];
	}
	return ans;
}
