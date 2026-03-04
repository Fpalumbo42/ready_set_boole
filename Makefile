CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
EXDIRS = $(wildcard ex*)

all: $(EXDIRS)

$(EXDIRS):
	@echo "Compiling $@..."
	@if [ -f $@/main.cpp ]; then \
		$(CXX) $(CXXFLAGS) $@/main.cpp -o $@/a.out; \
	else \
		echo "No main.cpp found in $@"; \
	fi

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

dev-%:
	@if [ -f $*/main.cpp ]; then \
		$(CXX) -std=c++98 $*/main.cpp -o $*/a.out; \
	else \
		echo "No main.cpp found in $*"; \
	fi

clean:
	@rm -f ex*/a.out

re: clean all

run-%:
	@if [ -f $*/a.out ]; then \
		./$*/a.out; \
	else \
		echo "Executable $*/a.out not found. Run 'make $*' first."; \
	fi

.PHONY: all clean re $(EXDIRS) ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11
