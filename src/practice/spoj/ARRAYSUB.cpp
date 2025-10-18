#include<iostream>
#include <deque>
#include<cstdio>
using namespace std;
int main()
 {
     int n,k,*a;


     scanf("%d",&n);
     a=new int[n];
     for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
      scanf("%d",&k);   
     deque<int> mydeque;
     mydeque.push_back(0);
     for(int i=1;i<k;i++)
        {
           while(!mydeque.empty()&&a[mydeque.back()]<=a[i])
                 mydeque.pop_back();
                 mydeque.push_back(i);
        } 
        int i=1,j=k;
        printf("%d ",a[mydeque.front()]);
      if(mydeque.front()<i)mydeque.pop_front();  
     while(j<n)
       {
           
           while(!mydeque.empty()&&a[mydeque.back()]<=a[j])
                  mydeque.pop_back();   
                  mydeque.push_back(j);
                  printf("%d ",a[mydeque.front()]);
           i++;
           j++;   
          if(mydeque.front()<i)mydeque.pop_front();                                      
      }
  printf("\n");
return 0;
}

