#!/bin/bash

# Java Build and Run Script
# Usage: ./run_java.sh [ClassName] [arguments...]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$SCRIPT_DIR/src/main/java"
BUILD_DIR="$SCRIPT_DIR/build/classes"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Default class if none provided
CLASS_NAME="${1:-practice.HelloWorld}"
shift 2>/dev/null || true  # Remove first argument, ignore error if no args

print_info "Java Build and Run Script"
echo "=========================="

# Create build directory
mkdir -p "$BUILD_DIR"

# Compile all Java files
print_info "Compiling Java files..."
cd "$SCRIPT_DIR"
find "$SRC_DIR" -name "*.java" -print0 | xargs -0 javac -d "$BUILD_DIR" -cp "$BUILD_DIR"

if [ $? -eq 0 ]; then
    print_success "Compilation successful"
else
    print_error "Compilation failed"
    exit 1
fi

# Run the specified class
print_info "Running $CLASS_NAME..."
cd "$BUILD_DIR"
java "$CLASS_NAME" "$@"

print_success "Execution completed"