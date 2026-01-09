# Compiler
CXX = g++
CC = gcc
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS = -Wall -Wextra -Werror -std=c11

# Find all exercise directories
EXDIRS = $(wildcard ex*)

# Default target
all: $(EXDIRS)

# Rule for each exercise directory
$(EXDIRS):
	@echo "Compiling $@..."
	@if [ -f $@/main.cpp ]; then \
		$(CXX) $(CXXFLAGS) $@/main.cpp -o $@/a.out; \
	elif [ -f $@/main.c ]; then \
		$(CC) $(CFLAGS) $@/main.c -o $@/a.out; \
	else \
		echo "No main.cpp or main.c found in $@"; \
	fi

# Individual exercise targets
ex00: ex00
ex01: ex01
ex02: ex02
ex03: ex03
ex04: ex04
ex05: ex05
ex06: ex06
ex07: ex07
ex08: ex08
ex09: ex09
ex10: ex10
ex11: ex11

# Clean all executables
clean:
	@echo "Cleaning executables..."
	@rm -f ex*/a.out

# Rebuild everything
re: clean all

# Run specific exercise
run-%:
	@if [ -f $*/a.out ]; then \
		./$*/a.out; \
	else \
		echo "Executable $*/a.out not found. Run 'make $*' first."; \
	fi

.PHONY: all clean re $(EXDIRS) ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11
