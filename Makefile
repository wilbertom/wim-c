
WARNING_FLAGS := -Wall -Wextra -Wpedantic
DEBUG_FLAGS := -O0 -g
FLAGS := $(WARNING_FLAGS) $(DEBUG_FLAGS) -std=c23

gitignore:
	mkdir -p output
	CC $(FLAGS) -o output/gitignore clis/gitignore/src/*.c
