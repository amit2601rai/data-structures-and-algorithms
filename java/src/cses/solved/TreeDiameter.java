package cses.solved;

import java.io.*;
import java.util.*;

public class TreeDiameter {
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

        // Build adjacency list
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int u = nextInt();
            int v = nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }

        // Find one end of the diameter (farthest from node 1)
        int[] result1 = bfs(graph, n, 1);
        int farthestNode = result1[1];

        // Find the actual diameter (farthest from farthestNode)
        int[] result2 = bfs(graph, n, farthestNode);
        int diameter = result2[0];

        out.println(diameter);
    }

    // BFS from source node, returns [maxDistance, farthestNode]
    static int[] bfs(List<Integer>[] graph, int n, int source) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);

        Queue<Integer> queue = new LinkedList<>();
        dist[source] = 0;
        queue.add(source);

        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : graph[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    queue.add(v);
                }
            }
        }

        // Find the farthest node and its distance
        int maxDist = 0;
        int farthestNode = source;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF && dist[i] > maxDist) {
                maxDist = dist[i];
                farthestNode = i;
            }
        }

        return new int[] {maxDist, farthestNode};
    }
}
