#!/bin/bash

# Script to create a new C++ competitive programming file from template
# Usage: ./new_cpp.sh <filename> [directory]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEMPLATE_FILE="$SCRIPT_DIR/cpp_template.cpp"

# Function to print colored output
print_info() {
    echo -e "\033[1;34m[INFO]\033[0m $1"
}

print_success() {
    echo -e "\033[1;32m[SUCCESS]\033[0m $1"
}

print_error() {
    echo -e "\033[1;31m[ERROR]\033[0m $1"
}

# Check if filename is provided
if [ $# -eq 0 ]; then
    print_error "Usage: $0 <filename> [directory]"
    print_info "Example: $0 problem1.cpp"
    print_info "Example: $0 problem1.cpp src/practice/codeforces/"
    print_info "Example: $0 problem1.cpp src/concepts/dynamic-programming/"
    exit 1
fi

FILENAME="$1"
DIRECTORY="${2:-src/concepts/misc-codes}"  # Default to src/concepts/misc-codes if not specified

# Ensure filename has .cpp extension
if [[ "$FILENAME" != *.cpp ]]; then
    FILENAME="${FILENAME}.cpp"
fi

# Create target directory if it doesn't exist
TARGET_DIR="$SCRIPT_DIR/$DIRECTORY"
mkdir -p "$TARGET_DIR"

TARGET_FILE="$TARGET_DIR/$FILENAME"

# Check if file already exists
if [ -f "$TARGET_FILE" ]; then
    print_error "File $TARGET_FILE already exists!"
    exit 1
fi

# Check if template exists
if [ ! -f "$TEMPLATE_FILE" ]; then
    print_error "Template file $TEMPLATE_FILE not found!"
    exit 1
fi

# Copy template to new file
cp "$TEMPLATE_FILE" "$TARGET_FILE"

print_success "Created new C++ file: $TARGET_FILE"
print_info "Template copied from: $TEMPLATE_FILE"

# Open in VS Code if available
if command -v code &> /dev/null; then
    print_info "Opening in VS Code..."
    code "$TARGET_FILE"
fi