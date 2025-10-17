#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int c,s,cases = 1;
    while(scanf("%d%d",&c,&s) != -1){
            vector<int>v;
            double avg = 0.0;
            for(int i=0;i<2*c-s;i++)
                v.push_back(0);
            for(int i=0;i<s;i++){
                int val;
                cin>>val;
                avg += val;
                v.push_back(val);
            }
           avg /= c;
           sort(v.begin(),v.end());
           int l=0,h=v.size()-1,ch=0;
           double imbalance = 0.0;
           cout<<"Set #"<<cases<<endl;
           while(l<h){
                cout<<" "<<ch<<":";
                if(v[l] !=0 && v[h] !=0)cout<<" "<<v[l]<<" "<<v[h];
                else if(v[h] != 0)cout<<" "<<v[h];
                else if(v[l] != 0)cout<<" "<<v[l];
                cout<<endl;
                imbalance += abs(v[l]+v[h]-avg);
                l++;
                h--;
                ch++;
           }
        printf("IMBALANCE = %.5lf\n\n",imbalance);
        cases++;
    }
return 0;
}
