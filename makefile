
all: tlist_test

tlist_test: example.o
	gcc -o $@ $^

example.o: example.c tlist.h
	gcc -c $^ -Wall

clean:
	rm -rf example.o tlist_test

.PHONY: all clean
