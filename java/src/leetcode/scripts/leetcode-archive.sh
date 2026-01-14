#!/bin/bash

# Script to archive a solved LeetCode problem
# Usage: ./leetcode-archive.sh <ProblemName>
# Example: ./leetcode-archive.sh AddTwoNumbers

LEETCODE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SOLVED_DIR="$LEETCODE_DIR/solved"

# Check if problem name is provided
if [ -z "$1" ]; then
    echo "2/Failure: Problem name required"
    echo "Usage: ./leetcode-archive.sh <ProblemName>"
    echo "Example: ./leetcode-archive.sh AddTwoNumbers"
    exit 1
fi

PROBLEM_NAME="$1"
PROBLEM_DIR="$SOLVED_DIR/$PROBLEM_NAME"

# Check if Solution.java exists
if [ ! -f "$LEETCODE_DIR/Solution.java" ]; then
    echo "2/Failure: Solution.java not found in $LEETCODE_DIR"
    exit 1
fi

# Create problem directory under solved/
if [ -d "$PROBLEM_DIR" ]; then
    echo "⚠️  Warning: $PROBLEM_DIR already exists!"
    read -p "Do you want to overwrite it? (y/N): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo "Aborted. No changes made."
        exit 1
    fi
    rm -rf "$PROBLEM_DIR"
fi

mkdir -p "$PROBLEM_DIR"

# Find and copy all Java files in leetcode directory
ARCHIVED_FILES=()
for file in "$LEETCODE_DIR"/*.java; do
    if [ -f "$file" ]; then
        BASENAME=$(basename "$file")
        TARGET_FILE="$PROBLEM_DIR/$BASENAME"

        # Update package declaration from "package leetcode;" to "package leetcode.solved.<ProblemName>;"
        {
            echo "package leetcode.solved.$PROBLEM_NAME;"
            echo ""
            # Skip the original package line and copy rest
            tail -n +2 "$file"
        } > "$TARGET_FILE"

        ARCHIVED_FILES+=("$BASENAME")
    fi
done

echo "1/Success: Archived solution in folder $PROBLEM_NAME"
echo "📁 Location: $PROBLEM_DIR"
echo "📝 Files archived:"
for file in "${ARCHIVED_FILES[@]}"; do
    echo "  - $file"
done
echo ""

# Ask if user wants to create a new Solution.java
read -p "Create a new Solution.java template? (Y/n): " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]] || [[ -z $REPLY ]]; then
    # Call leetcode-new.sh to create new template
    bash "$(dirname "$0")/leetcode-new.sh"
else
    echo "💡 Tip: Run ./leetcode-new.sh when ready to start a new problem"
fi



