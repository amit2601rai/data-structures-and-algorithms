#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<cassert>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007

typedef struct ll{
    int leftc;
    int rightc;
    struct ll * left;
    struct ll * right;
}node;

node * insert(node * root, unsigned int n, int level){
    if(level==-1)return root;
    unsigned int x=((n>>level)&1);
    if(x){
        root->rightc++;
        if(root->right==NULL){
            root->right=(node *)malloc(sizeof(node));
            root->right->leftc=root->right->rightc=0;
        }
        root->right=insert(root->right,n,level-1);
    }
    else{
        root->leftc++;
        if(root->left==NULL){
            root->left=(node *)malloc(sizeof(node));
            root->left->leftc=root->left->rightc=0;
        }
        root->left=insert(root->left,n,level-1);
    }
    return root;
}

unsigned int query( node * root, unsigned int n, int level, unsigned int k){
    if(level==-1 || root==NULL)return 0;
    unsigned int p=((n>>level)&1);
    unsigned int q=((k>>level)&1);
    if(q){
        if(p==0)return root->leftc+query(root->right,n,level-1,k);
        else return root->rightc+query(root->left,n,level-1,k);
    }
    else{
        if(p==0)
            return query(root->left,n,level-1,k);
        else
            return query(root->right,n,level-1,k);
    }
}

void print(node * root){
    if(root==NULL)return ;
    printf("'%d %d'\n",root->leftc,root->rightc);
    print(root->left);
    print(root->right);
}

int main(){
    int t;
    sd(t);
    while(t--){
        node * root;
        root=(node *)malloc(sizeof(node));
        root->left=root->right=NULL;
        root->leftc=root->rightc=0;
        root=insert(root,0,20);
        unsigned int n,i,j,p=0,x,q,k;
        long long int ans=0;
        scanf("%u%u",&n,&k);
        assert(k>=1 && k<=1000000);
        for(i=0; i<n; i++){
            scanf("%u",&x);
            q=p^x;
            ans+=(LL)(query(root,q,20,k));
            root=insert(root,q,20);
            p=q;
        }
       // print(root);
        printf("%lld\n",ans);
    }
    return 0;
}
