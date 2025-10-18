#include<iostream>
#include<algorithm>

using namespace std;


struct box
{
	int area;
	int height;
	int length;
	int breadth;
};


bool comparator(struct box a,struct box b)
{
    return (a.area>b.area);   
}

int main()
{
  while(1)
  {
	int n;
	cin>>n;
	if(n==0)
	   break;
    struct box boxes[3*n+1];
	int k=0;
	for(int i=1;i<=n;i++)
	{
	  
		int l,h,b;
		cin>>h>>l>>b;
		k++;
		boxes[k].area=l*b;
		boxes[k].height=h;
		boxes[k].length=max(l,b);
		boxes[k].breadth=min(l,b);
		k++;
		boxes[k].area=l*h;
		boxes[k].height=b;
		boxes[k].length=max(l,h);
		boxes[k].breadth=min(l,h);
		k++;
		boxes[k].area=h*b;
		boxes[k].height=l;
		boxes[k].length=max(h,b);
		boxes[k].breadth=min(h,b);
	}
    sort(boxes+1,boxes+3*n+1,comparator);
   
/*  	 for(int i=1;i<=3*n;i++)
         {
			cout<<"[";
   	    	cout<<boxes[i].area<<" ";
			cout<<" ("<<boxes[i].length<<" "<<boxes[i].breadth<<")";
			cout<< boxes[i].height<<"]";
			cout<<endl;
         }
            cout<<endl;
   */
   int temp=-1;
   int ans[3*n+1];
   for(int i=1;i<=3*n;i++)
       ans[i]=boxes[i].height;
  // for(int i=1;i<=3*n;i++)
	//   cout<<boxes[i].height<<" ";
  // cout<<endl;

   for(int i=1;i<=3*n;i++)
   {
	    int ttemp=ans[i];
   	  for(int j=i-1;j>=1;j--)
		{
			//cout<<"j ="<<j<<" "<<"i= "<<i<<endl;
			//cout<<"("<<boxes[j].length<<" "<<boxes[j].breadth<<") ("<<boxes[i].length<<boxes[i].breadth<<")"<<endl;
			if(boxes[j].length>boxes[i].length && boxes[j].breadth>boxes[i].breadth)
			{
	//		cout<<"j ="<<j<<" "<<"i= "<<i<<endl;
	//		cout<<"("<<boxes[j].length<<" "<<boxes[j].breadth<<") ("<<boxes[i].length<<boxes[i].breadth<<")"<<endl;
				     
			        ans[i]=max(ans[i],ttemp+ans[j]);
			}
		}
	 // cout<<"------------->"<<ans[i]<<endl;;
	  temp=max(temp,ans[i]);
   }
  // cout<<endl;
   cout<<temp<<endl;
 }
return 0;
}

