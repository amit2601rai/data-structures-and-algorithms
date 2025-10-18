#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int sum;
    int first;
    int second;
};

bool  checkValidPair(struct node a,struct node b){
    if(a.first != b.first && a.first != b.second && b.first != a.second && b.second != a.second)return true;
    return false;
}

bool fourElementSumToValue(struct node aux[],int num_pair,int sum){
    int low = 0,high = num_pair-1;
    while(low<high){
        if(aux[low].sum+aux[high].sum == sum && checkValidPair(aux[low],aux[high])){
            cout<<aux[low].first<<" "<<aux[low].second<<" "<<aux[high].first<<" "<<aux[high].second<<endl;
           low++;
           high--;
        }else if(aux[low].sum+aux[high].sum < sum){
            low++;
        }else{
            high--;
        }
    }
    return false;
}


bool mycomp(struct node a,struct node b){
    return a.sum<b.sum;
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int num_pair = (n*(n-1))/2;
    struct node aux[num_pair];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            struct node tmp;
            tmp.sum = a[i]+a[j];
            tmp.first = a[i];
            tmp.second = a[j];
            aux[k++] = tmp;
        }
    }
    sort(aux,aux+num_pair,mycomp);
    cout<<fourElementSumToValue(aux,num_pair,sum)<<endl;
return 0;
}
