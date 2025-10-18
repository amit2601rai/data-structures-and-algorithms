#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

//ascii 49--->57
int main()
{
	while(1)
		{
     			char a[100000];
     			long long int b[100000];
			scanf("%s",a);
			if(a[0]=='0')break;
			b[0]=1;
			for(int i=1;i<strlen(a);i++)
			{
			
				if(a[i-1]-48==0)b[i]=b[i-1];
				else if(10*(a[i-1]-48)+(a[i]-48)<=26 && (a[i]-48)==0)
					{
                                              if(i>1)b[i]=b[i-2];
					      else b[i]=1; 
					}
				else if(10*(a[i-1]-48)+a[i]-48<=26 && a[i]-48!=0)
					{
						if(i>1)b[i]=b[i-1]+b[i-2];
						else b[i]=2;
					}
				else b[i]=b[i-1];
			}		
			printf("%lld\n",b[strlen(a)-1]);

		}


return 0;
}

