# Gradle Commands Quick Reference

## Build Commands
```bash
# Clean build artifacts
./gradlew clean

# Compile Java sources
./gradlew compileJava

# Build project (compile + test + check)
./gradlew build

# Build without tests
./gradlew build -x test
```

## Run Commands
```bash
# Run main class (practice.Main)
./gradlew runMain

# Run HelloWorld
./gradlew runHello

# Run any class
./gradlew runClass -PmainClass=practice.YourClass

# Run with arguments
./gradlew runClass -PmainClass=practice.Main -Pargs="arg1,arg2"

# Run with input (interactive)
echo "test input" | ./gradlew runMain -q

# Quiet mode (less output)
./gradlew runMain -q
```

## Code Formatting (Google Java Style)
```bash
# Format all Java files
./gradlew format
# OR
./gradlew spotlessApply

# Check formatting (no changes)
./gradlew checkFormat
# OR
./gradlew spotlessCheck
```

## Test Commands
```bash
# Run all tests
./gradlew test

# Run tests with output
./gradlew test --info

# Run specific test
./gradlew test --tests YourTestClass
```

## Utility Commands
```bash
# List all tasks
./gradlew tasks

# List all tasks including internal
./gradlew tasks --all

# Show project dependencies
./gradlew dependencies

# Show project info
./gradlew projects

# Gradle version
./gradlew --version

# Build with stack trace (for debugging)
./gradlew build --stacktrace

# Build with full debug info
./gradlew build --debug
```

## Common Workflows

### Quick Compile and Run
```bash
./gradlew clean build runMain
```

### Format and Build
```bash
./gradlew format build
```

### Build and Test with Details
```bash
./gradlew clean test --info
```

### Continuous Build (watches for changes)
```bash
./gradlew build --continuous
```

## Gradle Daemon
```bash
# Stop Gradle daemon
./gradlew --stop

# Run without daemon
./gradlew build --no-daemon
```

## Notes
- Use `-q` flag for quiet output (useful for competitive programming)
- Use `--console=plain` for plain console output (no formatting)
- The Gradle wrapper (`./gradlew`) ensures consistent Gradle version across machines
- Build outputs go to `build/` directory
- Compiled classes are in `build/classes/java/main/`
