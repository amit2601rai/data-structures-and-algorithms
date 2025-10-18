#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll solve(int pos, int tight, int leading_zeroes, int prev_digit, string num, vector<vector<vector<ll>>> &dp) {
  if (static_cast<size_t>(pos) == num.size()) return 1;

  if (dp[pos][tight][leading_zeroes] != -1) return dp[pos][tight][leading_zeroes];

  ll result = 0;
  int limit = tight ? num[pos] - '0' : 9;
  for (int i = 0; i <= limit; i++) {
    int new_tight = tight && (i == limit) ? 1 : 0;
    int new_leading_zeroes = leading_zeroes && (i == 0) ? 1 : 0;
    if (leading_zeroes) {
      result += solve(pos + 1, new_tight, new_leading_zeroes, i, num, dp);
    } else if (i != prev_digit) {
      result += solve(pos + 1, new_tight, new_leading_zeroes, i, num, dp);
    }
  }
  return dp[pos][tight][leading_zeroes] = result;
}

int main() {
  ll a, b;
  cin >> a >> b;
  string sa = to_string(a - 1);
  string sb = to_string(b);

  // Initialize DP vectors for both strings
  vector<vector<vector<ll>>> dp_a(sa.length(), vector<vector<ll>>(2, vector<ll>(2, -1)));
  vector<vector<vector<ll>>> dp_b(sb.length(), vector<vector<ll>>(2, vector<ll>(2, -1)));

  cout << solve(0, 1, 1, -1, sb, dp_b) - solve(0, 1, 1, -1, sa, dp_a) << endl;

  return 0;
}