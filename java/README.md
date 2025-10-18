# Java Data Structures and Algorithms

A comprehensive competitive programming repository with modern Java templates, organized problem solutions, and efficient build system.

## 🚀 Quick Start

### Creating New Java Files

**Method 1: Using the automated script (Recommended)**
```bash
# Create a new Java file with the competitive programming template
./new_java.sh ProblemName

# Create in a specific package
./new_java.sh ProblemName practice.codeforces
./new_java.sh Dijkstra concepts.graphs
```

**Method 2: Using VS Code snippets**
1. Create a new `.java` file in VS Code
2. Type `java` and press Tab to get the competitive programming template
3. Type `javamin` and press Tab to get a minimal template

**Method 3: Manual Creation**
```bash
# Copy from template
cp src/main/java/practice/Main.java src/main/java/practice/YourProblem.java
```

### Building and Running

**Using Build Script (Recommended)**
```bash
# Run HelloWorld (default)
./run_java.sh

# Run specific class
./run_java.sh practice.HelloWorld "arg1" "arg2"

# Run competitive programming template
echo "YourName" | ./run_java.sh practice.Main
```

**Using Maven**
```bash
# Compile all Java files
mvn compile

# Run main class
mvn exec:java -Dexec.mainClass="practice.Main"

# Run with arguments
mvn exec:java -Dexec.mainClass="practice.HelloWorld" -Dexec.args="arg1 arg2"

# Run tests
mvn test
```

**Using Direct Java Commands**
```bash
# Navigate to source directory
cd src/main/java

# Compile
javac practice/HelloWorld.java

# Run
java practice.HelloWorld
java practice.HelloWorld "arg1" "arg2"  # with arguments

# Run with input redirection
java practice.Main < ../../../tst/input
```

## 📁 Project Structure

This Java project follows Maven standard directory layout with competitive programming enhancements:

```
java/
├── src/
│   ├── main/
│   │   └── java/
│   │       ├── concepts/                    # Algorithm implementations
│   │       │   ├── arrays/                  # Array algorithms
│   │       │   ├── dynamicprogramming/      # DP problems and solutions
│   │       │   ├── graphs/                  # Graph algorithms
│   │       │   ├── trees/                   # Tree data structures
│   │       │   └── [other-categories]/      # Specialized algorithm topics
│   │       └── practice/                    # Contest solutions by platform
│   │           ├── Main.java                # Competitive programming template
│   │           ├── HelloWorld.java          # Simple Hello World example
│   │           ├── codeforces/              # Codeforces solutions
│   │           ├── leetcode/                # LeetCode solutions
│   │           └── [other-platforms]/       # Other competitive programming sites
│   └── test/
│       └── java/                            # Unit tests
├── build/                                   # Compiled classes (git-ignored)
│   ├── classes/                            # Compilation output
│   ├── test-classes/                       # Test compilation output
│   └── maven-status/                       # Maven build metadata
├── tst/                                    # Test cases (shared with C++)
│   ├── input                               # Sample input file
│   └── output                              # Expected output file
├── pom.xml                                 # Maven configuration
├── run_java.sh                             # Build and run script
├── format_java.sh                          # Google Java Style formatter
├── google-java-format.jar                 # Formatter tool (auto-downloaded)
├── FORMATTING.md                           # Formatting documentation
└── README.md                               # This documentation
```

### Naming Conventions
- **Classes**: Use PascalCase (e.g., `MaxProfitStock`, `LongestCommonSubsequence`)
- **Methods**: Use camelCase (e.g., `findMaxProfit`, `computeLCS`)
- **Variables**: Use camelCase (e.g., `maxValue`, `currentSum`)
- **Packages**: Use lowercase (e.g., `practice.codeforces`, `concepts.graphs`)
- **Constants**: Use UPPER_SNAKE_CASE (e.g., `MAX_SIZE`, `MOD_VALUE`)

### File Naming for New Problems
- **Concepts**: `src/main/java/concepts/[category]/ProblemDescription.java`  
  (e.g., `src/main/java/concepts/dynamicprogramming/CoinChange.java`)
- **Practice**: `src/main/java/practice/[platform]/[ContestName]/[ProblemLetter].java`  
  (e.g., `src/main/java/practice/codeforces/Round849/A.java`)

## 🛠️ Template Features

The competitive programming template (`Main.java`) includes:

### **Core Language Features**
- Fast I/O using `BufferedReader` and `PrintWriter`
- Comprehensive utility methods for input parsing
- Common data type definitions and constants
- Efficient array reading methods

### **Mathematical Utilities**
- GCD and LCM functions
- Fast exponentiation with modular arithmetic
- Modular inverse calculation
- Power function with modulo support

### **Input/Output Utilities**
- `next()` - Read next string token
- `nextInt()` - Read next integer
- `nextLong()` - Read next long
- `nextDouble()` - Read next double
- `readIntArray(n)` - Read array of n integers
- `readLongArray(n)` - Read array of n longs

### **Common Constants**
```java
private static final long MOD = 1000000007L;
private static final int INF = Integer.MAX_VALUE;
private static final long LINF = Long.MAX_VALUE;
```

### **Example Usage**
```java
// Reading input
int n = nextInt();
int[] arr = readIntArray(n);

// Mathematical operations
long result = power(base, exp, MOD);
long gcdValue = gcd(a, b);

// Output
pw.println(result);
```

## 🔧 Build System

### Maven Configuration
- **Java Version**: 21
- **Encoding**: UTF-8
- **Main Class**: `practice.Main`
- **Dependencies**: JUnit 5, AssertJ (for testing)

### Build Commands
```bash
# Compile (generates class files in build/classes/)
mvn compile

# Run main class
mvn exec:java

# Package into JAR
mvn package

# Clean build artifacts (removes build/ directory)
mvn clean

# Run tests
mvn test
```

### Clean Source Directory
The build system is configured to keep the `src/` directory clean:
- **Class files** are generated in `build/classes/` (not in `src/`)
- **Test classes** are generated in `build/test-classes/`
- **Build artifacts** are contained in the `build/` directory
- **Maven artifacts** use custom output directories to avoid polluting `src/`

### Compilation Flags
- **Target**: Java 21
- **Encoding**: UTF-8
- **Debug**: Enabled for development

## 🎨 Code Formatting

The project uses **Google Java Style Guide** for consistent code formatting:

### **Formatting Commands**
```bash
# Format all Java files
./format_java.sh

# Format specific file
./format_java.sh src/main/java/practice/HelloWorld.java

# Format specific directory
./format_java.sh src/main/java/practice/
```

### **Automatic Formatting**
- **VS Code**: Automatically formats on save (configured in `.vscode/settings.json`)
- **Style**: Google Java Style Guide
- **Indentation**: 2 spaces
- **Line Length**: 100 characters
- **Import Organization**: Automatic

### **Style Configuration**
```json
{
  "java.format.settings.url": "https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-java-google-style.xml",
  "java.format.settings.profile": "GoogleStyle",
  "editor.formatOnSave": true
}
```

## 📝 Testing Workflow

### Creating Test Cases
```bash
# Create shared test files (works with C++ too)
cd ../  # Go to repository root
make create-test
```

### Running with Test Input
```bash
# Using build script
echo "test input" | ./run_java.sh practice.Main

# Using direct Java
java practice.Main < tst/input

# Using Maven
mvn exec:java -Dexec.mainClass="practice.Main" < tst/input
```

### Unit Testing
```bash
# Run all tests
mvn test

# Run specific test class
mvn test -Dtest=MainTest
```

## 🏃‍♂️ Development Workflow

### For New Problems
1. **Create the Java file**:
   ```bash
   ./new_java.sh ProblemName practice.codeforces
   ```

2. **Implement the solution** in the `solve()` method

3. **Create test cases**:
   ```bash
   # Add input to tst/input
   echo "5\n1 2 3 4 5" > tst/input
   ```

4. **Test the solution**:
   ```bash
   ./run_java.sh practice.codeforces.ProblemName < tst/input
   ```

5. **Format the code**:
   ```bash
   ./format_java.sh src/main/java/practice/codeforces/ProblemName.java
   ```

### For Algorithm Implementation
1. Create in appropriate concept package
2. Include comprehensive Javadoc comments
3. Add unit tests in `src/test/java/`
4. Ensure Google Style formatting

## 🔍 VS Code Integration

### Extensions Installed
- **Extension Pack for Java** - Complete Java development support
- **Language Support for Java** - Core language features
- **Debugger for Java** - Debug support
- **Maven for Java** - Maven integration
- **Test Runner for Java** - JUnit support

### Features Available
- ✅ **Syntax highlighting** and IntelliSense
- ✅ **Debugging** with breakpoints
- ✅ **Maven integration** and dependency management
- ✅ **JUnit test runner**
- ✅ **Automatic formatting** on save
- ✅ **Import organization**
- ✅ **Code completion** and quick fixes

## 📚 Examples

### Hello World
```java
package practice;

public class HelloWorld {
  public static void main(String[] args) {
    System.out.println("Hello, World!");
    System.out.println("Java Version: " + System.getProperty("java.version"));
  }
}
```

### Competitive Programming Template Usage
```java
private static void solve() throws IOException {
  int n = nextInt();
  int[] arr = readIntArray(n);
  
  long sum = 0;
  for (int x : arr) {
    sum += x;
  }
  
  pw.println(sum);
}
```

### Running Examples
```bash
# Run Hello World
./run_java.sh practice.HelloWorld

# Run with arguments
./run_java.sh practice.HelloWorld "arg1" "arg2"

# Run competitive template with input
echo -e "5\n1 2 3 4 5" | ./run_java.sh practice.Main
```

## 🚀 Getting Started

1. **Ensure Java 21+ is installed**:
   ```bash
   java --version
   ```

2. **Run Hello World**:
   ```bash
   ./run_java.sh practice.HelloWorld
   ```

3. **Test competitive programming template**:
   ```bash
   echo "TestName" | ./run_java.sh practice.Main
   ```

4. **Create your first problem**:
   ```bash
   ./new_java.sh MyFirstProblem practice
   ```

Your Java competitive programming environment is ready! 🎯☕

## 🔗 Resources

- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- [Java Documentation](https://docs.oracle.com/en/java/javase/17/)
- [Maven Documentation](https://maven.apache.org/guides/)
- [VS Code Java Extension Pack](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)