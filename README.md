# Data Structures and Algorithms

Competitive programming repository with **C++** and **Java** support.

## Prerequisites
- **C++**: GCC/Clang with C++17, clang-format
- **Java**: Java 21+ (Gradle wrapper included)

---

## C++ Quick Reference

### Build & Run
```bash
cd cpp/

# Run without input
make run FILE=src/practice/cses/1234.cpp

# Run with input file
make run FILE=src/concepts/arrays/MaxProfitStock.cpp INPUT=tst/input

# Test with expected output
make test FILE=src/concepts/dp/CoinChange.cpp
```

### Format Code
```bash
# Format single file
make format FILE=src/path/to/file.cpp

# Format all files
make format-all
```

---

## Java Quick Reference

### Build & Run
```bash
cd java/

# Run without input
./gradlew runMain

# Run with input file
./gradlew runMain -q < tst/input

# Run specific class
./gradlew runClass -PmainClass=practice.YourClass -q
```

### Format Code
```bash
# Format all files
./gradlew format

# Check formatting
./gradlew checkFormat
```

---

## Testing Workflow

```bash
# Create test files
cd cpp/
make create-test  # Creates tst/input and tst/output

# C++ - run with comparison
make test FILE=src/path/to/file.cpp

# Java - run with input
cd java/
./gradlew runMain -q < ../cpp/tst/input
```
