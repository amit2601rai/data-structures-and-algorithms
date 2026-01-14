#!/bin/bash

# Script to create a new LeetCode Solution.java with template
# Usage: ./leetcode-new.sh [PROBLEM_NUMBER] [PROBLEM_NAME]
# Example: ./leetcode-new.sh 1 TwoSum

LEETCODE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SOLUTION_FILE="$LEETCODE_DIR/Solution.java"
MAIN_FILE="$LEETCODE_DIR/Main.java"

PROBLEM_NUM="$1"
PROBLEM_NAME="$2"

# Check if Solution.java already exists
if [ -f "$SOLUTION_FILE" ]; then
    echo "⚠️  Warning: Solution.java already exists!"
    echo "If you have unsaved work, please use leetcode-archive.sh first to save it."
    read -p "Do you want to overwrite it? (y/N): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo "Aborted. No changes made."
        exit 1
    fi
fi

# Create Solution.java with package declaration
cat > "$SOLUTION_FILE" << 'EOF'
package leetcode;

import java.util.*;

public class Solution {
  // Paste the exact method signature from LeetCode here

}
EOF

# Create Main.java with package declaration and test validation
cat > "$MAIN_FILE" << 'EOF'
package leetcode;

public class Main {
  private static int passedTests = 0;
  private static int totalTests = 0;

  public static void main(String[] args) {
    Solution solution = new Solution();

    // Add test cases from LeetCode examples here
    // Use runTest(testNum, actual, expected) to validate each test
    //
    // Example:
    // int[] result = solution.twoSum(new int[]{2,7,11,15}, 9);
    // runTest(1, Arrays.toString(result), "[0, 1]");

    // Print summary
    System.out.println("\n" + "=".repeat(50));
    if (passedTests == totalTests) {
      System.out.println("✅ All tests passed! (" + passedTests + "/" + totalTests + ")");
      System.exit(0);
    } else {
      System.out.println("❌ Some tests failed! (" + passedTests + "/" + totalTests + " passed)");
      System.exit(1);
    }
  }

  static void runTest(int testNum, String actual, String expected) {
    totalTests++;
    if (actual.equals(expected)) {
      passedTests++;
      System.out.println("✅ Test " + testNum + " passed: " + actual);
    } else {
      System.out.println("❌ Test " + testNum + " failed:");
      System.out.println("   Expected: " + expected);
      System.out.println("   Got:      " + actual);
    }
  }
}
EOF

# Add problem info as comments if provided
if [ -n "$PROBLEM_NUM" ] && [ -n "$PROBLEM_NAME" ]; then
    LEETCODE_URL="https://leetcode.com/problems/$(echo $PROBLEM_NAME | tr '[:upper:]' '[:lower:]' | sed 's/\([A-Z]\)/-\1/g' | sed 's/^-//')/"

    # Add to Solution.java (after package line)
    TEMP_FILE="${SOLUTION_FILE}.tmp"
    {
        head -n 1 "$SOLUTION_FILE"
        echo ""
        echo "// Problem: $PROBLEM_NUM. $PROBLEM_NAME"
        echo "// Link: $LEETCODE_URL"
        tail -n +2 "$SOLUTION_FILE"
    } > "$TEMP_FILE"
    mv "$TEMP_FILE" "$SOLUTION_FILE"

    # Add to Main.java (after package line)
    TEMP_FILE="${MAIN_FILE}.tmp"
    {
        head -n 1 "$MAIN_FILE"
        echo ""
        echo "// Problem: $PROBLEM_NUM. $PROBLEM_NAME"
        echo "// Link: $LEETCODE_URL"
        tail -n +2 "$MAIN_FILE"
    } > "$TEMP_FILE"
    mv "$TEMP_FILE" "$MAIN_FILE"

    echo "1/Success: Created Solution.java and Main.java"
    echo "📋 Problem: $PROBLEM_NUM. $PROBLEM_NAME"
    echo "🔗 Link: $LEETCODE_URL"
else
    echo "1/Success: Created Solution.java and Main.java"
fi

echo "📝 Files: Solution.java, Main.java (+ create supporting classes if needed)"
echo ""
echo "Next steps:"
echo "  1. Copy exact method signature from LeetCode to Solution.java"
echo "  2. Create supporting classes if needed (e.g., ListNode.java, TreeNode.java)"
echo "  3. Implement the solution in Solution.java"
echo "  4. Add test cases in Main.java"
echo "  5. Test locally: cd scripts && ./leetcode-run.sh"
echo "  6. Copy Solution class (without package) to LeetCode and submit"
echo "  7. After acceptance: cd scripts && ./leetcode-archive.sh <ProblemName>"

