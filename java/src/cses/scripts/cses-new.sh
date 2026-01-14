#!/bin/bash

# Script to create a new CSES Solution.java with template
# Usage: ./cses-new.sh [CSES_URL]
# Example: ./cses-new.sh https://cses.fi/problemset/task/1131/

CSES_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SOLUTION_FILE="$CSES_DIR/Solution.java"
INPUT_FILE="$CSES_DIR/input"
OUTPUT_FILE="$CSES_DIR/output"

CSES_URL="$1"
PROBLEM_NAME=""
PROBLEM_ID=""

# Check if Solution.java already exists
if [ -f "$SOLUTION_FILE" ]; then
    echo "⚠️  Warning: Solution.java already exists!"
    echo "If you have unsaved work, please use cses-archive.sh first to save it."
    read -p "Do you want to overwrite it? (y/N): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo "Aborted. No changes made."
        exit 1
    fi
fi

# Extract problem info from URL if provided
if [ -n "$CSES_URL" ]; then
    echo "📡 Fetching problem details from CSES..."

    # Extract problem ID from URL
    PROBLEM_ID=$(echo "$CSES_URL" | grep -oE '[0-9]+' | tail -1)

    if [ -n "$PROBLEM_ID" ]; then
        # Fetch the page
        PAGE_CONTENT=$(curl -s "$CSES_URL")

        # Extract problem name from first h1 tag
        PROBLEM_NAME=$(echo "$PAGE_CONTENT" | grep -m 1 "<h1>" | sed 's/<[^>]*>//g' | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')

        # Use Python for reliable HTML parsing
        PARSED_DATA=$(echo "$PAGE_CONTENT" | python3 -c "
import sys
import re
content = sys.stdin.read()

# Find all pre tags
pre_tags = re.findall(r'<pre>(.*?)</pre>', content, re.DOTALL)

# Get last 2 pre tags (usually input and output from example section)
if len(pre_tags) >= 2:
    sample_input = pre_tags[-2].strip()
    sample_output = pre_tags[-1].strip()
    print(f'INPUT_START')
    print(sample_input)
    print(f'INPUT_END')
    print(f'OUTPUT_START')
    print(sample_output)
    print(f'OUTPUT_END')
" 2>/dev/null)

        # Extract input from parsed data
        SAMPLE_INPUT=$(echo "$PARSED_DATA" | sed -n '/INPUT_START/,/INPUT_END/p' | sed '1d;$d')

        # Extract output from parsed data
        SAMPLE_OUTPUT=$(echo "$PARSED_DATA" | sed -n '/OUTPUT_START/,/OUTPUT_END/p' | sed '1d;$d')

        if [ -n "$PROBLEM_NAME" ] && [ "$PROBLEM_NAME" != "CSES" ]; then
            echo "✅ Found: $PROBLEM_NAME (ID: $PROBLEM_ID)"
        else
            echo "⚠️  Could not extract problem name, using ID only"
            PROBLEM_NAME="Problem $PROBLEM_ID"
        fi

        # Save sample input/output to files
        if [ -n "$SAMPLE_INPUT" ]; then
            # Decode HTML entities and save
            echo "$SAMPLE_INPUT" | sed 's/&lt;/</g;s/&gt;/>/g;s/&amp;/\&/g;s/&quot;/"/g' > "$INPUT_FILE"
            echo "1/Success: Saved sample input to input"
        else
            echo "2/Failure: Could not extract sample input from CSES"
        fi

        if [ -n "$SAMPLE_OUTPUT" ]; then
            # Decode HTML entities and save
            echo "$SAMPLE_OUTPUT" | sed 's/&lt;/</g;s/&gt;/>/g;s/&amp;/\&/g;s/&quot;/"/g' > "$OUTPUT_FILE"
            echo "1/Success: Saved expected output to output"
        else
            echo "2/Failure: Could not extract expected output from CSES"
        fi
    else
        echo "⚠️  Could not extract problem ID from URL"
    fi
fi

# Create Solution.java with template
cat > "$SOLUTION_FILE" << 'EOF'
import java.util.*;
import java.io.*;

public class Solution {
  static final int MOD = (int)1e9 + 7;
  static final int INF = (int)2e9;
  static final long LINF = (long)1e18;
  static final int[] DX = {-1, 0, 1, 0}, DY = {0, 1, 0, -1};

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter out = new PrintWriter(System.out);
  static StringTokenizer st = new StringTokenizer("");

  // Helper classes
  static class Pair implements Comparable<Pair> {
    int x, y;
    Pair(int x, int y) { this.x = x; this.y = y; }
    public int compareTo(Pair p) { return x != p.x ? x - p.x : y - p.y; }
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

  static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }

  public static void main(String[] args) throws IOException {
    solve();
    out.close();
  }

  static void solve() throws IOException {
    // Write your solution here

  }
}
EOF

# Add problem info as comments if available
if [ -n "$CSES_URL" ]; then
    # Insert problem info at the top
    TEMP_FILE="${SOLUTION_FILE}.tmp"
    {
        if [ -n "$PROBLEM_NAME" ]; then
            echo "// Problem: $PROBLEM_NAME"
        fi
        echo "// Link: $CSES_URL"
        echo ""
        cat "$SOLUTION_FILE"
    } > "$TEMP_FILE"
    mv "$TEMP_FILE" "$SOLUTION_FILE"
fi

echo "1/Success: Created new Solution.java with CP template"
if [ -n "$PROBLEM_NAME" ]; then
    echo "📋 Problem: $PROBLEM_NAME"
fi
if [ -n "$CSES_URL" ]; then
    echo "🔗 Link: $CSES_URL"
fi
echo "📝 File location: $SOLUTION_FILE"
echo ""
echo "Next steps:"
echo "  1. Implement your solution in solve() method"
if [ -f "$INPUT_FILE" ]; then
    echo "  2. Test locally: cd scripts && ./cses-run.sh"
else
    echo "  2. Create input file and test: cd scripts && ./cses-run.sh"
fi
echo "  3. Submit to CSES"
echo "  4. After acceptance: cd scripts && ./cses-archive.sh <ProblemName>"

