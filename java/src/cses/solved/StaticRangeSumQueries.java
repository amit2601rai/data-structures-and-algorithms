package cses.solved;

// Problem: Static Range Sum Queries
// Link: https://cses.fi/problemset/task/1646

import java.io.*;
import java.util.*;

public class StaticRangeSumQueries {

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
        // Write your solution here
        int n = nextInt();
        int q = nextInt();
        long[] arr = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] + nextInt();
        }

        for (int i = 0; i < q; i++) {
            int a = nextInt();
            int b = nextInt();
            out.println(arr[b] - arr[a - 1]);
        }
    }
}
