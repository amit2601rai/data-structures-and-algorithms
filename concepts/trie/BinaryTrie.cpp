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
#define init_1D(a,n,value) FOR(i,0,n)a[i]=value
#define init_2D(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX_LEVEL 3


//For n-bit number n-1 level is Required
//Given Array maximum xor between two any number

struct node{
    struct node *left;
    struct node *right;
};

typedef struct node* Node;

Node getNewNode(){
    Node tmp = (Node)malloc(sizeof(struct node));
    tmp->left = tmp->right = NULL;
return tmp;
}

Node insert(Node root, int v, int level){
    if(level == -1) return root;
    int x = ((v >> level) & 1);
    if(x){
        if(!root->right) root->right = getNewNode();
        root->right = insert(root->right, v, level-1);
    }else{
        if(!root->left) root->left = getNewNode();
        root->left = insert(root->left, v, level-1);
    }
return root;
}

void query(Node root, int v, int level, int &val){
    if(level == -1 || root == NULL) return;
    int x = ((v >> level) & 1);
    if(x){
        if(root->left){
            val += (1 << level);
            query(root->left, v, level - 1, val);
        } else query(root->right, v, level - 1, val);
    }else {
        if(root->right) {
            val += (1 << level);
            query(root->right, v, level - 1, val);
        } else query(root->left, v, level - 1, val);
    }
}

int main(){
    int n;
    s(n);
    int a[n+1];
    FOR(i,1,n) s(a[i]);
    Node root = getNewNode();
    root = insert(root, 0, MAX_LEVEL);
    int ans = INT_MIN;
    int val = 0;
    FOR(i,1,n){
        query(root, a[i], MAX_LEVEL, val);
        ans = max(ans, val);
        root = insert(root, a[i], MAX_LEVEL);
        val = 0;
    }
    p(ans);
return 0;
}
