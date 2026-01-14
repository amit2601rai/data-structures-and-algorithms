package cses; // Problem: Static Range Minimum Queries

// Link: https://cses.fi/problemset/task/1647

import java.io.*;
import java.util.*;

public class Solution {

    static final int MOD = (int) 1e9 + 7;
    static final int INF = (int) 2e9;
    static final long LINF = (long) 1e18;
    static final int[] DX = {-1, 0, 1, 0}, DY = {0, 1, 0, -1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");

    // Helper classes
    static class Pair implements Comparable<Pair> {

        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair p) {
            return x != p.x ? x - p.x : y - p.y;
        }
    }

    // Utilities
    static String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static int[] readInts(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        solve();
        out.close();
    }

    static void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        int[] arr = readInts(n);

        // Calculate log2(n) - how many powers of 2 we need
        // Example: n=5 → log=3 (need 2^0, 2^1, 2^2 to cover all ranges)
        int log = 32 - Integer.numberOfLeadingZeros(n);

        // st[j][i] = minimum in range [i, i + 2^j - 1]
        // st[0][i] = arr[i] (single element)
        // st[1][i] = min(arr[i], arr[i+1]) (pairs)
        // st[2][i] = min of 4 elements starting at i, etc.
        int[][] st = new int[log][n];

        // Initialize st[0] with original array (ranges of length 1)
        System.arraycopy(arr, 0, st[0], 0, n);

        // Build sparse table using DP
        // For each power of 2 (j), compute min for all valid positions (i)
        for (int j = 1; j < log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                // Split range of length 2^j into two halves of length 2^(j-1)
                // st[j][i] = min(left half, right half)
                st[j][i] = Math.min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }

        // Answer queries in O(1) each
        for (int i = 0; i < q; i++) {
            int a = nextInt() - 1; // convert to 0-indexed
            int b = nextInt() - 1;

            // Find largest power k such that 2^k <= length
            int length = b - a + 1;
            int k = 31 - Integer.numberOfLeadingZeros(length);

            // Cover range [a, b] with 2 overlapping ranges of length 2^k
            // Range 1: starts at a
            // Range 2: ends at b
            // They overlap but together cover entire [a, b]
            int min = Math.min(st[k][a], st[k][b - (1 << k) + 1]);
            out.println(min);
        }
    }
}
