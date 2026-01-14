package leetcode;

// Problem: 862. ShortestSubarrayWithSumAtLeastK
// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

import java.util.*;

public class Main {
    private static int passedTests = 0;
    private static int totalTests = 0;

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: nums = [1], k = 1
        int result1 = solution.shortestSubarray(new int[] {1}, 1);
        runTest(1, String.valueOf(result1), "1");

        // Test case 2: nums = [1,2], k = 4
        int result2 = solution.shortestSubarray(new int[] {1, 2}, 4);
        runTest(2, String.valueOf(result2), "-1");

        // Test case 3: nums = [2,-1,2], k = 3
        int result3 = solution.shortestSubarray(new int[] {2, -1, 2}, 3);
        runTest(3, String.valueOf(result3), "3");

        // Print summary
        System.out.println("\n" + "=".repeat(50));
        if (passedTests == totalTests) {
            System.out.println("✅ All tests passed! (" + passedTests + "/" + totalTests + ")");
            System.exit(0);
        } else {
            System.out.println(
                    "❌ Some tests failed! (" + passedTests + "/" + totalTests + " passed)");
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
