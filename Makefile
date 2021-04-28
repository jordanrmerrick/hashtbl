all: build
.PHONY: build

build:
	@gcc -o build/hashtbl src/hashtbl.c

run:
	@./build/hashtbl
