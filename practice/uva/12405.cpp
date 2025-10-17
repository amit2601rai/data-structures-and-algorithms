#include<iostream>

using namespace std;

void cal(int n,char str[],int cases){
    int ans = 0;
    int l=0,h;
    if(n == 1)h=0;
    else if(n == 2)h=1;
    else h=2;
    while(l<n && h<n){
        if(h-l == 0){
            if(str[l] == '.')
                ans++;
            l++;
            h++;
        }else if(h-l == 1){
            if(str[l]== '.' || str[l+1] == '.')
                ans++;
            l+=2;
            h+=1;
        }
        else {
                if(str[l] == '#' && str[l+1] == '#' && str[l+2] == '#'){
                    l += 3;
                    if(h+3 < n)
                        h += 3;
                    else if(h+2 < n)
                        h += 2;
                    else
                        h += 1;
                }
                else if(str[l] == '#' && str[l+1] == '#' && str[l+2] == '.'){
                        l += 2;
                    if(h+2 < n)
                        h += 2;
                    else if(h+1 < n)
                        h += 1;
                }
                else if(str[l] == '#' && str[l+1] == '.' && str[l+2] == '#'){
                        l += 1;
                        if(h+1 < n)
                            h += 1;
                }
                else if(str[l] == '#' && str[l+1] == '.' &&  str[l+2] == '.'){
                        l += 1;
                        if(h+1 < n)
                           h += 1;
                }
                else if(str[l] == '.' && str[l+1] == '#' && str[l+2] == '#'){
                        ans++;
                        l += 3;
                        if(h+3 < n)
                            h += 3;
                        else if(h+2 < n)
                            h += 2;
                        else
                            h += 1;
                }
                else if(str[l] == '.' && str[l+1] == '#' && str[l+2] == '.'){
                        ans++;
                        l += 3;
                        if(h+3 < n)
                            h += 3;
                        else if(h+2 < n)
                            h += 2;
                        else
                            h += 1;

                }
                else if(str[l] == '.' && str[l+1] == '.' && str[l+2] == '#'){
                         ans++;
                        l += 3;
                        if(h+3 < n)
                            h += 3;
                        else if(h+2 < n)
                            h += 2;
                        else
                            h += 1;
                }
                else if(str[l] == '.' && str[l+1] == '.'  && str[l+2] == '.'){
                        ans++;
                        l += 3;
                        if(h+3 < n)
                            h += 3;
                        else if(h+2 < n)
                            h += 2;
                        else
                            h += 1;
                }
            }
    }
     cout<<"Case "<<cases<<": "<<ans<<endl;
}

int main(){
    int T,cases=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        char str[n];
        cin>>str;
        cal(n,str,cases);
        cases++;
    }
return 0;
}
