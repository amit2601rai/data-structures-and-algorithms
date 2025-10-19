package practice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Competitive Programming Template for Java Author: Your Name Features: Fast I/O, Common utilities,
 * Data structures
 */
public class Main {
  private static final long MOD = 1000000007L;
  private static final int INF = Integer.MAX_VALUE;
  private static final long LINF = Long.MAX_VALUE;

  // Fast I/O using BufferedReader
  private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static PrintWriter pw = new PrintWriter(System.out);
  private static StringTokenizer st;

  // Utility methods for input
  private static String next() throws IOException {
    while (st == null || !st.hasMoreTokens()) {
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }

  private static int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  private static long nextLong() throws IOException {
    return Long.parseLong(next());
  }

  private static double nextDouble() throws IOException {
    return Double.parseDouble(next());
  }

  private static int[] readIntArray(int n) throws IOException {
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = nextInt();
    }
    return arr;
  }

  private static long[] readLongArray(int n) throws IOException {
    long[] arr = new long[n];
    for (int i = 0; i < n; i++) {
      arr[i] = nextLong();
    }
    return arr;
  }

  // Mathematical utilities
  private static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  private static long lcm(long a, long b) {
    return a / gcd(a, b) * b;
  }

  private static long power(long base, long exp, long mod) {
    long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp % 2 == 1) {
        result = (result * base) % mod;
      }
      base = (base * base) % mod;
      exp /= 2;
    }
    return result;
  }

  // Main solution method
  private static void solve() throws IOException {
    // Simple Hello World
    pw.println("Hello, World!");
    pw.println("Welcome to Java competitive programming!");

    // Example with input
    pw.print("Enter your name: ");
    pw.flush(); // Make sure the prompt is displayed
    String name = next();
    pw.println("Hello, " + name + "!");
  }

  public static void main(String[] args) throws IOException {
    // Uncomment for multiple test cases
    // int t = nextInt();
    // while (t-- > 0) {
    // solve();
    // }

    solve();

    pw.close();
    br.close();
  }
}
