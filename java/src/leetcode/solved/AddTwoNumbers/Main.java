package leetcode.solved.AddTwoNumbers;

// Problem: 2. AddTwoNumbers
// Link: https://leetcode.com/problems/addtwonumbers/

public class Main {
    private static int passedTests = 0;
    private static int totalTests = 0;

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: l1 = [2,4,3], l2 = [5,6,4]
        ListNode l1 = createList(new int[] {2, 4, 3});
        ListNode l2 = createList(new int[] {5, 6, 4});
        ListNode result1 = solution.addTwoNumbers(l1, l2);
        String expected1 = "[7,0,8]";
        runTest(1, listToString(result1), expected1);

        // Test case 2: l1 = [0], l2 = [0]
        ListNode l3 = createList(new int[] {0});
        ListNode l4 = createList(new int[] {0});
        ListNode result2 = solution.addTwoNumbers(l3, l4);
        String expected2 = "[0]";
        runTest(2, listToString(result2), expected2);

        // Test case 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
        ListNode l5 = createList(new int[] {9, 9, 9, 9, 9, 9, 9});
        ListNode l6 = createList(new int[] {9, 9, 9, 9});
        ListNode result3 = solution.addTwoNumbers(l5, l6);
        String expected3 = "[8,9,9,9,0,0,0,1]";
        runTest(3, listToString(result3), expected3);

        // Summary
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

    static ListNode createList(int[] values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

    static String listToString(ListNode head) {
        if (head == null) return "null";
        StringBuilder sb = new StringBuilder("[");
        while (head != null) {
            sb.append(head.val);
            if (head.next != null) sb.append(",");
            head = head.next;
        }
        sb.append("]");
        return sb.toString();
    }
}
