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

int getLevelOfNode(int x){
    int total = 1;
    int level = 0;
    while(total < x+1){
        total *= 2;
        level++;
    }
return level - 1;
}


int getNodes(int flag,int level_xy, int level_x, int level_y){
    int countNodes = 0;
    if(level_xy % 2 == flag)countNodes++;
    if((level_xy+1) % 2 != flag) level_xy += 2;
    else level_xy += 1;
    if(level_x % 2 != flag) level_x--;
    if(level_y % 2 != flag) level_y--;
    int ans = (level_x + level_y - 2*level_xy)/2 + 2 + countNodes;
    return ans;
}


int getNumberOfNodes(int flag, int x, int y){
    int level_x = getLevelOfNode(x);
    int level_y = getLevelOfNode(y);
    int lca_xy;
    map<int,int>M;
    while(x != 0){
        M[x] = 1;
        x /= 2;
    }
    while(y != 0){
        if(M[y] == 1){lca_xy = y; break;}
        y /= 2;
    }
    int level_xy = getLevelOfNode(lca_xy);
   // cout<<"level_xy = "<<level_xy<<"level_x = "<<level_x<<"level_y = "<<level_y<<endl;
    return getNodes(flag, level_xy, level_x, level_y);
}

int main(){
    int black = 0, red = 1;
    int Q;
    string qs;
    cin>>Q;
    while(Q--){
        cin>>qs;
        int x,y;
        if(qs.compare("Qr") == 0){
            cin>>x>>y;
            cout<<getNumberOfNodes(red,x,y)<<endl;
        }
        else if(qs.compare("Qb") == 0){
            cin>>x>>y;
            cout<<getNumberOfNodes(black,x,y)<<endl;
        }
        else { black = (black+1)%2; red = (red+1)%2;}
    }
return 0;
}


