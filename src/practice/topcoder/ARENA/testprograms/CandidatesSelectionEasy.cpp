#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CandidatesSelectionEasy {
public:
	vector <int> sort(vector <string>, int);
};

bool myComp(pair<char,int>x,pair<char,int>y){
	if(x.first>x.second)return true;
	else return(x.second<y.second);
}

vector <int> CandidatesSelectionEasy::sort(vector <string> score, int x) {
	vector<int>v;
	vector<pair<char,int> >vp;
	for(int i = 0; i<score.size(); i++){
		vp.push_back(make_pair(score[i][x],i));
	}
	std::sort(vp.begin(),vp.end(),myComp);
	for(int i=0; i<vp.size(); i++){
		v.push_back(vp[i].second);
	}
return v;
}
//Powered by [KawigiEdit] 2.0!
