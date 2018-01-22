
#standard vars
CC = gcc
CFLAGS = -Wall
LDLIBS = -lm

# custom vars
target = ex02sqrt
cfile = ex02sqrt.c
test = ex02sqrt-test

$(target): $(cfile)
	$(CC) $(cfile) -o $(target) $(LDLIBS)

$(test): $(target)
	echo "Running test for square root of 5 to 3 decimal places"
	./ex02sqrt 5 3

# tidy up
.PHONY: clean
clean:
	$(RM) $(target)

