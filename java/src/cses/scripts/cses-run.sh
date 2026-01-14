#!/bin/bash

# Helper script to compile and run Solution.java
# Usage: ./cses-run.sh [input_file]
# Example: ./cses-run.sh input
#          echo "5\n1 2\n1 3\n3 4\n3 5" | ./cses-run.sh

CSES_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROJECT_ROOT="$(cd "$CSES_DIR/../.." && pwd)"
OUT_DIR="$PROJECT_ROOT/out"
SOLUTION_FILE="$CSES_DIR/Solution.java"

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

# Compile
javac -d "$OUT_DIR" "$SOLUTION_FILE" 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}Failed:${NC} Compilation error"
    exit 1
fi

# Run with input file or stdin and capture output
ACTUAL_OUTPUT=""
if [ -n "$1" ]; then
    if [ ! -f "$1" ]; then
        echo -e "${RED}Failed:${NC} Input file '$1' not found"
        exit 1
    fi
    ACTUAL_OUTPUT=$(java -cp "$OUT_DIR" Solution < "$1" 2>&1)
elif [ -f "$CSES_DIR/input" ]; then
    # Auto-use input if it exists and no argument provided
    ACTUAL_OUTPUT=$(java -cp "$OUT_DIR" Solution < "$CSES_DIR/input" 2>&1)
else
    ACTUAL_OUTPUT=$(java -cp "$OUT_DIR" Solution 2>&1)
fi

# Check for runtime errors
if [ $? -ne 0 ]; then
    echo -e "${RED}Failed:${NC} Runtime error"
    echo "$ACTUAL_OUTPUT"
    exit 1
fi

# Compare with expected output if it exists
if [ -f "$CSES_DIR/output" ]; then
    EXPECTED_OUTPUT=$(cat "$CSES_DIR/output")

    # Normalize whitespace for comparison (trim trailing whitespace and newlines)
    ACTUAL_NORMALIZED=$(echo "$ACTUAL_OUTPUT" | sed 's/[[:space:]]*$//')
    EXPECTED_NORMALIZED=$(echo "$EXPECTED_OUTPUT" | sed 's/[[:space:]]*$//')

    if [ "$ACTUAL_NORMALIZED" = "$EXPECTED_NORMALIZED" ]; then
        echo -e "${GREEN}Successful:${NC} Output matches expected result"
    else
        echo -e "${RED}Failed:${NC} Output does not match expected result"
        echo ""
        echo "Expected:"
        echo "$EXPECTED_OUTPUT"
        echo ""
        echo "Actual:"
        echo "$ACTUAL_OUTPUT"
        exit 1
    fi
else
    # No expected output file, just show that it ran successfully
    echo -e "${GREEN}Successful:${NC} Code executed without errors"
    echo ""
    echo "Output:"
    echo "$ACTUAL_OUTPUT"
fi

