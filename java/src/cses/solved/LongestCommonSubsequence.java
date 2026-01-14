package cses.solved;

// Problem: Longest Common Subsequence
// Link: https://cses.fi/problemset/task/3403

import java.io.*;
import java.util.*;

public class LongestCommonSubsequence {
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
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
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
        for (int i = 0; i < n; i++) a[i] = nextInt();
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
        int m = nextInt();

        int[] x = readInts(n);
        int[] y = readInts(m);

        // DP table with 1-based indexing for cleaner logic
        int[][] dp = new int[n + 1][m + 1];
        // Parent pointers: 0=diagonal, 1=up, 2=left
        int[][] parent = new int[n + 1][m + 1];

        // Build DP table with parent tracking
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    parent[i][j] = 0; // came from diagonal (match)
                } else if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    parent[i][j] = 1; // came from up
                } else {
                    dp[i][j] = dp[i][j - 1];
                    parent[i][j] = 2; // came from left
                }
            }
        }

        // Print length
        out.println(dp[n][m]);

        // Reconstruct sequence using parent pointers
        List<Integer> sequence = new ArrayList<>();
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (parent[i][j] == 0) { // diagonal (match)
                sequence.add(x[i - 1]);
                i--;
                j--;
            } else if (parent[i][j] == 1) { // up
                i--;
            } else { // left
                j--;
            }
        }

        // Reverse and print
        Collections.reverse(sequence);
        for (int val : sequence) out.print(val + " ");
        out.println();
    }
}
