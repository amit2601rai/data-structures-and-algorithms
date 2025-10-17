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

class PairGameEasy {
public:
	string able(int, int, int, int);
};

bool func(int a, int b,int c,int d){
	if(a == c && b == d)return true;
	if(a > c || b > d)return false;
	return func(a,a+b,c,d) || func(a+b,b,c,d);
}
string PairGameEasy::able(int a, int b, int c, int d) {
	if(func(a,b,c,d))return "Able to generate";
	else return "Not able to generate";
}

//Powered by [KawigiEdit] 2.0!
