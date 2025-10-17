#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int countOne = 0;
        int total = 0;
        bool f1=false,f2=false,f3=false,f4=false,f5=false,f6=false;
        for(int i=0;i<12;i++)if(str[i]=='X')countOne++;
        if(countOne == 0)cout<<"0"<<endl;
        else{
            if(countOne>0){
                f1 = true;
                total++;
            }
            if((str[0]=='X'&&str[6]=='X')||(str[1]=='X'&&str[7]=='X')||(str[2]=='X'&&str[8]=='X')||(str[3]=='X'&&str[9]=='X')
               ||(str[4]=='X'&&str[10]=='X')||(str[5]=='X'&&str[11]=='X')){
                f2= true;
                total++;
               }
            if((str[0]=='X'&& str[4]=='X' && str[8]=='X') || (str[1]=='X'&& str[5]=='X' && str[9]=='X')
                || (str[2]=='X'&& str[6]=='X' && str[10]=='X')||
               (str[3]=='X'&& str[7]=='X' && str[11]=='X')){
                f3 = true;
                total++;
               }

            if((str[0]=='X'&& str[3]=='X' && str[6]=='X' && str[9]=='X') || (str[1]=='X'&& str[4]=='X' && str[7]=='X' && str[10]=='X')
               || (str[2]=='X'&& str[5]=='X' && str[8]=='X' && str[11]=='X')){
                f4 = true;
                total++;
               }
            if((str[0]=='X'&& str[4]=='X' && str[8]=='X' && str[2]=='X' && str[6]=='X' && str[10]=='X')||
               (str[1]=='X'&& str[9]=='X' && str[3]=='X' && str[5]=='X' && str[7]=='X' && str[11]=='X')){
                f5 = true;
                total++;
               }
              if(countOne == 12){
                f6 = true;
                total++;
            }
            cout<<total;
            if(f1)cout<<" 1x12";
            if(f2)cout<<" 2x6";
            if(f3)cout<<" 3x4";
            if(f4)cout<<" 4x3";
            if(f5)cout<<" 6x2";
            if(f6)cout<<" 12x1";
            cout<<endl;
        }

    }
return 0;
}
