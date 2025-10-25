#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string intToStr(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

string encodeString(string input) {
  string ans = "";
  int c = 0;
  string x;
  for (int i = 0; i < input.size(); i++) {
    if (i == 0) {
      ans.append(1, input[i]);
      c++;
    } else if (input[i] == input[i - 1]) {
      c++;
    } else {
      x = intToStr(c);
      if (c > 1) ans.append(x);
      ans.append(1, input[i]);
      c = 1;
    }
  }
  x = intToStr(c);
  if (c > 1) ans.append(x);
  return ans;
}

/*Main Starts From Here*/
int main() {
  string str;
  cin >> str;
  cout << encodeString(str) << endl;
  return 0;
}
