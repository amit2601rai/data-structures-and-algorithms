package cses.solved;

// Problem: Message Route
// Link: https://cses.fi/problemset/task/1667/

import java.io.*;
import java.util.*;

public class MessageRoute {

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
        int m = nextInt();

        // Array-based adjacency list with 1-based indexing
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = nextInt();
            int b = nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }

        int[] parent = new int[n + 1];
        Arrays.fill(parent, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        parent[1] = 1;

        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : graph[u]) {
                if (parent[v] == -1) {
                    parent[v] = u;
                    queue.add(v);
                }
            }
        }

        if (parent[n] == -1) {
            out.println("IMPOSSIBLE");
            return;
        }

        List<Integer> path = new ArrayList<>();
        for (int v = n; v != 1; v = parent[v]) {
            path.add(v);
        }
        path.add(1);
        Collections.reverse(path);

        out.println(path.size());
        for (int v : path) {
            out.print(v + " ");
        }
        out.println();
    }
}
