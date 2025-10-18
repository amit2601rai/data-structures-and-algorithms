#include<iostream>
#include<algorithm>


using namespace std;


int getMedian(int a[],int low,int high){
    int num = high - low + 1;
    int mid = (low+high)/2;
    if(num % 2 == 0) return (a[mid]+a[mid+1])/2;
return a[mid];
}

int median(int a[], int b[], int n){
    int low1 = 1, high1 = n, low2 = 1, high2 = n;
    while(high1-low1 > 1 && high2 - low2 > 1){
        int mid1 = (low1+high1)/2;
        int mid2 = (low2+high2)/2;
        int m1 = getMedian(a, low1, high1);
        int m2 = getMedian(b, low2, high2);
        if(m1 == m2)return m1;
        else if(m1 > m2) low2 = mid2, high1 = mid1 + ((high1 - low1 + 1) % 2 == 0 ? 1 : 0);
        else low1 = mid1, high2 = mid2 + ((high2 - low2 + 1) % 2 == 0 ? 1 : 0);
    }
return (max(a[low1],b[low2]) + min(a[high1],b[high2]))/2;
}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    cout<<median(a,b,n)<<endl;
return 0;
}
