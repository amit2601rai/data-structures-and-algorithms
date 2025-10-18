//Author : Amit Rai (IIIT Hyderabad)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;

int lps[1001];


/*Longest prefix (Which is also suffix) computation*/
/* lps(a) = empty string
   lps(aa) = a
   lps(aba) = a
   lps(aabaab) = aab
*/
void prefix(char P[]){
	int m,cur=0;
	m=strlen(P);
	lps[0]=0;
	for(int i=1;i<m;i++){
		if(P[cur]==P[i]){
			lps[i] = lps[i-1]+1;
			cur++;
		}
		else{
            cur=0;
            if(P[cur]==P[i]){
                lps[i]=1;
                cur++;
            }
            else lps[i]=0;
        }
	}
}


/*kmp matcher*/
int kmp(char T[],char P[])
{
	int i=0,j=0,n,m,l=0;
	n=strlen(T);
	m=strlen(P);
	while(i<n){
		if(P[j]==T[i]){
			j++;
			i++;
			if(j==m)
			   return (i-j);
		}
		else{
			if(j==0)
				i++;
			else
				j = lps[j-1];
		}
	}
return -1;
}

/*Main Function*/
int main()
{
	char T[1001];
	char P[1001];
	scanf("%s",T);
	scanf("%s",P);
	prefix(P);
	for(int i=0;i<strlen(P);i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	cout<<"index = "<<kmp(T,P)<<endl;
return 0;
}
