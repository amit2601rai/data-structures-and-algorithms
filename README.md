# Data Structures and Algorithms

A comprehensive competitive programming repository with dual-language support for **C++** and **Java**, featuring modern templates, organized problem solutions, and efficient build systems.

## 📁 Repository Structure

```
data-structures-and-algorithms/
├── cpp/                    # C++ src/tst dir
│   ├── src/              
│   ├── build/          
│   └── Makefile        
├── java/                  # Java src/tst dir
│   ├── src/               
│   ├── build/            
│   └── pom.xml          
└── README.md              
```

## 🏃‍♂️ Quick Start

### Prerequisites
- **C++**: GCC/Clang with C++17 support, clang-format
- **Java**: Java 21+, Maven 3.6+

---

## 🔧 C++ Development

### Building and Running C++

**Using Makefile (Recommended)**
```bash
cd cpp/

# Compile and run a file
make run FILE=src/practice/cses/3421.cpp

# Run with input file
make run FILE=src/concepts/arrays/MaxProfitStock.cpp INPUT=tst/input

# Test with expected output comparison
make test FILE=src/concepts/dynamic-programming/CoinChange.cpp

# Debug mode compilation
make debug FILE=src/practice/codeforces/Round849/A.cpp

# Quick compile and run
make quick FILE=src/concepts/graphs/Dijkstra.cpp
```

**Direct Compilation**
```bash
cd cpp/

# Compile
g++ -std=c++17 -O2 -Wall -o build/program src/path/to/file.cpp

# Run
./build/program

# Run with input
./build/program < tst/input
```

### Creating New C++ Files
```bash
cd cpp/

# Create new file with template
make template NAME=ProblemName DIR=src/concepts/category

# Create test cases
make create-test

# Format code (Google C++ Style)
make format FILE=src/path/to/file.cpp
make format-all                    # Format all files
```

---

## ☕ Java Development

### Building and Running Java

**Using Build Script (Recommended)**
```bash
cd java/

# Run HelloWorld
./run_java.sh practice.HelloWorld "arg1" "arg2"

# Run competitive programming template
echo "YourName" | ./run_java.sh practice.Main

# Run with input redirection
./run_java.sh practice.Main < tst/input
```

**Using Maven**
```bash
cd java/

# Compile all Java files (outputs to build/classes/)
mvn compile

# Run main class
mvn exec:java -Dexec.mainClass="practice.Main"

# Run with arguments
mvn exec:java -Dexec.mainClass="practice.HelloWorld" -Dexec.args="arg1 arg2"

# Clean build artifacts
mvn clean

# Package into JAR
mvn package
```

**Direct Java Commands**
```bash
cd java/src/

# Compile
javac practice/HelloWorld.java -d ../build/classes/

# Run
cd ../build/classes/
java practice.HelloWorld

# Run with input
java practice.Main < ../../tst/input
```
---

## 🎨 Code Formatting

### C++ Formatting (Google Style)
```bash
cd cpp/

# Format specific file
make format FILE=src/path/to/file.cpp

# Format all C++ files
make format-all

# Check formatting without changes
make format-check
```

### Java Formatting (Google Style)
```bash
cd java/

# Format all Java files
./format_java.sh

# Format specific file
./format_java.sh src/practice/HelloWorld.java

# VS Code auto-formats on save (configured)
```

---

## 🧪 Testing Workflow

### Create Test Cases
```bash
# For C++
cd cpp/
make create-test        # Creates tst/input and tst/output

# For Java  
cd java/
# Use shared tst/ directory from cpp/ or create manually
```

### Running Tests
```bash
# C++ with test comparison
cd cpp/
make test FILE=src/concepts/arrays/MaxProfitStock.cpp

# Java with input redirection
cd java/
./run_java.sh practice.Main < ../cpp/tst/input
```

---

## 📚 Resources

- [C++ Reference](https://en.cppreference.com/)
- [Java Documentation](https://docs.oracle.com/en/java/javase/21/)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- [Competitive Programming](https://codeforces.com/)
