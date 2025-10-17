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

LL f(LL h, LL x, LL y, LL m) {
	return (h*x + y)%m;
}


LL cycleDetect (LL a, LL h, LL x, LL y, LL m) {
	LL hare = h;
	LL turtle = h;
	LL th = 0;
	LL tt = 0;
	LL final_tt = -1;
	LL final_th = -1;
	do {
		turtle = f(turtle, x, y, m);
		hare = f(f(hare, x, y, m), x, y, m);
		th += 2;
		tt++;
		if(turtle == a) final_tt = tt;
		if(hare == a) final_th = th;
	} while(tt <=m && hare != turtle);
	if(final_th != -1 && final_tt != -1) return min(final_th,final_tt);
	else if(final_tt == -1) return final_th;
	else return final_tt;
}

pair<LL,LL> extendedEuclid(LL a, LL b){
    LL xLast = 1 , yLast = 0, x = 0, y=1;
    LL q,r,m,n;
    while(b != 0){
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;
        xLast = x;
        yLast = y;
        x = m;
        y = n;
        a = b;
        b = r;
    }
    return mp(xLast, yLast);
}

LL euclid(LL x,LL y){
    LL r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
	LL m, h1, a1, x1, y1, h2, a2, x2, y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	LL h1Toa1 = cycleDetect (a1, h1, x1, y1, m);
	LL a1Toh1 = cycleDetect (a1, a1, x1, y1, m);
	LL h2Toa2 = cycleDetect (a2, h2, x2, y2, m);
	LL a2Toh2 = cycleDetect (a2, a2, x2, y2, m);
	if(h1Toa1 == -1  || h2Toa2 == -1) {
		cout<<"-1"<<endl;
		return 0;
	}

	
	if(h1Toa1 == h2Toa2) {
		cout<<h1Toa1<<endl;
		return 0;
	}

	if(a1Toh1 == -1) a1Toh1 = 0;
	if(a2Toh2 == -1) a2Toh2 = 0;

	LL a = a1Toh1;
	LL b = (-1)*a2Toh2;
	LL gcd_ab = euclid(a,b);
	LL c = (a1Toh1 - a2Toh2) + (h2Toa2 - h1Toa1);
	
	if(c % gcd_ab != 0) {
		cout<<"-1"<<endl;
		return 0;
	}

    pair<LL,LL> res = extendedEuclid(a,b);
    LL x0 = ((res.first)*c)/gcd_ab;
    LL y0 = ((res.second)*c)/gcd_ab;
    LL q1 = b/gcd_ab;
    LL q2 = (-1)*(a/gcd_ab);
    //x0+q1K y0+q2K 
    LL min_ans_tmp = 1000000000000000000;
    for (LL k = 0; k <= 5000000; k++){
    	LL tmp_x = x0 + q1*k;
    	LL tmp_y = y0 + q2*k;
    	if(tmp_x > 0 && tmp_y > 0) {
    		LL ans_tmp = h1Toa1 + (tmp_x - 1)*a1Toh1;
    		min_ans_tmp = min(min_ans_tmp,ans_tmp);
    	
    	}
    	tmp_x = x0 + (-1)*q1*k;
    	tmp_y = y0 + (-1)*q2*k;
    	if(tmp_x > 0 && tmp_y > 0) {
    		LL ans_tmp = h1Toa1 + (tmp_x - 1)*a1Toh1;
    		min_ans_tmp = min(min_ans_tmp,ans_tmp);
    	} 
    }
    if(min_ans_tmp == 1000000000000000000) cout<<"-1"<<endl;
    else cout<<min_ans_tmp<<endl;

return 0;
}