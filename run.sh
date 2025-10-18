#!/bin/bash

# CP Runner - Competitive Programming Build and Run Script
# Usage: ./run.sh <file.cpp> [input.txt]

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Configuration
CXX="g++"
CXXFLAGS="-std=c++17 -O2 -Wall -Wextra -pedantic -g"
BUILD_DIR="build"
SRC_DIR="src"
TST_DIR="tst"

# Helper functions
print_usage() {
    echo "CP Runner - Competitive Programming Build and Run Script"
    echo ""
    echo "Usage:"
    echo "  $0 <file.cpp> [input.txt]                 # Compile and run"
    echo "  $0 -t <file.cpp>                          # Run tests"
    echo "  $0 -d <file.cpp>                          # Debug build"
    echo "  $0 -c                                     # Clean build directory"
    echo "  $0 -h                                     # Show this help"
    echo ""
    echo "Examples:"
    echo "  $0 src/concepts/dynamic-programming/CoinChange.cpp"
    echo "  $0 src/practice/codeforces/229Div2/A.cpp tst/input"
    echo "  $0 -t src/concepts/arrays-string-searching-sorting-hashing-backtracking-adhoc/MaxProfitStock.cpp"
}

print_error() {
    echo -e "${RED}Error: $1${NC}" >&2
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_info() {
    echo -e "${BLUE}➤ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠ $1${NC}"
}

# Get basename without extension
get_basename() {
    basename "$1" .cpp
}

# Ensure directories exist
ensure_dirs() {
    mkdir -p "$BUILD_DIR"
    mkdir -p "$TESTCASES_DIR"
}

# Compile function
compile_file() {
    local file="$1"
    local debug="$2"
    
    if [[ ! -f "$file" ]]; then
        print_error "File $file not found"
        return 1
    fi
    
    local basename=$(get_basename "$file")
    local output="$BUILD_DIR/$basename"
    
    local flags="$CXXFLAGS"
    if [[ "$debug" == "true" ]]; then
        flags="-std=c++17 -g -Wall -Wextra -pedantic -DDEBUG"
        print_info "Debug mode enabled"
    fi
    
    print_info "Compiling $file..."
    if $CXX $flags -o "$output" "$file"; then
        print_success "Compiled to $output"
        return 0
    else
        print_error "Compilation failed"
        return 1
    fi
}

# Run function
run_file() {
    local file="$1"
    local input_file="$2"
    
    local basename=$(get_basename "$file")
    local executable="$BUILD_DIR/$basename"
    
    if [[ ! -f "$executable" ]]; then
        print_error "Executable $executable not found. Compile first."
        return 1
    fi
    
    print_info "Running $basename..."
    
    if [[ -n "$input_file" ]]; then
        if [[ -f "$input_file" ]]; then
            print_info "Using input from $input_file"
            "$executable" < "$input_file"
        else
            print_warning "Input file $input_file not found, running without input"
            "$executable"
        fi
    else
        print_info "Running interactively (press Ctrl+C to exit)"
        "$executable"
    fi
}

# Test function
test_file() {
    local file="$1"
    local basename=$(get_basename "$file")
    local executable="$BUILD_DIR/$basename"
    
    local input_file="$TST_DIR/input"
    local expected_file="$TST_DIR/output"
    local output_file="$BUILD_DIR/${basename}_output.txt"
    
    if [[ ! -f "$executable" ]]; then
        print_error "Executable $executable not found. Compile first."
        return 1
    fi
    
    print_info "Testing $basename..."
    
    if [[ -f "$input_file" ]]; then
        print_info "Using input: $input_file"
        "$executable" < "$input_file" > "$output_file"
        
        if [[ -f "$expected_file" ]]; then
            print_info "Comparing with expected output: $expected_file"
            if diff -q "$output_file" "$expected_file" > /dev/null; then
                print_success "Test PASSED"
            else
                print_error "Test FAILED"
                echo "Expected:"
                cat "$expected_file"
                echo ""
                echo "Got:"
                cat "$output_file"
                echo ""
                echo "Diff:"
                diff "$expected_file" "$output_file" || true
            fi
        else
            print_warning "No expected output file found ($expected_file)"
            echo "Actual output:"
            cat "$output_file"
        fi
    else
        print_warning "No input file found ($input_file), running without input"
        "$executable"
    fi
}

# Clean function
clean_build() {
    print_info "Cleaning build directory..."
    rm -rf "$BUILD_DIR"/*
    print_success "Clean completed"
}

# Main script
main() {
    ensure_dirs
    
    case "$1" in
        -h|--help)
            print_usage
            exit 0
            ;;
        -c|--clean)
            clean_build
            exit 0
            ;;
        -t|--test)
            if [[ -z "$2" ]]; then
                print_error "No file specified for testing"
                print_usage
                exit 1
            fi
            compile_file "$2" false && test_file "$2"
            ;;
        -d|--debug)
            if [[ -z "$2" ]]; then
                print_error "No file specified for debug build"
                print_usage
                exit 1
            fi
            compile_file "$2" true && run_file "$2" "$3"
            ;;
        "")
            print_usage
            exit 1
            ;;
        *)
            # Normal compile and run
            if [[ -z "$1" ]]; then
                print_error "No file specified"
                print_usage
                exit 1
            fi
            compile_file "$1" false && run_file "$1" "$2"
            ;;
    esac
}

# Run main function with all arguments
main "$@"