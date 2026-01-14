#!/bin/bash

# Helper script to compile and run Solution.java
# Usage: ./leetcode-run.sh [input_file]
# Example: ./leetcode-run.sh input
#          echo "test data" | ./leetcode-run.sh

LEETCODE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROJECT_ROOT="$(cd "$LEETCODE_DIR/../.." && pwd)"
OUT_DIR="$PROJECT_ROOT/out"
SOLUTION_FILE="$LEETCODE_DIR/Solution.java"

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Check if Solution.java exists
if [ ! -f "$SOLUTION_FILE" ]; then
    echo -e "${RED}Failed:${NC} Solution.java not found"
    exit 1
fi

# Create out directory if it doesn't exist
mkdir -p "$OUT_DIR"

# Compile all Java files in leetcode directory
javac -d "$OUT_DIR" "$LEETCODE_DIR"/*.java 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}Failed:${NC} Compilation error"
    exit 1
fi

# Run Main class and capture output
ACTUAL_OUTPUT=$(java -cp "$OUT_DIR" leetcode.Main 2>&1)
EXIT_CODE=$?

# Check the exit code to determine success/failure
if [ $EXIT_CODE -eq 0 ]; then
    echo -e "${GREEN}Successful:${NC} All tests passed!"
    echo ""
    echo "$ACTUAL_OUTPUT"
else
    echo -e "${RED}Failed:${NC} Some tests failed or runtime error occurred"
    echo ""
    echo "$ACTUAL_OUTPUT"
    exit 1
fi

