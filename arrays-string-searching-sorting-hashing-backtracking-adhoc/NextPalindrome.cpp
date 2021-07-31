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
#define init_1D(a,n,value) FOR(i,0,n)a[i]=value;
#define init_2D(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

/*
ASCII 0-9 : 48 - 57
*/

bool all9s(char input[], int len){
    for(int i = 0; i<len; i++)
        if(input[i] != '9') return false;
return true;
}

int main(){
    int T;
    s(T);
    while(T--){
        char input[1000005];
        scanf("%s",input);
        int len = strlen(input);
        if(all9s(input, len)){
            printf("1");
            for(int i = 1; i <= len-1; i++)printf("0");
            printf("1\n");
            continue;
        }
        int mid = len/2;
        bool leftsmaller = false;
        int i = mid - 1;
        int j = (len % 2)? mid + 1 : mid;
        while (i >= 0 &&  input[i] == input[j]) i--,j++;
        if ( i < 0 || input[i] < input[j]) leftsmaller = true;
        while (i >= 0){
            input[j] = input[i];
            j++;
            i--;
        }
        if(leftsmaller){
            int carry = 1;
            int i = mid - 1;
            if(len%2 == 1){
                int tmp = input[mid] - 48;
                tmp += carry;
                input[mid] = (tmp%10) + 48;
                carry = tmp/10;
                j = mid + 1;
            }else j = mid;

            while (i >= 0){
                int tmp = input[i] - 48;
                tmp += carry;
                carry = tmp / 10;
                input[i] = (tmp%10) + 48;
                input[j++] = input[i--];
            }
        }
        printf("%s\n",input);
    }
}
