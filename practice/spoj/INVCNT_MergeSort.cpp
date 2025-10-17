#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

long long int mergeSubArray(int a[],int low,int mid,int high){
    int left = low;
    int right = mid+1;
    int temp[high-low+1];
    int k=0;
	long long int invCount = 0;
    while(left < mid+1 && right < high+1){
        if(a[left] <= a[right]){
            temp[k++] = a[left++];
        }else{
            temp[k++] = a[right++];
            invCount += (mid - left + 1);
        }
    }
    while(left < mid+1){
        temp[k++] = a[left++];
    }
    while(right < high+1){
        temp[k++] = a[right++];
    }
    for(int i = 0;i<k;i++){
        a[low++] = temp[i];
    }
    return invCount;
}

long long int mergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        return mergeSort(a,low,mid)+ mergeSort(a,mid+1,high)+ mergeSubArray(a,low,mid,high);
    }
return 0;
}

long long int countInversion(int a[],int n){
    return mergeSort(a,0,n-1);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        cout<<countInversion(a,n)<<endl;
    }
    return 0;
}

