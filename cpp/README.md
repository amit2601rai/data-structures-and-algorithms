# Data Structures and Algorithms Repository

A comprehensive competitive programming repository with modern C++ templates, organized problem solutions, and efficient build system.

## 🚀 Quick Start

### Creating New C++ Files

**Method 1: Using the automated script (Recommended)**
```bash
# Create a new C++ file with the full template (defaults to src/concepts/misc-codes/)
./new_cpp.sh problem_name.cpp

# Create in a specific directory
./new_cpp.sh problem1.cpp src/practice/codeforces/
./new_cpp.sh dijkstra.cpp src/concepts/graphs/
```

**Method 2: Using VS Code snippets**
1. Create a new `.cpp` file in VS Code
2. Type `cpp` and press Tab to get the full competitive programming template
3. Type `cppmin` and press Tab to get a minimal template

### Building and Running

**Using Makefile (Recommended)**
```bash
# Compile and run
make run FILE=src/path/to/file.cpp

# Run with input file
make run FILE=src/path/to/file.cpp INPUT=tst/input

# Run tests (compares with expected output)
make test FILE=src/path/to/file.cpp

# Debug mode
make debug FILE=src/path/to/file.cpp

# Create new template file
make template NAME=ProblemName DIR=src/concepts/category

# Create test case files (creates tst/input and tst/output)
make create-test

# Format code with Google C++ style
make format FILE=src/path/to/file.cpp     # Format specific file
make format-all                           # Format all C++ files
make format-check                         # Check formatting without changes
```

**Using Shell Script**
```bash
# Compile and run interactively
./run.sh src/path/to/file.cpp

# Run with input file
./run.sh src/path/to/file.cpp tst/input

# Run automated tests
./run.sh -t src/path/to/file.cpp
```

## 📁 Repository Structure

This repository follows a clean separation between source code and test cases:
- `src/` - All source code organized by purpose
- `tst/` - All test cases organized to match source structure

```
├── src/                               # Source code directory
│   ├── concepts/                      # Algorithm implementations by category
│   │   ├── arrays-string-searching-*/ # Array and string algorithms
│   │   ├── dynamic-programming/       # DP problems and solutions
│   │   ├── graphs/                    # Graph algorithms
│   │   ├── binary-tree/               # Tree data structures
│   │   └── [other-categories]/        # Specialized algorithm topics
│   └── practice/                      # Contest solutions by platform
│       ├── Template.cpp               # Minimal working template
│       ├── codeforces/                # Codeforces solutions
│       ├── cses/                      # CSES problem set
│       ├── leetcode/                  # LeetCode solutions
│       └── [other-platforms]/         # Other competitive programming sites
├── tst/                               # Test cases directory
│   ├── input                          # Sample input file
│   ├── output                         # Expected output file
│   └── README.md                      # Test case documentation
├── build/                             # Compiled executables (git-ignored)
├── cpp_template.cpp                   # Master comprehensive template
├── new_cpp.sh                         # Script to create new files
├── run.sh                             # Build and run script
└── Makefile                           # Build automation
```

### Naming Conventions
- **Files**: Use descriptive PascalCase names (e.g., `MaxProfitStock.cpp`, `LongestCommonSubsequence.cpp`)
- **Functions**: Use camelCase for algorithm implementations
- **Variables**: Short names typical in competitive programming (`n`, `m`, `ans`, `dp`)

### File Naming for New Problems
- **Concepts**: `src/concepts/[category]/ProblemDescription.cpp` (e.g., `src/concepts/dynamic-programming/CoinChange.cpp`)
- **Practice**: `src/practice/[platform]/[ContestName]/[ProblemLetter].cpp` (e.g., `src/practice/codeforces/229Div2/A.cpp`)
- **Test Cases**: `tst/input` (sample input) and `tst/output` (expected output)

## 🛠️ Template Features

The modern C++ template (`cpp_template.cpp`) includes:

### **Core Language Features**
- Modern C++17 constructs and syntax
- Fast I/O with `ios_base::sync_with_stdio(false)`
- Comprehensive type definitions (`ll`, `vi`, `pii`, etc.)
- Useful macros (`all()`, `sz()`, `pb`, `FOR`, `REP`)

### **Mathematical Utilities**
- GCD and LCM functions
- Fast exponentiation with modular arithmetic
- Modular inverse calculation
- Debug macros (enabled with `-DDEBUG`)

### **Data Structures**
- **Disjoint Set Union (DSU/Union-Find)** with path compression
- **Fenwick Tree (BIT)** for range sum queries
- **Segment Tree** with lazy propagation
- **Graph utilities** (DFS, BFS, Dijkstra)

### **String Algorithms**
- KMP pattern matching with LPS computation
- String utilities and processing functions

### **Combinatorics**
- Factorial and inverse factorial precomputation
- nCr and nPr calculations with modular arithmetic
- Efficient combinatorial computations

### **Advanced Features**
- Random number generation with Mersenne Twister
- Container manipulation utilities
- Graph representations (adjacency list, weighted)
- Modern C++ features (structured bindings, auto, etc.)

## 🔧 Build System

### Compilation Flags
- **Standard**: C++17 (`-std=c++17`)
- **Optimization**: `-O2` for performance
- **Warnings**: `-Wall -Wextra -pedantic` for code quality
- **Debug**: `-g` for debugging symbols

### Directory Structure
- `build/`: All compiled executables (automatically created)
- No external dependencies or include directories needed

## 🎨 Code Formatting

The repository uses **Google C++ Style Guide** for consistent code formatting:

### **Setup**
```bash
# Install clang-format (one-time setup)
# macOS
brew install clang-format

# Linux
sudo apt-get install clang-format
```

### **Formatting Commands**
```bash
# Format a specific file
make format FILE=src/path/to/file.cpp

# Format all C++ files in the repository
make format-all

# Check formatting without making changes
make format-check
```

### **Automatic Formatting**
- **VS Code**: Automatically formats on save (configured in `.vscode/settings.json`)
- **New files**: Automatically formatted when created with `./new_cpp.sh`
- **Git integration**: Pre-commit hook checks formatting before commits

### **Style Configuration**
The `.clang-format` file configures:
- **Base Style**: Google C++ Style Guide
- **Indentation**: 2 spaces
- **Line Length**: 120 characters
- **Brace Style**: Attach (same line as function/control structure)
- **Include Sorting**: Automatic organization of headers

### **Pre-commit Hook**
The repository includes a pre-commit hook that:
- Automatically checks formatting of staged C++ files
- Prevents commits with improperly formatted code
- Provides helpful commands to fix formatting issues

```bash
# If formatting check fails during commit:
make format-all              # Format all files
git add .                    # Stage formatted changes
git commit                   # Commit again
```

## 📝 Testing Workflow

### Creating Test Cases
```bash
# Create test files (creates tst/input and tst/output)
make create-test

# This creates:
# tst/input    - Sample input
# tst/output   - Expected output
```

### Running Tests
```bash
# Add your test cases to tst/input and tst/output
# Then run automated testing
make test FILE=src/concepts/category/ProblemName.cpp
make test FILE=src/practice/platform/ProblemName.cpp
```

## 💡 Development Patterns

### Algorithm Implementation Style
- Use global arrays/variables for competitive programming efficiency
- Prefer `scanf`/`printf` or `cin`/`cout` based on performance needs
- Use STL containers with typedef shortcuts: `vi arr`, `vii pairs`
- Optimize for time complexity typical in competitive programming

### Contest Solution Pattern
1. Copy from `Template.cpp` or use `./new_cpp.sh`
2. Implement solution in `solve()` function
3. Use standard input/output without file operations
4. Test locally before submission

### Key Algorithm Categories
- **DP Problems**: `src/concepts/dynamic-programming/` contains classic DP patterns
- **Graph Algorithms**: `src/concepts/graphs/` for traversal and path algorithms  
- **Array Problems**: `src/concepts/arrays-string-searching-sorting-hashing-backtracking-adhoc/` for diverse array techniques

## 🎯 Usage Examples

### Basic Problem Solving
```cpp
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    REP(i, n) cin >> arr[i];
    
    // Your solution here
    sort(all(arr));
    cout << arr[0] << endl;
}
```

### Using Data Structures
```cpp
void solve() {
    int n, q;
    cin >> n >> q;
    
    DSU dsu(n);
    FenwickTree ft(n);
    
    REP(i, q) {
        int type, x, y;
        cin >> type >> x >> y;
        
        if (type == 1) {
            dsu.unite(x, y);
        } else {
            ft.update(x, y);
        }
    }
}
```

### Graph Problems
```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    
    Graph g(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vi distances = bfs(g, 0);
    REP(i, n) cout << distances[i] << " ";
}
```

## 🚀 **Clean Architecture & No Dependencies**

This repository now uses **organized directory structure** and **self-contained C++ files** with explicit standard library includes. Benefits:

### Directory Organization
- ✅ **Separated concerns**: Source (`src/`) and tests (`tst/`) clearly separated
- ✅ **Scalable structure**: Easy to navigate and maintain large codebases
- ✅ **Platform organization**: Contest solutions grouped by platform
- ✅ **Category organization**: Concepts grouped by algorithm type

### Technical Benefits
- ✅ **IDE-friendly**: Full IntelliSense support
- ✅ **Portable**: Works on any C++ compiler
- ✅ **Standards-compliant**: No non-standard headers
- ✅ **Clear dependencies**: Explicit header usage
- ✅ **No build complexity**: Simple compilation

## 🏆 Competitive Programming Ready

The template is optimized for:
- **Codeforces** contests
- **CSES** problem set  
- **LeetCode** competitions
- **ACM ICPC** style problems
- **Google Code Jam / Kick Start**
- **AtCoder** contests

## 📚 Getting Started

1. **Clone the repository**
2. **Create a new problem**: 
   ```bash
   # For concept problems
   ./new_cpp.sh dijkstra.cpp src/concepts/graphs/
   
   # For contest problems  
   ./new_cpp.sh problem_a.cpp src/practice/codeforces/contest_123/
   ```
3. **Implement your solution** in the `solve()` function
4. **Create test cases**: `make create-test`
5. **Test it**: `make test FILE=src/concepts/graphs/dijkstra.cpp`
6. **Submit to your platform**

### Quick Reference
```bash
# Complete workflow example
./new_cpp.sh coin_change.cpp src/concepts/dynamic-programming/
make create-test
# Edit tst/input and tst/output files
make test FILE=src/concepts/dynamic-programming/coin_change.cpp
```

Happy coding! 🎯