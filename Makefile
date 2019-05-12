CFLAGS = -Wall -std=c11 -o
PROGS = char2int int2char excited_echo
COMPILE = gcc $(CFLAGS) $@ $<

all: $(PROGS)

clean: $(PROGS)
	rm $(PROGS)

char2int: char2int.c
	$(COMPILE)

int2char: int2char.c
	$(COMPILE)

excited_echo: excited_echo.c
	$(COMPILE)


