# Competitive Programming - Java Solutions

Automated workflows for solving CSES and LeetCode problems with Java and CP templates.

## 📂 Directory Structure

```
java/
├── README.md                    # This file
├── out/                         # Compiled classes (gitignored)
└── src/
    ├── cses/                    # CSES solutions
    │   ├── Solution.java        # Active solution (no package)
    │   ├── input                # Sample input (auto-fetched)
    │   ├── output               # Expected output (auto-fetched)
    │   ├── scripts/
    │   │   ├── cses-new.sh      # Create new problem
    │   │   ├── cses-run.sh      # Test solution
    │   │   └── cses-archive.sh  # Archive solved
    │   └── solved/              # Archived solutions
    │
    └── leetcode/                # LeetCode solutions
        ├── Solution.java        # Active solution (package leetcode)
        ├── Main.java            # Test runner with validation
        ├── scripts/
        │   ├── leetcode-new.sh     # Create new problem
        │   ├── leetcode-run.sh     # Test solution
        │   └── leetcode-archive.sh # Archive solved
        └── solved/              # Archived solutions (by folder)
```

---

## 🚀 Quick Start

### CSES Problems

```bash
cd src/cses/scripts

# 1. Fetch problem and create template (auto-extracts input/output)
./cses-new.sh https://cses.fi/problemset/task/1131/

# 2. Implement solution in ../Solution.java

# 3. Test
./cses-run.sh

# 4. Submit to CSES

# 5. Archive
./cses-archive.sh TreeDiameter
```

### LeetCode Problems

```bash
cd src/leetcode/scripts

# 1. Create problem template
./leetcode-new.sh 862 ShortestSubarrayWithSumAtLeastK

# 2. Add method signature to Solution.java
# 3. Add test cases to Main.java
# 4. Implement solution

# 5. Test (validates results with exit codes)
./leetcode-run.sh

# 6. Submit to LeetCode (copy Solution class without package)

# 7. Archive (creates folder with all files)
./leetcode-archive.sh ShortestSubarrayWithSumAtLeastK
```

---

## 📋 CSES Workflow

### Features

✅ **Auto-fetch** problem details from CSES URL  
✅ **Extract** sample input/output automatically  
✅ **Fast I/O** template with BufferedReader/PrintWriter  
✅ **Output comparison** - shows expected vs actual  
✅ **No package** for active solutions (CSES requirement)  
✅ **Package** added when archived: `cses.solved`  

### Scripts

#### `cses-new.sh [URL]`
- Fetches problem name and link
- Extracts sample input/output from CSES page
- Creates Solution.java with CP template

**Result format:**
- `1/Success: <message>` - Operation succeeded
- `2/Failure: <details>` - Operation failed

#### `cses-run.sh [input_file]`
- Compiles to `../../out/` (keeps src/ clean)
- Auto-detects `input` file
- Compares output with `output` file
- Shows **Successful** (green) or **Failed** (red) with details

#### `cses-archive.sh <ProblemName>`
- Adds `package cses.solved;`
- Renames class to ProblemName
- Moves to `solved/` directory

### Example

```bash
./cses-new.sh https://cses.fi/problemset/task/1131/
# Output:
#   1/Success: Created new Solution.java
#   📋 Problem: Tree Diameter
#   🔗 Link: https://cses.fi/problemset/task/1131/
#   1/Success: Saved sample input to input
#   1/Success: Saved expected output to output

# Implement solution...

./cses-run.sh
# Output:
#   Successful: Output matches expected result ✅

./cses-archive.sh TreeDiameter
# Output:
#   1/Success: Archived solution as TreeDiameter
```

---

## 💻 LeetCode Workflow

### Features

✅ **Dual structure** - Solution.java + Main.java with test validation  
✅ **Package management** - `leetcode` for active, `leetcode.solved.ProblemName` for archived  
✅ **Test validation** - Compares actual vs expected, shows pass/fail  
✅ **Exit codes** - 0 for all pass, 1 for failures  
✅ **Folder archiving** - All files (Solution, Main, supporting classes) in one folder  
✅ **Supporting classes** - ListNode, TreeNode, etc. with proper packages  

### Scripts

#### `leetcode-new.sh [PROBLEM_NUMBER] [PROBLEM_NAME]`
- Creates Solution.java and Main.java with packages
- Adds problem info in comments
- Main.java includes test validation framework

#### `leetcode-run.sh`
- Compiles all `.java` files in leetcode directory
- Runs `leetcode.Main` class
- Validates test results with exit codes
- Shows **Successful** (green) or **Failed** (red) with details

#### `leetcode-archive.sh <ProblemName>`
- Creates folder: `solved/ProblemName/`
- Moves ALL `.java` files (Solution, Main, ListNode, etc.)
- Updates packages to `leetcode.solved.ProblemName`

### File Structure

**Solution.java** - Clean LeetCode solution with exact method signature:
```java
package leetcode;

public class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    // Implementation
  }
}
```

**Main.java** - Test runner with validation:
```java
package leetcode;

public class Main {
  private static int passedTests = 0;
  private static int totalTests = 0;
  
  public static void main(String[] args) {
    Solution solution = new Solution();
    
    // Test case 1
    int[] result = solution.maxSlidingWindow(new int[]{1,3,-1,-3,5,3,6,7}, 3);
    runTest(1, Arrays.toString(result), "[3, 3, 5, 5, 6, 7]");
    
    // Summary with exit codes
    if (passedTests == totalTests) {
      System.out.println("✅ All tests passed!");
      System.exit(0);
    } else {
      System.out.println("❌ Some tests failed!");
      System.exit(1);
    }
  }
  
  static void runTest(int testNum, String actual, String expected) {
    // Validation logic
  }
}
```

**Supporting Classes** (e.g., ListNode.java):
```java
package leetcode;

public class ListNode {
  public int val;
  public ListNode next;
  public ListNode() {}
  public ListNode(int val) { this.val = val; }
}
```

### Example

```bash
./leetcode-new.sh 239 SlidingWindowMaximum
# Output:
#   1/Success: Created Solution.java and Main.java
#   📋 Problem: 239. SlidingWindowMaximum

# Add method signature to Solution.java
# Add test cases to Main.java
# Implement solution...

./leetcode-run.sh
# Output:
#   ✅ Test 1 passed: [3, 3, 5, 5, 6, 7]
#   ✅ Test 2 passed: [1]
#   ==================================================
#   ✅ All tests passed! (2/2)
#   Successful: All tests passed!

./leetcode-archive.sh SlidingWindowMaximum
# Output:
#   1/Success: Archived solution in folder SlidingWindowMaximum
#   📁 Location: solved/SlidingWindowMaximum/
#   📝 Files archived:
#     - Solution.java
#     - Main.java
```

---

## 🛠️ CP Template Includes

Both CSES and LeetCode templates include:

- **Fast I/O**: BufferedReader + PrintWriter
- **Input utilities**: 
  - `next()` - Read next token
  - `nextInt()` - Read integer
  - `nextLong()` - Read long
  - `readInts(n)` - Read array of n integers
- **Math utilities**: 
  - `gcd(a, b)` - Greatest common divisor
- **Helper classes**: 
  - `Pair` - Comparable pair class
- **Constants**: 
  - `MOD = 1e9 + 7`
  - `INF = 2e9`
  - `LINF = 1e18`
  - `DX, DY` - Direction arrays

---

## 📊 Comparison

| Feature | CSES | LeetCode |
|---------|------|----------|
| **Auto-fetch** | ✅ Yes (from URL) | ❌ Manual |
| **Test files** | ✅ Auto-extracted | 📝 Manual in Main.java |
| **Method signature** | Full program | Single method |
| **Package (active)** | ❌ No | ✅ `leetcode` |
| **Package (archived)** | ✅ `cses.solved` | ✅ `leetcode.solved.ProblemName` |
| **Archive structure** | Single file | Folder with all files |
| **Test validation** | Output comparison | Exit codes with pass/fail |
| **Compile to** | `../../out/` | `../../out/` |
| **Colored output** | ✅ Yes | ✅ Yes |

---

## 📝 Notes

### CSES
- **No package** in Solution.java (CSES requirement)
- **"Missing package statement"** IDE warning is expected and correct
- Files named `input` and `output` (no extensions)
- Success format: `1/Success`, Failure format: `2/Failure: details`

### LeetCode
- **Package declaration** required: `package leetcode;`
- **Copy without package** when submitting to LeetCode
- **Supporting classes** must have same package
- **Test validation** with exit codes (0 = pass, 1 = fail)
- **Folder-based archiving** keeps all related files together

---

## 🎯 Making Scripts Executable

```bash
# CSES
cd src/cses/scripts
chmod +x *.sh

# LeetCode
cd src/leetcode/scripts
chmod +x *.sh
```

---

## 💡 Tips

1. **CSES**: Always use the full CSES URL for auto-fetching
2. **LeetCode**: Create supporting classes (ListNode, TreeNode) with `package leetcode;`
3. **Testing**: Run tests before submitting to catch errors early
4. **Archiving**: Archive immediately after acceptance to keep workspace clean
5. **Compilation**: All classes compile to `out/` directory (gitignored)

---

## 🎓 Workflow Summary

### CSES (3 steps)
```bash
./cses-new.sh <URL>      # Fetch and create
# Implement...
./cses-run.sh            # Test
./cses-archive.sh <Name> # Archive
```

### LeetCode (4 steps)
```bash
./leetcode-new.sh <NUM> <Name>  # Create templates
# Implement in Solution.java and Main.java...
./leetcode-run.sh               # Test with validation
./leetcode-archive.sh <Name>    # Archive to folder
```

---

**Happy Coding! 🚀**

