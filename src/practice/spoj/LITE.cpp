#include<iostream>
#include<cstdio>
#include<string>


using namespace std;

struct node{
    int toggle;
    int sum;
};
typedef struct node node;
node tree[200000];


//Updation
void updatetree(int root,int low,int high,int u,int v)
{
    if(v<low || u>high)
        return;
     if(u<=low && high<=v){
        tree[root].toggle++;
        tree[root].sum = (high-low+1)-tree[root].sum;
        return;
     }
  int mid=(low+high)/2;
  if(tree[root].toggle !=0){
        tree[2*root].toggle += tree[root].toggle;
        tree[2*root+1].toggle += tree[root].toggle;
        if(tree[root].toggle%2 != 0){
            tree[2*root].sum = (mid-low+1)-tree[2*root].sum;
            tree[2*root+1].sum = (high-mid)-tree[2*root+1].sum;
        }
        tree[root].toggle = 0;
    }
	if(u<= mid)
        updatetree(2*root,low,mid,u,v);
	if(v>mid)
        updatetree(2*root+1,mid+1,high,u,v);
	tree[root].sum = tree[2*root].sum+tree[2*root+1].sum;
}

node addn(node a,node b){
    a.sum += b.sum;
    return a;
}


//Query
node querytree(int root,int low,int high,int u,int v)
{
    node left,right;
    left.sum = right.sum = 0;
    left.toggle = right.toggle = 0;
    int mid=(low+high)/2;
    if(v<low || u>high)
        return left;
    if(u<=low && high<=v)
        return tree[root];
    if(tree[root].toggle !=0){
        tree[2*root].toggle += tree[root].toggle;
        tree[2*root+1].toggle += tree[root].toggle;
        if(tree[root].toggle%2 != 0){
            tree[2*root].sum = ((mid-low+1)-tree[2*root].sum);
            tree[2*root+1].sum = ((high-mid)-tree[2*root+1].sum);
        }
        tree[root].toggle = 0;
    }
	if(u<= mid)
        left = querytree(2*root,low,mid,u,v);
	if(v>mid)
        right = querytree(2*root+1,mid+1,high,u,v);
    return addn(left,right);
}

int main(){
    int n,m,x,y,z;
    cin>>n>>m;
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        if(x==0){
                updatetree(1,1,n,y,z);
        }else{
                int ans = querytree(1,1,n,y,z).sum;
                printf("%d\n",ans);
        }
    }
return 0;
}
