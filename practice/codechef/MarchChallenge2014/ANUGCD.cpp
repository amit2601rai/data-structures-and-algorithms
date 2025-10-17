/*Author:Amit(IIIT-H)*/
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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define MAX 100000
#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)


struct element{
    int primefactor,maximum,frequency;
};
typedef struct element element;
struct node{
    vector<element>v;
};
typedef struct node node;
vector<node>tree(3*MAX+1);

vector<int>primeFactors[MAX+1];

//Prime Generation
void primeFactorGeneration(){
    vector<int>f(MAX+1);
    FOR(i,1,MAX)f[i] = i;
    for(int i = 2;i*i<=MAX;i++){
        for(int j=i;j<=MAX;j += i){
            bool flag = false;
            while(f[j]%i == 0){
                flag = true;
                f[j] = f[j]/i;
            }
            if(flag)primeFactors[j].pb(i);
        }
    }
    FOR(i,2,MAX){
        if(f[i] != 1){
            primeFactors[i].pb(f[i]);
            f[i] = 1;
        }
    }
    f.clear();
}

//Query Function
ii comp(ii e_left,ii e_right){
    ii result;
    result.first = result.second = -1;
    if(e_left.first == -1)return e_right;
    else if(e_right.first == -1)return e_left;
    else {
            if(e_right.first == e_left.first){
                result.first = e_left.first;
                result.second = e_left.second + e_right.second;
            }else if(e_right.first > e_left.first){
                result.first = e_right.first;
                result.second = e_right.second;
            }
            else {
                result.first = e_left.first;
                result.second = e_left.second;
            }
        return result;
    }

}

int b_search(int key,int root){
    int low = 0;
    int high = tree[root].v.size() -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(tree[root].v[mid].primefactor == key)return mid;
        if(tree[root].v[mid].primefactor < key)low = mid+1;
        else high = mid-1;
    }
    return -1;
}

ii eval(int g,int root){
    ii result;
    result.first = result.second = -1;
    for(int i=0;i<primeFactors[g].size();i++){
        int index = b_search(primeFactors[g][i],root);
        if(index != -1){
            if(result.first < tree[root].v[index].maximum){
                result.first = tree[root].v[index].maximum;
                result.second = tree[root].v[index].frequency;
            }
        }
    }
    return result;
}

ii Query(int root,int low,int high,int g,int u,int v){
    ii e_left;
    ii e_right;
    e_left.first = e_left.second = -1;
    e_right.first = e_right.second = -1;
    int mid = (low+high)/2;
    if(v<low || u>high)
        return e_left;
    if(u<=low && high<=v)
        return eval(g,root);
    if(u<= mid)
        e_left = Query(2*root,low,mid,g,u,v);
	if(v>mid)
        e_right = Query(2*root+1,mid+1,high,g,u,v);
    return comp(e_left,e_right);
}

//Tree Construction
void nodeFillUp(int root,int input){
    node T;
    for(int i=0;i<primeFactors[input].size();i++){
        element e;
        e.primefactor = primeFactors[input][i];
        e.maximum = input;
        e.frequency = 1;
        T.v.pb(e);
    }
    tree[root] = T;
}

void nodeLeftMerge(int root,int left,vector<element>v_left){
    element e;
    e.primefactor = v_left[left].primefactor;
    e.maximum = v_left[left].maximum;
    e.frequency = v_left[left].frequency;
    tree[root].v.pb(e);
}

void nodeRightMerge(int root,int right,vector<element>v_right){
     element e;
     e.primefactor = v_right[right].primefactor;
     e.maximum = v_right[right].maximum;
     e.frequency = v_right[right].frequency;
     tree[root].v.pb(e);
}

void nodeMerge(int root){
    vector<element>v_left = tree[2*root].v;
    vector<element>v_right = tree[2*root+1].v;
    int left = 0,right = 0;
    int len_left = v_left.size();
    int len_right = v_right.size();
    while(left<len_left && right<len_right){
        if(v_left[left].primefactor == v_right[right].primefactor){
            if(v_left[left].maximum == v_right[right].maximum){
                element e;
                e.primefactor = v_left[left].primefactor;
                e.maximum = v_left[left].maximum;
                e.frequency = v_left[left].frequency + v_right[right].frequency;
                tree[root].v.pb(e);
            }else{
                if(v_left[left].maximum < v_right[right].maximum){
                    nodeRightMerge(root,right,v_right);
                }else{
                    nodeLeftMerge(root,left,v_left);
                }
            }
            left++;
            right++;
        }else if(v_left[left].primefactor < v_right[right].primefactor){
            nodeLeftMerge(root,left,v_left);
            left++;
        }else{
            nodeRightMerge(root,right,v_right);
            right++;
        }
    }
    while(left < len_left){
        nodeLeftMerge(root,left,v_left);
        left++;
    }
    while(right < len_right){
       nodeRightMerge(root,right,v_right);
       right++;
    }
}

void buildTree(int root,int low,int high,int input[]){
    if(low == high){
        nodeFillUp(root,input[low]);
        return;
    }
    int mid = (low+high)/2;
    buildTree(2*root,low,mid,input);
    buildTree(2*root+1,mid+1,high,input);
    nodeMerge(root);
}

int main(){
    primeFactorGeneration();
    int n,m,g,x,y;
    scanf("%d%d",&n,&m);
    int input[n+1];
    FOR(i,1,n){
        scanf("%d",&input[i]);
    }
    buildTree(1,1,n,input);
    while(m--){
        scanf("%d%d%d",&g,&x,&y);
        ii e = Query(1,1,n,g,x,y);
        printf("%d %d\n",e.first,e.second);
    }
return 0;
}
