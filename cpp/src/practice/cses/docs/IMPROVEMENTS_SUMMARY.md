# CSES Solutions - Improvements & Best Practices

This document highlights potential improvements and best practices based on your current solutions.

## 🟢 Excellent Practices Found in Your Code

### 1. **1084 - Apartments**: Range Storage Pattern
```cpp
ds[i] = make_pair(x - k, x + k);  // Smart: store acceptable range
```
✅ Storing the acceptable range upfront makes the matching logic cleaner

### 2. **1090 - Ferris Wheel**: Clean Greedy Logic
```cpp
while (p <= q) {
    if (v[p] + v[q] <= x)
        p++, q--;
    else
        q--;
    ans++;  // Count gondola regardless
}
```
✅ Clear that every iteration uses one gondola - elegant!

### 3. **1145 - LIS**: Excellent Comments
```cpp
// lower_bound : gives len bucket above
```
✅ Your inline comments explain the algorithm clearly

### 4. **1629 - Movie Festival**: Sorting Trick
```cpp
intervals.push_back(make_pair(y, x));  // (end, start)
sort(intervals.begin(), intervals.end());
```
✅ Clever! By storing (end, start), you get automatic sorting by end time

### 5. **1141 - Playlist**: Proper Start Pointer Handling
```cpp
s = max(s, lastIdx[v[idx]] + 1);  // Never move backward
```
✅ Critical detail: using max() prevents start from going backward

---

## 🟡 Good Solutions with Suggested Improvements

### 1. **1091 - Concert Tickets**: Can Be Simplified

**Your approach (correct but complex):**
```cpp
auto it = ms.lower_bound(val);
if (it != ms.end()) {
    if ((*it) == val) {
        // handle exact match
    } else {
        if (it != ms.begin()) it--;
        // handle smaller ticket
    }
} else {
    it--;
    // handle end case
}
```

**Simpler alternative:**
```cpp
auto it = ms.upper_bound(val);  // First > val
if (it == ms.begin()) {
    cout << "-1\n";
} else {
    --it;  // Largest ≤ val
    cout << *it << "\n";
    ms.erase(it);
}
```

**Why better:** Only 3 lines of logic instead of nested conditions. `upper_bound` handles all cases uniformly.

---

### 2. **1617 - Bit Strings**: Iterative vs Binary Exponentiation

**Your approach (works for n ≤ 10^6):**
```cpp
long long ans = 1;
for (int i = 1; i <= n; i++) {
    ans *= 2;
    if (ans >= 1000000007) 
        ans %= 1000000007;
}
```

**Better approach (works for n ≤ 10^9):**
```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
cout << power(2, n, 1000000007) << endl;
```

**Benefit:**
- Your solution: O(n) - fast enough for this problem
- Binary exp: O(log n) - handles much larger n values
- Industry standard for modular exponentiation

---

### 3. **1618 - Trailing Zeros**: Potential Overflow

**Your approach:**
```cpp
int d = 5;
while (n / d >= 1) {
    ans += (n / d);
    d *= 5;  // ⚠️ Can overflow!
}
```

**Problem:** When `d *= 5` repeatedly, `d` overflows after ~13 iterations (5^13 > INT_MAX)

**Safer approach:**
```cpp
while (n >= 5) {
    n /= 5;
    ans += n;
}
```

**Why better:** No multiplication means no overflow risk. Divides n instead of multiplying d.

---

### 4. **1633 - Dice Combinations**: Manual Base Cases

**Your approach:**
```cpp
dp[1] = 1;
dp[2] = 2;
dp[3] = 4;
dp[4] = 8;
dp[5] = 16;
dp[6] = 32;
for (int i = 7; i <= n; i++) {
    // sum previous 6 states
}
```

**Cleaner approach:**
```cpp
dp[0] = 1;  // Base: empty sum
for (int i = 1; i <= n; i++) {
    for (int dice = 1; dice <= 6; dice++) {
        if (i >= dice) {
            dp[i] = (dp[i] + dp[i - dice]) % mod;
        }
    }
}
```

**Benefits:**
- More maintainable (what if problem asks for 1-10 instead of 1-6?)
- Base cases handled automatically
- Same time complexity

---

### 5. **1145 - LIS**: Minor Optimization

**Your approach:**
```cpp
*it = min(*it, v[i]);  // Replace with smaller
```

**Note:** This `min()` is actually **redundant**! Since `lower_bound` finds the first element ≥ v[i], we know `*it >= v[i]`. So we can just assign:

```cpp
*it = v[i];  // This is sufficient
```

Your solution is still correct, just doing an unnecessary comparison.

---

## 🔵 Pattern Recognition

### Two Pointers Mastery
You've used this pattern correctly in multiple problems:
- ✅ 1084 - Apartments (matching with tolerance)
- ✅ 1090 - Ferris Wheel (greedy pairing)
- ✅ 1640 - Sum of Two Values (classic two-sum)

**Consistent pattern:** Sort first, then use two pointers from ends

### Sliding Window Understanding
- ✅ 1141 - Playlist: Correctly maintains window invariant
- Key insight in your code: `s = max(s, lastIdx[v[idx]] + 1)`

### DP State Management
- ✅ 2413 - Counting Towers: Excellent state definitions
- ✅ 1633, 1634: Proper handling of base cases
- ✅ 1643 - Kadane's: Space-efficient (reusing input array)

---

## 📊 Complexity Analysis Summary

| Problem | Your Solution | Time | Space | Optimal? |
|---------|---------------|------|-------|----------|
| 1617 | Iterative power | O(n) | O(1) | ✅ For constraints |
| 1618 | Factorial zeros | O(log n) | O(1) | ✅ Perfect |
| 1091 | Concert tickets | O(n log n) | O(n) | ✅ Correct |
| 1141 | Playlist | O(n) | O(n) | ✅ Optimal |
| 1145 | LIS | O(n log n) | O(n) | ✅ Optimal |
| 1643 | Max subarray | O(n) | O(1)* | ✅ Perfect |

*Reusing input array

---

## 🎯 General Recommendations

### 1. **Overflow Safety**
When multiplying repeatedly (like 1618), prefer division-based approaches to avoid overflow.

### 2. **Binary Exponentiation**
Learn the template for fast modular exponentiation - it's used in many competitive programming problems.

### 3. **Simplify Conditionals**
When using binary search functions (lower_bound/upper_bound), choose the variant that minimizes conditional logic.

### 4. **Modular Arithmetic**
Your MOD handling is excellent - you consistently apply it after each operation.

### 5. **Code Reusability**
Consider extracting common patterns (like binary search on multiset) into helper functions.

---

## 💡 Advanced Techniques to Learn

Based on your current level, these would be good next steps:

1. **Binary Exponentiation** (modular exponentiation in O(log n))
2. **Binary Lifting** (for tree queries)
3. **Segment Trees** (range queries)
4. **Lazy Propagation** (range updates)
5. **SCC/Bridges** (advanced graph algorithms)

---

## ✨ Overall Assessment

Your solutions demonstrate:
- ✅ Strong grasp of fundamental algorithms
- ✅ Good understanding of time/space complexity
- ✅ Clean, readable code structure
- ✅ Proper handling of edge cases
- ✅ Efficient use of STL containers

**Areas for growth:**
- Minor optimizations (using better STL functions)
- Overflow-safe implementations
- Template-based solutions for common patterns

**Keep up the excellent work!** 🚀
