package leetcode.solved.SlidingWindowMaximum;

// Problem: 239. SlidingWindowMaximum
// Link: https://leetcode.com/problems/sliding-window-maximum/

import java.util.*;

public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            while (!dq.isEmpty() && i - dq.peekFirst() + 1 > k) {
                dq.removeFirst();
            }
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) {
                dq.removeLast();
            }
            dq.offerLast(i);
            if (i + 1 >= k) {
                ans[idx] = nums[dq.peekFirst()];
                idx++;
            }
        }
        return ans;
    }
}
