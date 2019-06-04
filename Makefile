PROGS = char2int int2char excited_echo int2hex hex2int dns pim netend
COMPILE = gcc -Wall -std=c11 -o $@ $<
COMPILECPP = g++ -Wall -std=c++11 -o $@ $<

all: $(PROGS)

clean: $(PROGS)
	rm $(PROGS)

char2int: char2int.c
	$(COMPILE)

int2char: int2char.c
	$(COMPILE)

excited_echo: excited_echo.c
	$(COMPILE)

int2hex: int2hex.c
	$(COMPILE)

hex2int: hex2int.c
	$(COMPILE)

dns: dns.cc
	$(COMPILECPP)

pim : pim.cc
	$(COMPILECPP)

netend : netend.c
	$(COMPILE)