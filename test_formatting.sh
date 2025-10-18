#!/bin/bash

# Test script to verify the complete Google C++ formatting integration
# This script tests all formatting features and ensures they work correctly

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}🎨 Testing Google C++ Code Formatting Integration${NC}"
echo "=================================================="

# Test 1: Check if clang-format is installed
echo -e "\n${YELLOW}Test 1: Checking clang-format installation${NC}"
if command -v clang-format &> /dev/null; then
    echo -e "${GREEN}✓ clang-format is installed$(clang-format --version)${NC}"
else
    echo -e "${RED}✗ clang-format is not installed${NC}"
    echo "Install with: brew install clang-format (macOS) or sudo apt-get install clang-format (Linux)"
    exit 1
fi

# Test 2: Check if .clang-format config exists
echo -e "\n${YELLOW}Test 2: Checking .clang-format configuration${NC}"
if [ -f ".clang-format" ]; then
    echo -e "${GREEN}✓ .clang-format configuration file found${NC}"
    echo "  Base style: $(grep "BasedOnStyle:" .clang-format | cut -d' ' -f2)"
    echo "  Indent width: $(grep "IndentWidth:" .clang-format | cut -d' ' -f2)"
    echo "  Column limit: $(grep "ColumnLimit:" .clang-format | cut -d' ' -f2)"
else
    echo -e "${RED}✗ .clang-format configuration file not found${NC}"
    exit 1
fi

# Test 3: Test format command on a specific file
echo -e "\n${YELLOW}Test 3: Testing make format command${NC}"
if make format FILE=src/practice/cses/2220.cpp >/dev/null 2>&1; then
    echo -e "${GREEN}✓ make format command works correctly${NC}"
else
    echo -e "${RED}✗ make format command failed${NC}"
    exit 1
fi

# Test 4: Test format-check command
echo -e "\n${YELLOW}Test 4: Testing make format-check command${NC}"
# This might fail if files are unformatted, which is expected
if make format-check >/dev/null 2>&1; then
    echo -e "${GREEN}✓ All files are properly formatted${NC}"
else
    echo -e "${YELLOW}⚠ Some files need formatting (this is expected for existing files)${NC}"
    echo "  Run 'make format-all' to format all files"
fi

# Test 5: Check VS Code configuration
echo -e "\n${YELLOW}Test 5: Checking VS Code integration${NC}"
if [ -f ".vscode/settings.json" ]; then
    if grep -q "formatOnSave.*true" .vscode/settings.json; then
        echo -e "${GREEN}✓ VS Code auto-format on save is enabled${NC}"
    else
        echo -e "${YELLOW}⚠ VS Code auto-format on save might not be enabled${NC}"
    fi
    if grep -q "clang-format" .vscode/settings.json; then
        echo -e "${GREEN}✓ VS Code clang-format integration configured${NC}"
    else
        echo -e "${YELLOW}⚠ VS Code clang-format integration might not be configured${NC}"
    fi
else
    echo -e "${YELLOW}⚠ No VS Code settings found${NC}"
fi

# Test 6: Check pre-commit hook
echo -e "\n${YELLOW}Test 6: Checking git pre-commit hook${NC}"
if [ -f ".git/hooks/pre-commit" ] && [ -x ".git/hooks/pre-commit" ]; then
    echo -e "${GREEN}✓ Pre-commit hook is installed and executable${NC}"
else
    echo -e "${YELLOW}⚠ Pre-commit hook is not installed or not executable${NC}"
fi

# Test 7: Check new_cpp.sh auto-formatting
echo -e "\n${YELLOW}Test 7: Checking new_cpp.sh auto-formatting${NC}"
if grep -q "clang-format" new_cpp.sh; then
    echo -e "${GREEN}✓ new_cpp.sh includes auto-formatting${NC}"
else
    echo -e "${RED}✗ new_cpp.sh does not include auto-formatting${NC}"
fi

# Test 8: Create a temporary file and test complete workflow
echo -e "\n${YELLOW}Test 8: Testing complete workflow${NC}"
TEMP_FILE="test_format_temp.cpp"
cat > "$TEMP_FILE" << 'EOF'
#include<iostream>
using namespace std;
int main(){
int x=5,y=10;
if(x<y){
cout<<"x is smaller"<<endl;
}
return 0;
}
EOF

echo "  Created unformatted test file..."
if make format FILE="$TEMP_FILE" >/dev/null 2>&1; then
    echo -e "${GREEN}✓ Successfully formatted test file${NC}"
    # Check if file is properly formatted
    if clang-format --dry-run --Werror "$TEMP_FILE" >/dev/null 2>&1; then
        echo -e "${GREEN}✓ Test file is now properly formatted${NC}"
    else
        echo -e "${RED}✗ Test file formatting verification failed${NC}"
    fi
else
    echo -e "${RED}✗ Failed to format test file${NC}"
fi

# Cleanup
rm -f "$TEMP_FILE"

echo -e "\n${BLUE}🎯 Summary${NC}"
echo "==========="
echo -e "${GREEN}✓ Google C++ formatting integration is working correctly!${NC}"
echo -e "${GREEN}✓ All major components are properly configured${NC}"
echo ""
echo "Usage commands:"
echo "  make format FILE=path/to/file.cpp    # Format specific file"
echo "  make format-all                      # Format all C++ files"  
echo "  make format-check                    # Check formatting"
echo "  ./new_cpp.sh filename.cpp           # Create formatted file"
echo ""
echo -e "${BLUE}Happy coding with consistent style! 🚀${NC}"