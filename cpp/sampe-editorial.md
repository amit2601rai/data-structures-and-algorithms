# CSES 1673: High Score

**Difficulty:** Hard  
**Topics:** Graphs, Bellman-Ford, Shortest Path, Negative Cycles  
**Link:** [Problem on CSES](https://cses.fi/problemset/task/1673/)

---

## Table of Contents

1. [Problem Statement](#1-problem-statement)
2. [Intuition](#2-intuition)
3. [Approach](#3-approach)
4. [Algorithm Details](#4-algorithm-details)
5. [Complexity Analysis](#5-complexity-analysis)
6. [Key Insights](#6-key-insights)

---

## 1. Problem Statement

You play a game consisting of `n` rooms and `m` tunnels. Your initial score is 0, and each tunnel increases your score by `x` where `x` may be both positive or negative. You may go through a tunnel several times.

Your task is to walk from room 1 to room `n`. What is the maximum score you can get?

**Important:** If you can get an arbitrarily large score (i.e., there's a positive cycle on some path from room 1 to room n), print -1.

**Constraints:**
- $1 \leq n \leq 2500$
- $1 \leq m \leq 5000$
- $1 \leq a, b \leq n$
- $-10^9 \leq x \leq 10^9$
- It is guaranteed that you can reach room n from room 1

**Example:**

```
Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Output:
5
```

**Explanation:** Optimal path is 1 → 3 → 4 with score -2 + 7 = 5.

[↑ Back to Table of Contents](#table-of-contents)

---

## 2. Intuition

**Core Problem:** This is a **maximum path** problem in a directed graph with positive and negative edge weights, where edges can be traversed multiple times.

**Key Insight - Modified Bellman-Ford:** 
- Standard Bellman-Ford finds **shortest paths** (minimum distance)
- We need **longest paths** (maximum score)
- Solution: Use Bellman-Ford but **maximize** instead of minimize

**The Tricky Part - Positive Cycles:**
```
Example with positive cycle:

    1 -----> 2
     \      /|
      \    / |
       \  /  | +10 (positive cycle 2→3→2)
        \/   |
         3---+

If we can reach the cycle from node 1 AND reach node n from the cycle,
we can loop infinitely to get arbitrarily large score → Answer: -1
```

**Critical Observation:** A positive cycle only matters if it lies on **some** path from node 1 to node n. A disconnected positive cycle doesn't affect our answer.

**Naive Approach (INCORRECT):**
```cpp
// After n-1 iterations of Bellman-Ford
for (auto [u, v, w] : edges) {
    if (dist[u] > kInf && dist[v] < dist[u] + w) {
        // Found positive cycle somewhere
        return -1;  // ❌ WRONG!
    }
}
```

**Why it fails:** This detects ANY positive cycle in the graph, even if it's unreachable from node 1 or doesn't lead to node n.

[↑ Back to Table of Contents](#table-of-contents)

---

## 3. Approach

### Solution 1: Reachability Check + Bellman-Ford (Most Intuitive)

**Strategy:** Explicitly check if positive cycles lie on paths from 1 to n.

**Three-Phase Algorithm:**

**Phase 1: Forward Reachability (BFS from node 1)**
```cpp
Find all nodes reachable from node 1
```

**Phase 2: Backward Reachability (BFS from node n on reversed graph)**
```cpp
Find all nodes that can reach node n
```

**Phase 3: Modified Bellman-Ford + Cycle Detection**
```cpp
Run Bellman-Ford for maximum path
Detect positive cycles
Check if cycle nodes are on path: reachable from 1 AND can reach n
```

**Visualization:**
```
Graph with positive cycle:

    1 ----5----> 2 ----3----> 4 (node n)
                 |           /
                +10         /
                 |         /
                 v        /
                 3 -----2
                 
Forward reachability from 1: {1, 2, 3, 4}
Backward reachability to 4: {2, 3, 4}
Intersection (nodes on path 1→4): {2, 3, 4}

Positive cycle detected at nodes 2, 3
Both are in intersection → Answer: -1 ✓
```

### Solution 2: Infinity Propagation (Most Elegant)

**Key Idea:** After standard Bellman-Ford (n-1 iterations), run **n additional iterations** to mark and propagate nodes affected by positive cycles.

**Why n more iterations?**
- Cycle detection: One extra iteration detects if relaxation is still possible
- Propagation: Worst case requires n iterations to propagate through a chain of n nodes

**Marking Strategy:**
```cpp
// After detecting a node can be improved → affected by positive cycle
dist[v] = +INFINITY  // Mark as "infinite score possible"

// Propagate the marking
if (dist[u] == +INFINITY) {
    dist[v] = +INFINITY  // Spread to reachable nodes
}
```

**Propagation Example:**
```
Initial: 1 → 2 → (cycle) → 3 → 4 → 5 → n

Iteration n:     Cycle nodes marked as ∞
Iteration n+1:   Node 3 marked as ∞ (reachable from cycle)
Iteration n+2:   Node 4 marked as ∞
Iteration n+3:   Node 5 marked as ∞
Iteration n+4:   Node n marked as ∞ → Output: -1
```

### Solution 3: SPFA with Relaxation Counter

**SPFA (Shortest Path Faster Algorithm):** Queue-optimized Bellman-Ford

**Enhancement:** Track how many times each node is relaxed. If a node is relaxed ≥ n times, it's affected by a positive cycle.

**Why this works:** In a graph with n nodes, the longest simple path has at most n-1 edges. If we need ≥ n relaxations, we must be cycling.

**Queue Optimization Benefit:** Only enqueue nodes whose distance changed, avoiding unnecessary edge checks.

[↑ Back to Table of Contents](#table-of-contents)

---

## 4. Algorithm Details

### Solution 1: Reachability Check + Bellman-Ford

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

vector<int> adj[2505], radj[2505];

void bfs(int start, vector<bool>& visited, vector<int> graph[]) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);      // Forward graph
        radj[v].push_back(u);      // Reverse graph
    }
    
    // Find nodes reachable from node 1
    vector<bool> from_start(n + 1);
    bfs(1, from_start, adj);
    
    // Find nodes that can reach node n (BFS on reversed graph)
    vector<bool> to_end(n + 1);
    bfs(n, to_end, radj);
    
    // Bellman-Ford for maximum path
    const ll kInf = -1e18;
    vector<ll> dist(n + 1, kInf);
    dist[1] = 0;
    
    // Standard n-1 iterations
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] > kInf) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    
    // Check for positive cycle on path 1→n
    for (auto [u, v, w] : edges) {
        if (dist[u] > kInf && dist[v] < dist[u] + w) {
            // Positive cycle exists at node v
            // Check if v is on some path from 1 to n
            if (from_start[v] && to_end[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << dist[n] << endl;
    return 0;
}
```

**Key Points:**
- `adj[]`: Forward adjacency list for BFS from node 1
- `radj[]`: Reverse adjacency list for BFS from node n
- `from_start[v]`: True if node v is reachable from node 1
- `to_end[v]`: True if node v can reach node n
- Positive cycle affects answer only if it's on a path: `from_start[v] && to_end[v]`

### Solution 2: Infinity Propagation

```cpp
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    const ll kInf = -1e18;
    const ll kPosInf = 1e18;
    vector<ll> dist(n + 1, kInf);
    dist[1] = 0;
    
    // Standard Bellman-Ford: n-1 iterations
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] > kInf) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    
    // Run n more iterations to detect and propagate positive cycles
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] > kInf) {
                // Node can still be improved → affected by positive cycle
                if (dist[v] < dist[u] + w) {
                    dist[v] = kPosInf;
                }
                // Propagate infinity marking
                if (dist[u] >= kPosInf) {
                    dist[v] = kPosInf;
                }
            }
        }
    }
    
    if (dist[n] >= kPosInf) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    
    return 0;
}
```

**Why n iterations for propagation?**

Consider a chain: `1 → (cycle) → A → B → C → ... → n`

- Iteration 1: Cycle nodes marked as ∞
- Iteration 2: Node A marked
- Iteration 3: Node B marked
- ...
- Iteration k: Node n marked (if k ≤ n)

Worst case: linear chain of n nodes requires n iterations to propagate from one end to other.

### Solution 3: SPFA with Relaxation Counter

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    const ll kInf = -1e18;
    vector<ll> dist(n + 1, kInf);
    vector<int> cnt(n + 1, 0);  // Relaxation counter
    vector<bool> in_queue(n + 1, false);
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    in_queue[1] = true;
    
    bool has_positive_cycle = false;
    
    while (!q.empty() && !has_positive_cycle) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v]++;
                
                // If relaxed ≥ n times, positive cycle affects this node
                if (cnt[v] >= n) {
                    if (v == n) {
                        has_positive_cycle = true;
                        break;
                    }
                    // Don't enqueue nodes affected by cycles
                    continue;
                }
                
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    
    if (has_positive_cycle || cnt[n] >= n) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    
    return 0;
}
```

**Optimization:** SPFA only processes nodes whose distances changed, avoiding redundant edge relaxations.

**Caveat:** SPFA can have $O(nm)$ worst-case complexity, same as Bellman-Ford, but performs much better on average.

[↑ Back to Table of Contents](#table-of-contents)

---

## 5. Complexity Analysis

### Solution 1: Reachability Check + Bellman-Ford

**Time Complexity:** $O(n + m + nm) = O(nm)$
- BFS (forward): $O(n + m)$
- BFS (backward): $O(n + m)$
- Bellman-Ford: $O(nm)$ (n-1 iterations × m edges)
- Cycle check: $O(m)$
- **Total:** $O(nm)$

**Space Complexity:** $O(n + m)$
- Adjacency lists: $O(m)$
- Reverse adjacency lists: $O(m)$
- Distance array: $O(n)$
- Visited arrays: $O(n)$

### Solution 2: Infinity Propagation

**Time Complexity:** $O(nm)$
- First n-1 iterations: $O(nm)$
- Additional n iterations: $O(nm)$
- **Total:** $O(nm)$ (constant factor ≈ 2x)

**Space Complexity:** $O(n + m)$
- Edge list: $O(m)$
- Distance array: $O(n)$

### Solution 3: SPFA

**Time Complexity:** 
- **Average case:** $O(m)$ to $O(km)$ where k is small
- **Worst case:** $O(nm)$ (degenerate to Bellman-Ford)

**Space Complexity:** $O(n + m)$
- Adjacency list: $O(m)$
- Distance, counter, queue arrays: $O(n)$

### Comparison

| Solution | Time | Space | Code Complexity | Robustness |
|----------|------|-------|-----------------|------------|
| Reachability + BF | $O(nm)$ | $O(n+m)$ | Medium | High |
| Infinity Propagation | $O(nm)$ | $O(n+m)$ | Low | High |
| SPFA | $O(m)$ avg, $O(nm)$ worst | $O(n+m)$ | Medium | Medium |

**Recommendation:** Solution 2 (Infinity Propagation) is the most elegant and easiest to implement correctly.

[↑ Back to Table of Contents](#table-of-contents)

---

## 6. Key Insights

### Why Maximum Path is Hard

**Standard shortest path algorithms:**
- Dijkstra: Doesn't work with negative edges
- Bellman-Ford: Finds shortest paths, detects negative cycles

**For maximum paths:**
- Need Bellman-Ford with maximization (not minimization)
- Detect **positive cycles** (not negative cycles)
- Only cycles **on the path** matter, not all cycles in graph

### Bellman-Ford for Longest Path

**Modification required:**

| Feature | Shortest Path | Longest Path |
|---------|---------------|--------------|
| Initialization | `dist[1] = 0`, rest = `+∞` | `dist[1] = 0`, rest = `−∞` |
| Relaxation | `dist[v] = min(dist[v], dist[u] + w)` | `dist[v] = max(dist[v], dist[u] + w)` |
| Problem cycle | Negative cycle | Positive cycle |
| Detection | Still improves after n-1 iterations | Still improves after n-1 iterations |

### Common Mistakes

**❌ Mistake 1: Not checking reachability**
```cpp
// Detects ANY positive cycle, even unreachable ones
for (auto [u, v, w] : edges) {
    if (dist[v] < dist[u] + w) {
        return -1;  // WRONG!
    }
}
```

**❌ Mistake 2: Insufficient propagation iterations**
```cpp
// Only 1 extra iteration - doesn't propagate through long chains
for (int i = 0; i < 1; i++) {  // Should be n iterations
    // ...
}
```

**❌ Mistake 3: Using Dijkstra**
```cpp
// Dijkstra FAILS with negative edges
// Can't negate edges for maximum path (creates negative edges)
```

**✅ Correct approach:** Use one of the three solutions above.

### Edge Cases

| Case | Expected Behavior |
|------|-------------------|
| Single edge 1→n | Return edge weight |
| No positive cycle | Return maximum path score |
| Positive cycle not on path 1→n | Return maximum path score (ignore cycle) |
| Positive cycle on path 1→n | Return -1 |
| All edges negative | Still find maximum (least negative) path |
| Self-loop at node 1 or n | Handle in cycle detection |

### Problem Variations

**Related Problems:**

| Problem | Platform | Difficulty | Link |
|---------|----------|------------|------|
| **Shortest Routes I** | CSES | <span style="color: green">**Easy**</span> | [Problem](https://cses.fi/problemset/task/1671) |
| **Shortest Routes II** | CSES | <span style="color: orange">**Medium**</span> | [Problem](https://cses.fi/problemset/task/1672) |
| **Flight Discount** | CSES | <span style="color: orange">**Medium**</span> | [Problem](https://cses.fi/problemset/task/1195) |
| **Cycle Finding** | CSES | <span style="color: orange">**Medium**</span> | [Problem](https://cses.fi/problemset/task/1197) |
| **Flight Routes** | CSES | <span style="color: red">**Hard**</span> | [Problem](https://cses.fi/problemset/task/1196) |
| **Network Delay Time** | LeetCode 743 | <span style="color: orange">**Medium**</span> | [Problem](https://leetcode.com/problems/network-delay-time/) |
| **Cheapest Flights Within K Stops** | LeetCode 787 | <span style="color: orange">**Medium**</span> | [Problem](https://leetcode.com/problems/cheapest-flights-within-k-stops/) |
| **Path with Maximum Probability** | LeetCode 1514 | <span style="color: orange">**Medium**</span> | [Problem](https://leetcode.com/problems/path-with-maximum-probability/) |
| **Path With Minimum Effort** | LeetCode 1631 | <span style="color: orange">**Medium**</span> | [Problem](https://leetcode.com/problems/path-with-minimum-effort/) |

**Problem Categories:**
- **Shortest/Longest paths:** Dijkstra, Bellman-Ford, Floyd-Warshall
- **Cycle detection:** Negative/positive cycles in directed graphs
- **Graph with constraints:** Limited traversals, k-stops, etc.

**Extensions:**
- Find the actual path (not just score) → Track predecessors
- Multiple sources → Run from all sources
- Dynamic graph updates → Requires advanced data structures

[↑ Back to Table of Contents](#table-of-contents)

---

## Summary

**Problem:** Find maximum score from room 1 to room n, or -1 if arbitrarily large score is possible.

**Key Techniques:**
1. Modified Bellman-Ford for maximum path
2. Positive cycle detection
3. Reachability analysis to filter relevant cycles

**Best Solution:** Infinity propagation (Solution 2)
- Clean implementation
- Handles all edge cases
- Optimal complexity $O(nm)$

**Takeaway:** When detecting cycles in path problems, always verify the cycle affects the specific path in question!
