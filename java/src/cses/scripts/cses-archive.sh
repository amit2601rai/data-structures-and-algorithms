#!/bin/bash

# Script to archive a solved CSES problem
# Usage: ./cses-archive.sh <ProblemName>
# Example: ./cses-archive.sh TreeDiameter

CSES_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SOLUTION_FILE="$CSES_DIR/Solution.java"
SOLVED_DIR="$CSES_DIR/solved"

# Check if problem name is provided
if [ -z "$1" ]; then
    echo "2/Failure: Problem name required"
    echo "Usage: ./cses-archive.sh <ProblemName>"
    echo "Example: ./cses-archive.sh TreeDiameter"
    exit 1
fi

PROBLEM_NAME="$1"

# Check if Solution.java exists
if [ ! -f "$SOLUTION_FILE" ]; then
    echo "2/Failure: Solution.java not found in $CSES_DIR"
    exit 1
fi

# Create solved directory if it doesn't exist
mkdir -p "$SOLVED_DIR"

# New file name
NEW_FILE="$SOLVED_DIR/${PROBLEM_NAME}.java"

# Check if target file already exists
if [ -f "$NEW_FILE" ]; then
    echo "⚠️  Warning: $NEW_FILE already exists!"
    read -p "Do you want to overwrite it? (y/N): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo "Aborted. No changes made."
        exit 1
    fi
fi

# Copy Solution.java to solved directory with new name and add package
echo "package cses.solved;" > "$NEW_FILE"
echo "" >> "$NEW_FILE"
# Skip any existing package declaration and copy rest
sed '/^package /d' "$SOLUTION_FILE" >> "$NEW_FILE"

# Replace class name in the new file
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' "s/public class Solution/public class $PROBLEM_NAME/g" "$NEW_FILE"
else
    # Linux
    sed -i "s/public class Solution/public class $PROBLEM_NAME/g" "$NEW_FILE"
fi

echo "1/Success: Archived solution as $PROBLEM_NAME"
echo "📁 Location: $NEW_FILE"
echo ""

# Ask if user wants to create a new Solution.java
read -p "Create a new Solution.java template? (Y/n): " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]] || [[ -z $REPLY ]]; then
    # Call cses-new.sh to create new template
    bash "$(dirname "$0")/cses-new.sh"
else
    echo "💡 Tip: Run ./cses-new.sh when ready to start a new problem"
fi

