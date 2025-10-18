# Competitive Programming Makefile
# Usage: make run FILE=src/path/to/file.cpp [INPUT=tst/path/input.txt]

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic -g
BUILD_DIR = build
SRC_DIR = src
TST_DIR = tst

# Default target
.PHONY: help
help:
	@echo "Competitive Programming Build System"
	@echo "Usage:"
	@echo "  make run FILE=src/path/to/file.cpp [INPUT=tst/path/input.txt]"
	@echo "  make compile FILE=src/path/to/file.cpp"
	@echo "  make test FILE=src/path/to/file.cpp"
	@echo "  make clean"
	@echo ""
	@echo "Examples:"
	@echo "  make run FILE=src/concepts/dynamic-programming/CoinChange.cpp"
	@echo "  make run FILE=src/practice/codeforces/229Div2/A.cpp INPUT=tst/practice/A_input.txt"
	@echo "  make test FILE=src/concepts/arrays-string-searching-sorting-hashing-backtracking-adhoc/MaxProfitStock.cpp"

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Ensure test directories exist  
$(TST_DIR):
	mkdir -p $(TST_DIR)
	mkdir -p $(TST_DIR)/practice
	mkdir -p $(TST_DIR)/concepts

# Extract filename without extension and path
define get_basename
$(basename $(notdir $(1)))
endef

# Compile a single file
.PHONY: compile
compile: $(BUILD_DIR)
ifndef FILE
	$(error FILE is not set. Usage: make compile FILE=path/to/file.cpp)
endif
	@echo "Compiling $(FILE)..."
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(call get_basename,$(FILE)) $(FILE)
	@echo "✓ Compiled to $(BUILD_DIR)/$(call get_basename,$(FILE))"

# Run with optional input file
.PHONY: run
run: compile
	@echo "Running $(call get_basename,$(FILE))..."
ifdef INPUT
	@if [ -f "$(INPUT)" ]; then \
		echo "Using input from $(INPUT)"; \
		$(BUILD_DIR)/$(call get_basename,$(FILE)) < $(INPUT); \
	else \
		echo "Input file $(INPUT) not found, running without input"; \
		$(BUILD_DIR)/$(call get_basename,$(FILE)); \
	fi
else
	@echo "No input file specified, running interactively"
	$(BUILD_DIR)/$(call get_basename,$(FILE))
endif

# Test with input and expected output (if available)
.PHONY: test
test: compile $(TST_DIR)
ifndef FILE
	$(error FILE is not set. Usage: make test FILE=src/path/to/file.cpp)
endif
	@NAME=$(call get_basename,$(FILE)); \
	if echo "$(FILE)" | grep -q "src/practice"; then \
		TEST_DIR=$(TST_DIR)/practice; \
	elif echo "$(FILE)" | grep -q "src/concepts"; then \
		TEST_DIR=$(TST_DIR)/concepts; \
	else \
		TEST_DIR=$(TST_DIR); \
	fi; \
	INPUT_FILE=$${TEST_DIR}/$${NAME}_input.txt; \
	EXPECTED_FILE=$${TEST_DIR}/$${NAME}_expected.txt; \
	OUTPUT_FILE=$(BUILD_DIR)/$${NAME}_output.txt; \
	\
	echo "Testing $$NAME..."; \
	\
	if [ -f "$$INPUT_FILE" ]; then \
		echo "Using input: $$INPUT_FILE"; \
		$(BUILD_DIR)/$$NAME < $$INPUT_FILE > $$OUTPUT_FILE; \
		\
		if [ -f "$$EXPECTED_FILE" ]; then \
			echo "Comparing with expected output: $$EXPECTED_FILE"; \
			if diff -q $$OUTPUT_FILE $$EXPECTED_FILE > /dev/null; then \
				echo "✓ Test PASSED"; \
			else \
				echo "✗ Test FAILED"; \
				echo "Expected:"; \
				cat $$EXPECTED_FILE; \
				echo "Got:"; \
				cat $$OUTPUT_FILE; \
				echo "Diff:"; \
				diff $$EXPECTED_FILE $$OUTPUT_FILE || true; \
			fi; \
		else \
			echo "No expected output file found ($$EXPECTED_FILE)"; \
			echo "Actual output:"; \
			cat $$OUTPUT_FILE; \
		fi; \
	else \
		echo "No input file found ($$INPUT_FILE), running without input"; \
		$(BUILD_DIR)/$$NAME; \
	fi

# Quick compile and run (for rapid testing)
.PHONY: quick
quick: $(BUILD_DIR)
ifndef FILE
	$(error FILE is not set. Usage: make quick FILE=path/to/file.cpp)
endif
	@echo "Quick build and run of $(FILE)..."
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(call get_basename,$(FILE)) $(FILE) && $(BUILD_DIR)/$(call get_basename,$(FILE))

# Clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)/*
	@echo "✓ Clean completed"

# Debug build (with debug symbols, no optimization)
.PHONY: debug
debug: CXXFLAGS = -std=c++17 -g -Wall -Wextra -pedantic -DDEBUG
debug: compile
	@echo "Debug build completed for $(FILE)"

# Template for new competitive programming file
.PHONY: template
template: 
ifndef NAME
	$(error NAME is not set. Usage: make template NAME=ProblemName [DIR=src/concepts/category])
endif
ifndef DIR
	$(eval DIR := src/concepts/misc-codes)
endif
	@echo "Creating new file: $(DIR)/$(NAME).cpp"
	@mkdir -p $(DIR)
	@cp cpp_template.cpp $(DIR)/$(NAME).cpp
	@echo "✓ Template created at $(DIR)/$(NAME).cpp"

# Create test case files  
.PHONY: create-test
create-test: $(TST_DIR)
ifndef NAME
	$(error NAME is not set. Usage: make create-test NAME=ProblemName [DIR=practice|concepts])
endif
	@DIR_TYPE=$(if $(DIR),$(DIR),concepts); \
	echo "Creating test files for $(NAME) in $${DIR_TYPE}..."; \
	mkdir -p $(TST_DIR)/$${DIR_TYPE}; \
	touch $(TST_DIR)/$${DIR_TYPE}/$(NAME)_input.txt; \
	touch $(TST_DIR)/$${DIR_TYPE}/$(NAME)_expected.txt; \
	echo "✓ Created $(TST_DIR)/$${DIR_TYPE}/$(NAME)_input.txt and $(TST_DIR)/$${DIR_TYPE}/$(NAME)_expected.txt"