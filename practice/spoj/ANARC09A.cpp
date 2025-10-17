#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
       int c=1;
   	while(1)
   	{
		char str[3000];
		stack<char>mystack;
		int a=0,b=0;
		
                scanf("%s",str);
 		
		if(str[0]=='-')break;

		if(str[0]=='\0')
                   cout<<c<<". "<<"0"<<endl;
               else
                 {
		      mystack.push(str[0]);
                      for(int i=1;i<strlen(str);i++)
			{
				if(!mystack.empty()&&mystack.top()=='{'&&str[i]=='}')
	                               mystack.pop();
				else 
                                       mystack.push(str[i]);
			}
            	     while(!mystack.empty())
		       {
                            if(mystack.top()=='{')//a---> "{" and b---> "}"
                                 a++;
			    else 
                                 b++;
 			    mystack.pop();	
 		       }
    		 if(b==0)
                          cout<<c<<". "<<(a/2)<<endl;
		 else if(a==0)
                          cout<<c<<". "<<(b/2)<<endl;
	 	 else {
                          if(b%2==0)cout<<c<<". "<<a/2+b/2<<endl;
			  else
                              cout<<c<<". "<<(b-1)/2+2+(a-1)/2<<endl;

                       }
           }
           c++;
   }
return 0;
}

