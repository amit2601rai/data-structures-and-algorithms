#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int tot = 23*3600 + 59*60 + 59, h, m, s;
	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

	bool good[tot+1], flag;
	for(int i=0; i<=tot; i++) {
		flag = true;
		h = i/3600;
		m = (i-h*3600)/60;
		s = (i-h*3600-m*60);
		for(int j=0; j<17; j++) {
			if(h%p[j] == 0 && m%p[j] == 0 && s%p[j] == 0) {
				flag = false;
				break;
			}
		}
		good[i] = flag;
		//cout<<h<<":"<<m<<":"<<s<<"->"<<flag<<endl;
	}

	int ar[tot+2];
	ar[0] = 0;
	for(int i=1; i<=tot+1; i++)
		ar[i] = ar[i-1] + (good[i-1]?1:0);

	int t, g, b, time, gd;
	cin>>t;
	while(t--) {
		cin>>h>>m>>s;

		time = h*3600 + m*60 + s;
		g = ar[tot+1] - ar[time];
		b = tot - time - g + 1;
		gd = (g!=0 && b!=0)?__gcd(b,g):1;

		cout<<b/gd<<":"<<g/gd<<endl;
	}

	return 0;
}
