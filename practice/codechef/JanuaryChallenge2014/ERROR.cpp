#include<iostream>
#include<cstring>

using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
            char str[100005];
            cin>>str;
            int len = strlen(str);
            if(len<3){
                cout<<"Bad"<<endl;
                continue;
            }else{
                int i = 0,j=1,k=2,flag=0;
                while(k<len){
                    if(str[i] == '0'  && str[j] == '1' && str[k] == '0'){
                        cout<<"Good"<<endl;
                        flag = 1;
                        break;
                    }
                    else if(str[i] == '1'  && str[j] == '0' && str[k] == '1'){
                            cout<<"Good"<<endl;
                            flag = 1;
                            break;
                    }
                    i++;j++;k++;
                }
                if(flag == 0)cout<<"Bad"<<endl;
            }
    }
return 0;
}
