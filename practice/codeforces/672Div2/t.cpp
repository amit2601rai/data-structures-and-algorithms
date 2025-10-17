#include<bits/stdc++.h> 

using namespace std; 

typedef long long ll;
  
int main() { 
    freopen("input", "w", stdout); 
  
    srand(time(NULL)); 

    int MAX = 1e9+1;
    int N = 1;
    int K = 95742;
    cout<<N<<" "<<K<<endl;
  
    for (int i=1; i<= N; i++) 
        printf("%d %d", rand() % MAX, rand() % MAX); 
  
    fclose(stdout); 
    return(0); 
} 