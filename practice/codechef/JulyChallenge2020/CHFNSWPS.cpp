/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

long long minSwapCost(map<long long, long long>a, map<long long, long long>b, long long minVal) {
	long long ans = 0;
	auto p = a.begin();
	auto q = b.rbegin();

	while (p != a.end() && q != b.rend()) {
		long long x1 = p->first;
		long long c1 = p->second;

		long long x2 = q->first;
		long long c2 = q->second;

		ans += min(min(x1,x2)*min(c1,c2), 2*minVal*min(c1,c2));

		a[x1] = c1 - min(c1,c2);
		b[x2] = c2 - min(c1,c2);

		if(c1 == c2){
			p++;
			q++;
		}
		else if (c1 < c2) p++;
		else q++;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		long long minVal = LONG_MAX;
		int n;
		cin>>n;

		map<long long, long long> freq;
	
		for (int i = 1; i <=n; i++) {
			long long val;
			cin>>val;
			minVal = min(val, minVal);
			freq[val]++;
		}

		for (int i = 1; i <=n; i++) {
			long long val;
	 		cin>>val;
	 		minVal = min(val, minVal);
			freq[val]--;
		}

		map<long long, long long> a;
		map<long long, long long> b;

		bool invalid = false;

		for (auto entry = freq.begin(); entry != freq.end(); entry++) {
			if(abs(entry->second) % 2 != 0) {
				invalid = true;
				break;
			}
			if(entry->second < 0) {
				b[entry->first] = abs(entry->second)/2;
			} else {
				a[entry->first] = abs(entry->second)/2;
			}
		}
		if (invalid) {
			cout<<"-1"<<endl;
		} else cout<<minSwapCost(a,b, minVal)<<endl;

	}
	return 0;
}
