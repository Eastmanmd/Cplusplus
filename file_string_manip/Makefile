CXXFLAGS+=-Wall -Werror  -Wextra -g -std=c++11

all: bank

bank: main.o account.o bank.o
	$(LINK.cc) -o $@ $^

clean:
	rm -f *.o bank

world: clean all

main.o: main.cpp bank.h account.h
bank.o: bank.cpp bank.h account.h
account.o: account.cpp account.h