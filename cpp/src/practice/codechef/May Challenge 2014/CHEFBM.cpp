//Author:Amit Rai (IIIT-Hyderabad)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(a, b) for (int i = a; i <= b; i++)
#define REP(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define memset1d(a,n,value) FOR(0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(0,m) REP(0,n) a[i][j]=value;

int binSearch(vector<pair<int,int> >vp,int key){
    int len = vp.size();
    int low = 0,high = len-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(vp[mid].first == key)return vp[mid].second;
        else if(vp[mid].first < key)low = mid+1;
        else high = mid-1 ;
    }
return 0;
}

int computeValue(vector<pair<int,int> >vp,int m){
    int len = vp.size();
    int ans = m-1;
    int x,y;
    for(int i = 0; i<len; i++){
        x = vp[i].first;//j
        y = vp[i].second;//freq
        if(x-1 > 0){
            if(x+y < (x-1)+binSearch(vp,x-1)){
                ans = -1;
                break;
            }else{
                if(x == m)ans += y;
            }
        }
        if(x+1 < m+1){
            if(x+y > (x+1)+binSearch(vp,x+1)){
                ans = -1;
                break;
            }else{
                if(x == 1)ans -= y;
            }
        }
    }
    return ans;
}

void calculateFrequency(vector<int> v,vector<pair<int,int> > &vp){
    int len = v.size();
    int tmp;
    int c = 1;
    for(int i=0; i<len; i++){
        if(i == 0)tmp = v[i];
        else if(tmp == v[i])c++;
        else{
            vp.push_back(make_pair(tmp,c));
            tmp = v[i];
            c = 1;
        }
    }
    vp.push_back(make_pair(tmp,c));
}

int main(){
    int n,m,p,x,y;
    cin>>n>>m>>p;
    vector<int>vv;
    vector<vector<int> >v(n+1,vv);
    while(p--){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    int ans = m-1;
    for(int i=1; i<=n; i++){
        if(v[i].size() != 0){
            sort(v[i].begin(),v[i].end());
            vector<pair<int,int> >vp;
            calculateFrequency(v[i],vp);
            printf("%d\n",computeValue(vp,m));
        }else{
            printf("%d\n",ans);
        }
    }
return 0;
}
