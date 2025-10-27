# CSES Problem Set - Solutions Guide

A comprehensive guide with explanations for CSES competitive programming problems solved in this repository.

## Table of Contents

### Introductory Problems
- [1068 - Weird Algorithm](#1068---weird-algorithm)
- [1069 - Repetitions](#1069---repetitions)
- [1070 - Permutations](#1070---permutations)
- [1071 - Number Spiral](#1071---number-spiral)
- [1083 - Missing Number](#1083---missing-number)
- [1094 - Increasing Array](#1094---increasing-array)

### Sorting and Searching
- [1074 - Stick Lengths](#1074---stick-lengths)
- [1084 - Apartments](#1084---apartments)
- [1090 - Ferris Wheel](#1090---ferris-wheel)
- [1091 - Concert Tickets](#1091---concert-tickets)
- [1141 - Playlist](#1141---playlist)
- [1158 - Book Shop](#1158---book-shop)
- [1621 - Distinct Numbers](#1621---distinct-numbers)
- [1629 - Movie Festival](#1629---movie-festival)
- [1640 - Sum of Two Values](#1640---sum-of-two-values)
- [2183 - Missing Coin Sum](#2183---missing-coin-sum)
- [2216 - Collecting Numbers](#2216---collecting-numbers)
- [2220 - Collecting Numbers II](#2220---collecting-numbers-ii)

### Dynamic Programming
- [1092 - Two Sets](#1092---two-sets)
- [1093 - Two Sets II](#1093---two-sets-ii)
- [1097 - Removal Game](#1097---removal-game)
- [1145 - Increasing Subsequence](#1145---increasing-subsequence)
- [1633 - Dice Combinations](#1633---dice-combinations)
- [1634 - Minimizing Coins](#1634---minimizing-coins)
- [1635 - Coin Combinations I](#1635---coin-combinations-i)
- [1636 - Coin Combinations II](#1636---coin-combinations-ii)
- [1637 - Removing Digits](#1637---removing-digits)
- [1638 - Grid Paths](#1638---grid-paths)
- [1744 - Rectangle Cutting](#1744---rectangle-cutting)
- [1745 - Money Sums](#1745---money-sums)
- [1746 - Array Description](#1746---array-description)
- [**2413 - Counting Towers**](#2413---counting-towers) ⭐

### Graph Algorithms
- [1192 - Counting Rooms](#1192---counting-rooms)
- [1193 - Labyrinth](#1193---labyrinth)
- [1666 - Building Teams](#1666---building-teams)

### Mathematics
- [1617 - Bit Strings](#1617---bit-strings)
- [1618 - Trailing Zeros](#1618---trailing-zeros)
- [1619 - Restaurant Customers](#1619---restaurant-customers)
- [1623 - Apple Division](#1623---apple-division)
- [1754 - Coin Piles](#1754---coin-piles)
- [3421 - XOR Pyramid](#3421---xor-pyramid)

### Range Queries
- [1643 - Maximum Subarray Sum](#1643---maximum-subarray-sum)

### Additional Problems
- [3359 - Download Speed](#3359---download-speed)

---

## Introductory Problems

### 1068 - Weird Algorithm
[Problem Link](https://cses.fi/problemset/task/1068)

**Problem:** Given integer n, repeatedly apply: if even divide by 2, if odd multiply by 3 and add 1. Print the sequence until n=1.

**Approach:** Simulation - implement the Collatz conjecture

**Your Solution:**
```cpp
long long n;
cin >> n;
while (n > 1) {
    cout << n << " ";
    if (n % 2 == 0)
        n /= 2;
    else
        n = 3 * n + 1;
}
cout << n << endl;
```

✅ **Good practices:**
- Used `long long` to handle large intermediate values (e.g., 3*n+1 can overflow int)
- Simple, clean implementation

**Complexity:** O(log n) on average

---

### 1069 - Repetitions
[Problem Link](https://cses.fi/problemset/task/1069)

**Problem:** Find the maximum length of a sequence of consecutive equal characters in a DNA string.

**Approach:** Single pass with counter

```cpp
int maxLen = 1, currentLen = 1;
for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i-1])
        currentLen++;
    else {
        maxLen = max(maxLen, currentLen);
        currentLen = 1;
    }
}
```

**Complexity:** O(n) time, O(1) space

---

### 1070 - Permutations
[Problem Link](https://cses.fi/problemset/task/1070)

**Problem:** Create a permutation of numbers 1 to n where no adjacent elements differ by 1.

**Approach:** Special construction
- If n=1: print 1
- If n≤3: impossible
- Otherwise: print all even numbers first, then all odd numbers

```cpp
if (n == 1) cout << 1;
else if (n <= 3) cout << "NO SOLUTION";
else {
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
}
```

**Complexity:** O(n)

---

### 1071 - Number Spiral
[Problem Link](https://cses.fi/problemset/task/1071)

**Problem:** Given position (y,x) in an infinite spiral, find the number at that position.

**Approach:** Mathematical pattern recognition
- Find which "layer" the position is in (max(x,y))
- Determine if we're in the row-major or column-major part
- Calculate the value based on the pattern

**Complexity:** O(1) per query

---

### 1083 - Missing Number
[Problem Link](https://cses.fi/problemset/task/1083)

**Problem:** Find the missing number from 1 to n when given n-1 numbers.

**Approach:** Sum formula
- Expected sum = n*(n+1)/2
- Actual sum = sum of given numbers
- Missing = Expected - Actual

**Complexity:** O(n)

---

### 1094 - Increasing Array
[Problem Link](https://cses.fi/problemset/task/1094)

**Problem:** Minimum number of moves to make array non-decreasing (each move increases an element by 1).

**Approach:** Greedy
- For each element, if it's less than previous, increase it to match previous
- Count total increases

```cpp
long long moves = 0;
for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i-1]) {
        moves += arr[i-1] - arr[i];
        arr[i] = arr[i-1];
    }
}
```

**Complexity:** O(n)

---

## Sorting and Searching

### 1074 - Stick Lengths
[Problem Link](https://cses.fi/problemset/task/1074)

**Problem:** Find minimum cost to make all sticks same length (cost = sum of differences).

**Approach:** Median minimizes sum of absolute differences
- Sort the array
- Median is at position n/2
- Sum distances from all sticks to median

**Complexity:** O(n log n)

---

### 1084 - Apartments
[Problem Link](https://cses.fi/problemset/task/1084)

**Problem:** Match applicants to apartments where apartment size must be within k of desired size.

**Approach:** Two pointers with range matching

**Your Solution:**
```cpp
// Store desired apartment range for each applicant
vector<pair<int, int>> ds(n);
for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ds[i] = make_pair(x - k, x + k);  // [min, max] acceptable
}

sort(ds.begin(), ds.end());
sort(as.begin(), as.end());

int ans = 0, p = 0, q = 0;
while (p < n && q < m) {
    if (ds[p].first <= as[q] && as[q] <= ds[p].second)
        ans++, p++, q++;          // Match found
    else if (as[q] < ds[p].first)
        q++;                      // Apartment too small, try next
    else
        p++;                      // Apartment too large, try next applicant
}
```

✅ **Good practices:**
- Clever use of pair to store acceptable range [desired-k, desired+k]
- Efficient two-pointer matching
- Clear logic for three cases

**Complexity:** O(n log n + m log m)

---

### 1090 - Ferris Wheel
[Problem Link](https://cses.fi/problemset/task/1090)

**Problem:** Minimum gondolas needed (capacity x, max 2 people per gondola).

**Approach:** Two pointers (greedy pairing)

**Your Solution:**
```cpp
sort(v.begin(), v.end());
int p = 0, q = n - 1;
int ans = 0;
while (p <= q) {
    if (v[p] + v[q] <= x)
        p++, q--;              // Pair lightest with heaviest
    else
        q--;                   // Heaviest goes alone
    ans++;                     // Count gondola in both cases
}
```

✅ **Good practices:**
- Clean greedy approach: always try to pair
- Counts gondola regardless of pairing (correct!)
- Note: `p <= q` handles odd case where one person remains

**Complexity:** O(n log n)

---

### 1091 - Concert Tickets
[Problem Link](https://cses.fi/problemset/task/1091)

**Problem:** Sell tickets to customers (each wants max price they can afford).

**Approach:** Multiset with binary search

**Your Solution:**
```cpp
multiset<int> ms;
for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    ms.insert(val);
}

for (int j = 0; j < m; j++) {
    int val;
    cin >> val;
    if (ms.size() == 0) {
        cout << "-1";
        continue;
    }
    auto it = ms.lower_bound(val);
    if (it != ms.end()) {
        if ((*it) == val) {
            cout << (*it) << endl;
            ms.erase(it);
        } else {
            if (it != ms.begin()) it--;
            if ((*it) < val) {
                cout << (*it) << endl;
                ms.erase(it);
            } else
                cout << "-1" << endl;
        }
    } else {
        it--;
        cout << (*it) << endl;
        ms.erase(it);
    }
}
```

✅ **Good practices:**
- Correctly handles all edge cases
- Uses multiset to allow duplicate ticket prices

💡 **Alternative approach (simpler):**
```cpp
auto it = ms.upper_bound(val);  // First ticket > val
if (it == ms.begin()) {
    cout << "-1\n";             // No ticket ≤ val
} else {
    --it;                       // Largest ticket ≤ val
    cout << *it << "\n";
    ms.erase(it);
}
```

**Complexity:** O(n log n + m log n)

---

### 1141 - Playlist
[Problem Link](https://cses.fi/problemset/task/1141)

**Problem:** Longest substring with unique songs.

**Approach:** Sliding window with hash map

**Your Solution:**
```cpp
map<int, int> lastIdx;
for (int i = 0; i < n; i++) {
    cin >> v[i];
    lastIdx[v[i]] = -1;  // Initialize all to -1
}

int ans = 1;
int s = 0, e = 0, idx = 0;
while (idx < n) {
    if (lastIdx[v[idx]] != -1) {
        s = max(s, lastIdx[v[idx]] + 1);  // Jump start past duplicate
    }
    e = idx;
    ans = max(ans, e - s + 1);
    lastIdx[v[idx]] = idx;
    idx++;
}
```

✅ **Good practices:**
- Correctly uses `max(s, lastIdx[v[idx]] + 1)` to avoid moving start backward
- Track both start (s) and end (e) pointers explicitly

💡 **Note:** Initialization to -1 is good, ensures first occurrence works correctly

**Complexity:** O(n)

---

### 1158 - Book Shop
[Problem Link](https://cses.fi/problemset/task/1158)

**Problem:** 0/1 Knapsack - maximize pages with budget constraint.

**Approach:** Standard DP knapsack

```cpp
dp[i][j] = max pages using first i books with budget j
dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i]] + pages[i])
```

**Complexity:** O(n × budget)

---

### 1621 - Distinct Numbers
[Problem Link](https://cses.fi/problemset/task/1621)

**Problem:** Count distinct numbers in array.

**Approach:** Sort and count or use set

```cpp
sort(arr.begin(), arr.end());
int distinct = 1;
for (int i = 1; i < n; i++)
    if (arr[i] != arr[i-1])
        distinct++;
```

**Complexity:** O(n log n)

---

### 1629 - Movie Festival
[Problem Link](https://cses.fi/problemset/task/1629)

**Problem:** Maximum non-overlapping intervals (activity selection).

**Approach:** Greedy by end time

**Your Solution:**
```cpp
vector<pair<int, int>> intervals;
for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    intervals.push_back(make_pair(y, x));  // Store as (end, start)
}
sort(intervals.begin(), intervals.end());  // Sorts by end time

int ans = 1;
int val = intervals[0].first;  // Last movie end time
for (int i = 1; i < n; i++) {
    if (intervals[i].second < val)  // Start < last end: overlap
        continue;
    else {
        ans++;
        val = intervals[i].first;   // Update end time
    }
}
```

✅ **Good practices:**
- Smart trick: store as `(end, start)` to automatically sort by end time!
- Clear logic: skip if overlapping, otherwise take movie

💡 **Alternative:** Can also use `intervals[i].second >= val` for the condition (more standard)

**Complexity:** O(n log n)

---

### 1640 - Sum of Two Values
[Problem Link](https://cses.fi/problemset/task/1640)

**Problem:** Find two numbers that sum to target (return indices).

**Approach:** Two pointers after sorting (keep track of original indices)

**Your Solution:**
```cpp
vector<pair<int, int>> v(n);
for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    v[i] = make_pair(val, i);  // Store (value, original_index)
}
sort(v.begin(), v.end());

int low = 0, high = n - 1;
while (low < high) {
    if (v[low].first + v[high].first == sum) {
        cout << v[low].second + 1 << " " << v[high].second + 1 << endl;
        return 0;
    } else if (v[low].first + v[high].first < sum)
        low++;
    else
        high--;
}
cout << "IMPOSSIBLE" << endl;
```

✅ **Good practices:**
- Preserves original indices before sorting
- Standard two-pointer technique
- Handles "IMPOSSIBLE" case

**Complexity:** O(n log n)

---

### 2183 - Missing Coin Sum
[Problem Link](https://cses.fi/problemset/task/2183)

**Problem:** Find smallest sum that cannot be created using subset of coins.

**Approach:** Greedy observation

**Your Solution:**
```cpp
ll solve(int n, vector<ll> &v) {
    if (v[0] != 1) return 1;  // If first coin > 1, can't make 1
    
    ll high = 1;  // Max sum we can create so far
    for (int i = 1; i < n; i++) {
        if (v[i] - high < 2)      // If v[i] <= high+1
            high = high + v[i];   // Extend range [0, high+v[i]]
        else
            break;                // Gap found!
    }
    return high + 1;
}

sort(v.begin(), v.end());
cout << solve(n, v) << endl;
```

✅ **Good practices:**
- Checks edge case: if first coin > 1, answer is 1
- Clean condition `v[i] - high < 2` equivalent to `v[i] <= high + 1`

**Key insight:** If we can make all sums [0, high] and next coin ≤ high+1, we can now make [0, high + coin]. If coin > high+1, there's a gap!

💡 **Equivalent condition:** `v[i] <= high + 1` is more readable than `v[i] - high < 2`

**Complexity:** O(n log n)

---

### 2216 - Collecting Numbers
[Problem Link](https://cses.fi/problemset/task/2216)

**Problem:** Count rounds needed to collect numbers 1 to n in order from array.

**Approach:** Track position of each number
- Count how many times we "restart" from beginning
- Restart happens when next number appears before current in array

```cpp
vector<int> position(n+1);
for (int i = 0; i < n; i++)
    position[arr[i]] = i;

int rounds = 1;
for (int i = 2; i <= n; i++)
    if (position[i] < position[i-1])
        rounds++;
```

**Complexity:** O(n)

---

### 2220 - Collecting Numbers II
[Problem Link](https://cses.fi/problemset/task/2220)

**Problem:** Same as 2216 but with updates (swap operations).

**Approach:** Digit DP with tight/leading zeros tracking

**Complexity:** O(m × updates)

---

## Dynamic Programming

### 1092 - Two Sets
[Problem Link](https://cses.fi/problemset/task/1092)

**Problem:** Divide numbers 1 to n into two sets with equal sum.

**Approach:** Mathematical
- Total sum = n*(n+1)/2, must be even
- If achievable, greedily pick numbers starting from n

```cpp
long long sum = n * (n + 1) / 2;
if (sum % 2 != 0)
    return "NO";

// Greedily pick from largest
long long target = sum / 2, current = 0;
while (n > 0) {
    if (current + n <= target) {
        set1.push(n);
        current += n;
    } else {
        set2.push(n);
    }
    n--;
}
```

**Complexity:** O(n)

---

### 1093 - Two Sets II
[Problem Link](https://cses.fi/problemset/task/1093)

**Problem:** Count ways to divide 1 to n into two equal-sum sets.

**Approach:** DP counting
- Similar to subset sum
- dp[i][j] = ways to make sum j using first i numbers
- Answer needs to divide by 2 (sets are unordered)

**Complexity:** O(n × sum)

---

### 1097 - Removal Game
[Problem Link](https://cses.fi/problemset/task/1097)

**Problem:** Two players alternately remove from ends, maximize your score.

**Approach:** Interval DP
- dp[i][j] = max advantage player 1 can get in range [i,j]
- dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1])

**Complexity:** O(n²)

---

### 1145 - Increasing Subsequence
[Problem Link](https://cses.fi/problemset/task/1145)

**Problem:** Longest Increasing Subsequence (LIS).

**Approach:** Binary search with DP

**Your Solution:**
```cpp
vector<int> dp(n, -1);
dp[0] = v[0];
int max_len = 1;

for (int i = 1; i < n; i++) {
    // lower_bound gives the position to replace or extend
    auto start = dp.begin();
    auto end = dp.begin() + max_len;
    auto it = lower_bound(start, end, v[i]);
    
    if (it == end) {
        dp[max_len++] = v[i];     // Extend LIS
    } else {
        *it = min(*it, v[i]);     // Replace with smaller value
    }
}
cout << max_len << endl;
```

✅ **Good practices:**
- Excellent comment explaining `lower_bound` usage
- Using `min(*it, v[i])` is smart (though lower_bound already gives optimal position)
- Track `max_len` explicitly instead of using `dp.size()`

💡 **Note:** The `min()` is actually redundant since `lower_bound` finds the first element ≥ v[i], so we can just assign `*it = v[i]`. Your solution is still correct!

**Key insight:** `dp[i]` stores the smallest tail element of all increasing subsequences of length i+1.

**Complexity:** O(n log n)

---

### 1633 - Dice Combinations
[Problem Link](https://cses.fi/problemset/task/1633)

**Problem:** Count ways to construct sum n by throwing a dice (1-6).

**Approach:** DP coin change variant

**Your Solution:**
```cpp
vector<long long> dp(1e6 + 1, 0);
long long mod = 1e9 + 7;

// Base cases (manually calculated)
dp[1] = 1;
dp[2] = 2;
dp[3] = 4;
dp[4] = 8;
dp[5] = 16;
dp[6] = 32;

for (int i = 7; i <= n; i++) {
    dp[i] += dp[i - 1];
    dp[i] %= mod;
    dp[i] += dp[i - 2];
    dp[i] %= mod;
    dp[i] += dp[i - 3];
    dp[i] %= mod;
    dp[i] += dp[i - 4];
    dp[i] %= mod;
    dp[i] += dp[i - 5];
    dp[i] %= mod;
    dp[i] += dp[i - 6];
    dp[i] %= mod;
}
```

✅ **Good practices:**
- MOD after each addition prevents overflow
- Pre-calculated base cases

💡 **Cleaner approach:**
```cpp
dp[0] = 1;  // Empty sum has 1 way
for (int i = 1; i <= n; i++) {
    for (int dice = 1; dice <= 6; dice++) {
        if (i - dice >= 0) {
            dp[i] = (dp[i] + dp[i - dice]) % mod;
        }
    }
}
```
This automatically handles base cases and is more maintainable.

**Complexity:** O(n)

---

### 1634 - Minimizing Coins
[Problem Link](https://cses.fi/problemset/task/1634)

**Problem:** Minimum coins needed to make sum x.

**Approach:** Classic coin change DP

**Your Solution:**
```cpp
vector<int> dp(x + 1, INT_MAX);
dp[0] = 0;

for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
        if (i - c[j] >= 0 && dp[i - c[j]] != INT_MAX) {
            dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
}

if (dp[x] == INT_MAX)
    cout << "-1" << endl;
else
    cout << dp[x] << endl;
```

✅ **Good practices:**
- Properly checks `dp[i - c[j]] != INT_MAX` to avoid overflow
- Handles impossible case with -1

**Key insight:** `dp[i]` = minimum coins to make sum i

**Complexity:** O(n × x)

---

### 1635 - Coin Combinations I
[Problem Link](https://cses.fi/problemset/task/1635)

**Problem:** Count ordered ways to make sum x using coins.

**Approach:** DP with order matters

```cpp
dp[0] = 1
for (int i = 1; i <= x; i++)
    for (int coin : coins)
        if (i >= coin)
            dp[i] += dp[i - coin]
```

**Complexity:** O(x × n)

---

### 1636 - Coin Combinations II
[Problem Link](https://cses.fi/problemset/task/1636)

**Problem:** Count unordered ways to make sum x using coins.

**Approach:** DP with order doesn't matter

```cpp
dp[0] = 1
for (int coin : coins)  // Note: iterate coins first
    for (int i = coin; i <= x; i++)
        dp[i] += dp[i - coin]
```

**Complexity:** O(x × n)

---

### 1637 - Removing Digits
[Problem Link](https://cses.fi/problemset/task/1637)

**Problem:** Minimum steps to reduce n to 0 by subtracting a digit.

**Approach:** DP with digit extraction

```cpp
dp[i] = minimum steps to reach 0 from i
dp[i] = 1 + min(dp[i - digit]) for all digits in i
```

**Complexity:** O(n × log n)

---

### 1638 - Grid Paths
[Problem Link](https://cses.fi/problemset/task/1638)

**Problem:** Count paths from top-left to bottom-right avoiding traps.

**Approach:** 2D DP

```cpp
dp[i][j] = paths to reach (i,j)
dp[i][j] = dp[i-1][j] + dp[i][j-1] if cell is free
dp[i][j] = 0 if trap
```

**Complexity:** O(n²)

---

### 1744 - Rectangle Cutting
[Problem Link](https://cses.fi/problemset/task/1744)

**Problem:** Minimum cuts to divide a×b rectangle into squares.

**Approach:** DP trying all cut positions

```cpp
dp[i][j] = minimum cuts for i×j rectangle
dp[i][j] = 0 if i == j (already square)
dp[i][j] = min over all horizontal/vertical cuts
```

**Complexity:** O(a × b × (a + b))

---

### 1745 - Money Sums
[Problem Link](https://cses.fi/problemset/task/1745)

**Problem:** Find all possible sums using subset of coins.

**Approach:** Subset sum DP

```cpp
dp[i][j] = can we make sum j using first i coins
dp[i][j] = dp[i-1][j] OR dp[i-1][j-coin[i]]
```

**Complexity:** O(n × sum)

---

### 1746 - Array Description
[Problem Link](https://cses.fi/problemset/task/1746)

**Problem:** Count ways to fill array where adjacent elements differ by at most 1.

**Approach:** DP with constraint checking

```cpp
dp[i][v] = ways to fill position i with value v
dp[i][v] = sum of dp[i-1][v-1], dp[i-1][v], dp[i-1][v+1]
```

**Complexity:** O(n × m)

---

## 2413 - Counting Towers

[Problem Link](https://cses.fi/problemset/task/2413)

**Problem:** Fill a 2×n grid with blocks. Count the number of ways modulo 10^9+7.

**Available blocks:**
- **1×1 block**: Single square (fills one column, one row)
- **Horizontal block**: 2×1 (spans both columns, one row)
- **Vertical block**: 1×2 (fills one column, two rows)

### DP States

At each row i, we track the configuration:
- **MERGED**: Row i has both columns connected (one horizontal block)
- **SPLIT**: Row i has both columns independent (two separate blocks)

### Solution Approach

```cpp
const int MERGED = 0;
const int SPLIT = 1;

dp[1][MERGED] = 1;  // One horizontal block
dp[1][SPLIT] = 1;   // Two 1×1 blocks

for (int i = 2; i <= n; i++) {
    // To get MERGED at row i:
    // 1. From MERGED: place horizontal (1) OR place 2 verticals side-by-side (1)
    // 2. From SPLIT: place horizontal across both (1)
    dp[i][MERGED] = (dp[i-1][MERGED] * 2 + dp[i-1][SPLIT]) % MOD;
    
    // To get SPLIT at row i:
    // 1. From SPLIT: place 2 new 1×1s (1) OR extend left (1) OR extend right (1) OR extend both (1)
    // 2. From MERGED: place 2 new 1×1s (1)
    dp[i][SPLIT] = (dp[i-1][SPLIT] * 4 + dp[i-1][MERGED]) % MOD;
}
```

### Example: n = 2

Let's enumerate all possible ways to fill a 2×2 tower:

#### Configuration 1: MERGED → MERGED
```
Row 2: ┌─────┐
       │████│  🟦 New horizontal block
       ├─────┤
Row 1: │[][]│  Horizontal block
       └─────┘
```

#### Configuration 2: MERGED → SPLIT
```
Row 2: ┌──┬──┐
       │██│██│  🟦 Two new 1×1 blocks
       ├──┴──┤
Row 1: │[][]│  Horizontal block
       └─────┘
```

#### Configuration 3: SPLIT → MERGED (using vertical blocks)
```
       ┌──┬──┐
       │██│██│  🟦 Two new vertical blocks (each 1×2)
       │  │  │
       │[]│[]│
       └──┴──┘
At row 2: appears MERGED (both columns at same level)
```

#### Configuration 4: SPLIT → MERGED (horizontal on top)
```
Row 2: ┌─────┐
       │████│  🟦 New horizontal block
       ├──┬──┤
Row 1: │[]│[]│  Two 1×1 blocks
       └──┴──┘
```

#### Configuration 5: SPLIT → SPLIT (extend left only)
```
Row 2: ┌──┬──┐
       │[]│██│  🟦 Right: new 1×1
       │  ├──┤
Row 1: │[]│[]│  Left: vertical spanning rows 1-2
       └──┴──┘

Explanation: Left column has ONE vertical block (1×2) spanning rows 1-2.
             Right column has TWO separate 1×1 blocks.
```

#### Configuration 6: SPLIT → SPLIT (extend right only)
```
Row 2: ┌──┬──┐
       │██│[]│  🟦 Left: new 1×1
       ├──┤  │
Row 1: │[]│[]│  Right: vertical spanning rows 1-2
       └──┴──┘

Explanation: Left column has TWO separate 1×1 blocks.
             Right column has ONE vertical block (1×2) spanning rows 1-2.
```

#### Configuration 7: SPLIT → SPLIT (extend both)
```
Row 2: ┌──┬──┐
       │██│██│  🟦 Both: new blocks extending each column upward
       │  ├  │
Row 1: │[]│[]│  Two 1×1 blocks
       └──┴──┘

Explanation: Row 1 has two separate 1×1 blocks.
             At row 2, we place a block on top of each, creating vertical extension.
             Result: Two vertical blocks, each 1×2, spanning rows 1-2.
```

#### Configuration 8: SPLIT → SPLIT (two new 1×1s)
```
Row 2: ┌──┬──┐
       │██│██│  🟦 Two new 1×1 blocks
       ├──┼──┤
Row 1: │[]│[]│  Two 1×1 blocks
       └──┴──┘
```

**Total for n=2: 8 ways** ✓

### Example: n = 3

**Base case (n=1):**
- `dp[1][MERGED] = 1`: One horizontal block
- `dp[1][SPLIT] = 1`: Two 1×1 blocks

**Calculate n=2:**
- `dp[2][MERGED] = 2 * 1 + 1 * 1 = 3`
- `dp[2][SPLIT] = 4 * 1 + 1 * 1 = 5`
- **Total: 8** ✓

**Calculate n=3:**
- `dp[3][MERGED] = 2 * 3 + 1 * 5 = 11`
- `dp[3][SPLIT] = 4 * 5 + 1 * 3 = 23`
- **Total: 34**

### Key Insights

1. **State tracking**: Track whether columns are merged (connected) or split (independent)
2. **Visual convention**: No divider = connected, divider = separate
3. **Transitions**: 
   - MERGED can come from MERGED (2 ways) or SPLIT (1 way)
   - SPLIT can come from SPLIT (4 ways) or MERGED (1 way)
4. **Complexity**: O(n) time, O(n) space

---

## 1633 - Dice Combinations

**Problem:** Count the number of ways to construct sum `n` by throwing a dice (1-6) one or more times.

**Approach:** Dynamic Programming

```cpp
dp[i] = number of ways to get sum i
dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
```

Base cases:
- `dp[1] = 1` (one way: throw 1)
- `dp[2] = 2` (1+1, 2)
- `dp[3] = 4` (1+1+1, 1+2, 2+1, 3)
- ... and so on

**Complexity:** O(n) time, O(n) space

---

## 1634 - Minimizing Coins

**Problem:** Given `n` coins and target sum `x`, find minimum number of coins needed to make sum `x`.

**Approach:** Classic coin change DP

```cpp
dp[i] = minimum coins needed to make sum i
dp[0] = 0
dp[i] = min(dp[i - coin] + 1) for all coins
```

If `dp[x] == INT_MAX`, return `-1` (impossible).

**Complexity:** O(n × x) time, O(x) space

---

## Graph Algorithms

### 1192 - Counting Rooms
[Problem Link](https://cses.fi/problemset/task/1192)

**Problem:** Given an n×m grid with floors (`.`) and walls (`#`), count the number of distinct rooms.

**Approach:** DFS for connected components

**Your Solution:**
```cpp
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<string> &v, int i, int j, int n, int m) {
    if (v[i][j] == '.') {
        v[i][j] = '#';  // Mark visited
        for (auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] == '.') {
                dfs(v, ni, nj, n, m);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                dfs(v, i, j, n, m);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
```

✅ **Good practices:**
- Clean direction array for 4-directional movement
- Marks cells as visited by changing '.' to '#'
- Proper boundary checking

**Key insight:** Each DFS call explores one complete room. Count how many DFS calls we make.

**Complexity:** O(n × m)

---

### 1193 - Labyrinth
[Problem Link](https://cses.fi/problemset/task/1193)

**Problem:** Find shortest path from A to B in a grid maze.

**Approach:** BFS

```cpp
// Use BFS queue with (x, y, path)
// Track visited cells
// Return path when B is reached
```

**Complexity:** O(n × m)

---

### 1666 - Building Teams
[Problem Link](https://cses.fi/problemset/task/1666)

**Problem:** Divide students into two teams such that no two friends are on same team (bipartite graph check).

**Approach:** DFS to find connected components and build roads between them

**Your Solution:**
```cpp
void dfs(int s, vector<vector<int>> &v, vector<bool> &vis) {
    vis[s] = true;
    for (int i = 0; i < v[s].size(); i++) {
        if (!vis[v[s][i]]) 
            dfs(v[s][i], v, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    vector<bool> vis(n + 1, false);
    vector<int> rep;  // Representatives of each component
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, v, vis);
            rep.push_back(i);
        }
    }
    
    cout << rep.size() - 1 << endl;  // Number of roads needed
    for (int i = 1; i < rep.size(); i++) {
        cout << rep[i - 1] << " " << rep[i] << endl;
    }
}
```

⚠️ **Wait!** This solution is for a **different problem** (Building Roads - 1666 on old numbering). This finds connected components and connects them!

**For the actual "Building Teams" (bipartite graph coloring), you'd need:**
```cpp
vector<int> color(n + 1, -1);
bool is_bipartite = true;

void dfs(int node, int c) {
    color[node] = c;
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            dfs(neighbor, 1 - c);
        } else if (color[neighbor] == c) {
            is_bipartite = false;
        }
    }
}
```

**Complexity:** O(V + E)

---

## Mathematics

### 1617 - Bit Strings
[Problem Link](https://cses.fi/problemset/task/1617)

**Problem:** Count number of distinct bit strings of length n.

**Approach:** Simple power calculation

**Your Solution:**
```cpp
int n;
cin >> n;
long long ans = 1;
for (int i = 1; i <= n; i++) {
    ans *= 2;
    if (ans >= 1000000007) 
        ans %= 1000000007;
}
cout << ans << endl;
```

✅ **Simple and works!**

⚠️ **Better approach:** Use binary exponentiation for O(log n):
```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
cout << power(2, n, 1000000007) << endl;
```

**Why better:** Your O(n) solution works fine for n ≤ 10^6, but binary exponentiation is O(log n) and handles any n up to 10^9!

**Complexity:** Your solution: O(n), Binary exp: O(log n)

---

### 1618 - Trailing Zeros
[Problem Link](https://cses.fi/problemset/task/1618)

**Problem:** Count trailing zeros in n!

**Approach:** Count factors of 5

**Your Solution:**
```cpp
int n;
cin >> n;
int ans = 0;
int d = 5;
while (n / d >= 1) {
    ans += (n / d);
    d *= 5;
}
cout << ans << endl;
```

✅ **Correct approach!**

⚠️ **Potential overflow issue:** When `d *= 5` repeatedly, `d` can overflow int!

💡 **Safer approach:**
```cpp
int ans = 0;
for (int i = 5; n / i >= 1; i *= 5) {
    ans += (n / i);
}
// OR better:
while (n >= 5) {
    n /= 5;
    ans += n;
}
```

**Key insight:** Count n/5 (multiples of 5) + n/25 (multiples of 25, contribute extra 5) + n/125 + ...

**Complexity:** O(log n)

---

### 1619 - Restaurant Customers
[Problem Link](https://cses.fi/problemset/task/1619)

**Problem:** Maximum number of customers in restaurant simultaneously.

**Approach:** Sweep line algorithm
- Create events: +1 at arrival, -1 at departure
- Sort all events
- Track running count and max

```cpp
for (arrival, departure) {
    events.push({arrival, +1});
    events.push({departure, -1});
}
sort(events);
int current = 0, maxCustomers = 0;
for (event : events) {
    current += event.type;
    maxCustomers = max(maxCustomers, current);
}
```

**Complexity:** O(n log n)

---

### 1623 - Apple Division
[Problem Link](https://cses.fi/problemset/task/1623)

**Problem:** Divide apples into two groups to minimize weight difference.

**Approach:** Bitmask enumeration (or DP for larger n)
- Try all 2^n subsets
- Calculate sum1 and sum2 = totalSum - sum1
- Track minimum |sum1 - sum2|

```cpp
long long minDiff = LLONG_MAX;
for (int mask = 0; mask < (1 << n); mask++) {
    long long sum1 = 0;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            sum1 += weights[i];
    long long sum2 = totalSum - sum1;
    minDiff = min(minDiff, abs(sum1 - sum2));
}
```

**Complexity:** O(2^n × n) - works for n ≤ 20

---

### 1754 - Coin Piles
[Problem Link](https://cses.fi/problemset/task/1754)

**Problem:** Can we empty two piles by repeatedly removing 1 from one and 2 from the other?

**Approach:** Mathematical condition
- Each operation removes 3 coins total
- So (a + b) must be divisible by 3
- Also, neither pile can be more than twice the other
- Conditions: (a+b) % 3 == 0 && a <= 2*b && b <= 2*a

**Complexity:** O(1) per query

---

### 3421 - XOR Pyramid
[Problem Link](https://cses.fi/problemset/task/3421)

**Problem:** Build pyramid where each level is XOR of adjacent elements below, find top.

**Approach:** Pattern recognition
- Observe that XOR has special properties
- Each bottom element contributes based on binomial coefficient pattern
- Can use combinatorics or direct simulation

**Complexity:** O(n) simulation or O(n log n) with combinatorics

---

## Range Queries

### 1643 - Maximum Subarray Sum
[Problem Link](https://cses.fi/problemset/task/1643)

**Problem:** Find maximum sum of a contiguous subarray.

**Approach:** Kadane's Algorithm

**Your Solution:**
```cpp
vector<long long> v(n);
for (int i = 0; i < n; i++) {
    cin >> v[i];
}

long long ans = v[0];
for (int i = 1; i < n; i++) {
    v[i] = max(v[i], v[i - 1] + v[i]);  // Extend or start fresh
    ans = max(ans, v[i]);
}
cout << ans << endl;
```

✅ **Good practices:**
- Space-efficient: reuses input array for DP
- Classic Kadane's algorithm implementation

💡 **What's happening:**
- `v[i]` stores max sum ending at position i
- At each position: either start new subarray (v[i]) or extend previous (v[i-1] + v[i])
- Track global maximum

**Key Insight:** At each position, decide whether to extend current subarray or start new one.

**Complexity:** O(n) time, O(1) space (reusing input array)

---

## Additional Problems

### 3359 - Download Speed
[Problem Link](https://cses.fi/problemset/task/3359)

**Problem:** Find maximum flow in a network from node 1 to node n.

**Approach:** Maximum flow algorithms
- Ford-Fulkerson with BFS (Edmonds-Karp)
- Dinic's algorithm
- Push-relabel

```cpp
// Typical Edmonds-Karp implementation
while (BFS finds augmenting path) {
    find bottleneck capacity
    update residual graph
    add to total flow
}
```

**Complexity:** O(V × E²) for Edmonds-Karp, O(V² × E) for Dinic's

---

## More Problems

*This is a living document. The above explanations cover the main approaches for 43 CSES problems solved in this repository.*

### Problem Patterns Summary

**DP Patterns:**
- Coin change: 1633, 1634, 1635, 1636, 1637
- Grid DP: 1638, 1744
- Subset DP: 1092, 1093, 1745
- Interval DP: 1097
- Constrained sequence: 1746
- State machine: 2413 ⭐

**Graph Patterns:**
- DFS/BFS: 1192, 1193
- Bipartite checking: 1666
- Max flow: 3359

**Greedy Patterns:**
- Two pointers: 1084, 1090, 1640
- Interval scheduling: 1629
- Sorting + greedy: 2183, 2216

**Math Patterns:**
- Combinatorics: 1617
- Number theory: 1618, 1754
- Sweep line: 1619

**Data Structures:**
- Multiset/map: 1091, 1141
- Binary search: 1145

### Contributing

To add explanation for a problem:
1. Add problem number to TOC in correct category
2. Create section with problem number as heading
3. Include: Problem link, statement, approach, key insights, complexity
4. Add code snippets and ASCII diagrams where helpful (see 2413 as example)

### Legend

- ⭐ = Detailed explanation with visualizations
- 🔥 = Tricky problem with common pitfalls
- 💡 = Useful technique/pattern to remember
