#!/bin/bash

# Java Google Style Formatter Script
# Usage: ./format_java.sh [file_or_directory]

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

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

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

echo -e "${BLUE}🎨 Java Google Style Formatter${NC}"
echo "================================="

# Check if google-java-format is installed
if ! command -v google-java-format &> /dev/null; then
    print_warning "google-java-format not found. Installing via Maven..."
    
    # Download google-java-format if not present
    FORMATTER_JAR="$SCRIPT_DIR/google-java-format.jar"
    if [ ! -f "$FORMATTER_JAR" ]; then
        print_info "Downloading google-java-format..."
        curl -L "https://github.com/google/google-java-format/releases/download/v1.18.1/google-java-format-1.18.1-all-deps.jar" -o "$FORMATTER_JAR"
        print_success "Downloaded google-java-format"
    fi
    
    FORMATTER_CMD="java -jar $FORMATTER_JAR"
else
    FORMATTER_CMD="google-java-format"
fi

# Determine target (file or directory)
TARGET="${1:-src}"

if [ -f "$TARGET" ]; then
    # Format single file
    print_info "Formatting file: $TARGET"
    $FORMATTER_CMD --replace "$TARGET"
    print_success "Formatted $TARGET"
elif [ -d "$TARGET" ]; then
    # Format all Java files in directory
    print_info "Formatting all Java files in: $TARGET"
    find "$TARGET" -name "*.java" -type f | while read -r file; do
        print_info "Formatting: $file"
        $FORMATTER_CMD --replace "$file"
    done
    print_success "Formatted all Java files in $TARGET"
else
    print_error "Target not found: $TARGET"
    exit 1
fi

# Run Maven format if pom.xml exists (skip if fails due to compatibility issues)
if [ -f "pom.xml" ]; then
    print_info "Running Maven formatter..."
    if mvn fmt:format -q 2>/dev/null; then
        print_success "Maven formatting completed"
    else
        print_warning "Maven formatting failed (likely Java version compatibility), but standalone formatter worked"
    fi
fi

print_success "Java formatting completed!"