#!/bin/bash

# C++ Competitive Programming Aliases
# Add these to your ~/.zshrc file

# Navigate to cpp directory
alias cpp="cd /Users/amit2601rai/Workspaces/data-structures-and-algorithms/cpp"

# Quick compile and run (assumes you're in cpp directory)
alias crun='function _crun() { make run FILE="$1"; }; _crun'

# Quick compile, run with input file
alias cruninput='function _cruninput() { make run FILE="$1" INPUT="$2"; }; _cruninput'

# Quick test (with expected output comparison)
alias ctest='function _ctest() { make test FILE="$1"; }; _ctest'

# Quick format
alias cfmt='function _cfmt() { make format FILE="$1"; }; _cfmt'

# Format all files
alias cfmtall='make format-all'

# Quick debug compile and run
alias cdebug='function _cdebug() { make debug FILE="$1"; }; _cdebug'

# Clean build directory
alias cclean='make clean'

# Create new cpp file from template
alias cnew='function _cnew() { ./new_cpp.sh "$1" "$2"; }; _cnew'

# Quick compile and run from anywhere (with full path)
alias cpprun='function _cpprun() { cd /Users/amit2601rai/Workspaces/data-structures-and-algorithms/cpp && make run FILE="$1"; }; _cpprun'

# Quick format from anywhere
alias cppfmt='function _cppfmt() { cd /Users/amit2601rai/Workspaces/data-structures-and-algorithms/cpp && make format FILE="$1"; }; _cppfmt'

# Java aliases
alias java-run='function _javarun() { cd /Users/amit2601rai/Workspaces/data-structures-and-algorithms/java && ./run_java.sh "$1" "${@:2}"; }; _javarun'
alias java-fmt='cd /Users/amit2601rai/Workspaces/data-structures-and-algorithms/java && ./format_java.sh'

echo "C++ Competitive Programming Aliases loaded!"
echo "Usage examples:"
echo "  cpp                          # Navigate to cpp directory"
echo "  crun src/practice/file.cpp   # Compile and run"
echo "  cruninput file.cpp tst/input # Run with input file"
echo "  ctest file.cpp               # Test with expected output"
echo "  cfmt file.cpp                # Format single file"
echo "  cfmtall                      # Format all files"
echo "  cdebug file.cpp              # Debug compile and run"
echo "  cnew Problem.cpp             # Create new file from template"
echo "  cpprun file.cpp              # Run from anywhere"
echo "  java-run practice.Main       # Run Java file"