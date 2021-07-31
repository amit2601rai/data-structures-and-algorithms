#include<iostream>

using namespace std;


int main(){
	float x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	cin>>x4>>y4;
	if(!( y2 < y3 || y1 > y4 || x2 < x3 || x1 > x4 ))
	cout<<"overlapping"<<endl;
	else cout<<"Not overlapping"<<endl;
	return 0;
}
