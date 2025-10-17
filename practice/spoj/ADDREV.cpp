/* Author:Amit Kr. Rai (IIIT-Hyderabad) */

#include<iostream>

using namespace std;

int reverse(int i)
{
   int a[200],count=0,num=0;
   while(i!=0)
   {
       a[count++]=i%10;
       i=i/10;
   }   

  i=1;
  count--;
  while(count>=0)
    {
        num=num+i*a[count--];
        i=i*10;
    } 
return num;
}


int main()
{
        int n,i,x,y;
        cin>>n;
       for(i=1;i<=n;i++)
        {
             cin>>x>>y;
             x=reverse(x);
             y=reverse(y);
             cout<<reverse(x+y)<<endl;
        }
 
return 0;
}

