package leetcode.solved.SlidingWindowMaximum;

// Problem: 239. SlidingWindowMaximum
// Link: https://leetcode.com/problems/sliding-window-maximum/

import java.util.*;

public class Main {
    private static int passedTests = 0;
    private static int totalTests = 0;

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: nums = [1,3,-1,-3,5,3,6,7], k = 3
        int[] nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
        int[] result1 = solution.maxSlidingWindow(nums1, 3);
        runTest(1, Arrays.toString(result1), "[3, 3, 5, 5, 6, 7]");

        // Test case 2: nums = [1], k = 1
        int[] nums2 = {1};
        int[] result2 = solution.maxSlidingWindow(nums2, 1);
        runTest(2, Arrays.toString(result2), "[1]");

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
