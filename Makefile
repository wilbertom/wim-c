
all:
	mkdir -p output
	CC -o output/gitignore clis/gitignore/src/*.c
