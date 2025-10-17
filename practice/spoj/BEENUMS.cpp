#include<iostream>
#include<cstdio>
#include<map>

#define num 1000000000

using namespace std;

map<int,int>M;

void precalculate()
{
   int count=1;
   long long val=1; 
   M[1]=1;
   while(val<=num)
   {
       val+=6*(count++);
       M[val]=1;
   }

}

int main()
{
   precalculate();
   int x;
   while(1)
   {
       scanf("%d",&x);
       if(x==-1)break;
       if(M[x]==1)cout<<"Y"<<endl;
       else cout<<"N"<<endl;
   }
return 0;
}

