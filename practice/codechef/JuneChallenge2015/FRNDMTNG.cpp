/*Amit Rai(IIIT Hyderabad)*/
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iomanip>

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

int main(){
	int T;
	s(T);
	while(T--) {
		LD T1, T2, t1, t2, areaAbove = 0.000000, areaBelow = 0.000000, two = 2.0, ans;
		cin>>T1>>T2>>t1>>t2;
		LD totalArea = T1*T2;
		//x-axis : [0,T1] and t1, y-axis : [0,T2] and t2
		// x-y+t1 < 0 
	    //y = T2 and x = T1 calculate above area 
	    if (!(t1 >= T2)) {
	    	LD x = T2 - t1;
	    	LD y = t1 + T1;
	    	//(x,T2)
	    	if (x <= T1) 
	    		areaAbove = ((T2 - t1)*x)/two;
	    	else 
	    		areaAbove = ((2*(T2-t1)- T1)*T1)/two;
	    }

		// x-y-t2 > 0
		//y = T2 and x = T1 calculate below area 
		if(!(t2 >= T1)) {
			LD x = T2+t2;
			LD y = T1 - t2;
			if (y <= T2)
				areaBelow = ((T1-t2)*y)/two;
			else 
				areaBelow = ((2*(T1-t2)-T2)*T2)/two;

		}
		//cout<<"aboveArea = "<<areaAbove<<" "<<"belowArea = "<<areaBelow<<endl;
		ans = (totalArea - (areaAbove + areaBelow))/totalArea;
		if(ans == 0.000000) ans = 0.000001;
		setp(ans,6);
	}

}
