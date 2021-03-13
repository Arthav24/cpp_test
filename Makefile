CXX := g++
CFLAGS := -std=c++14 -g
LDFLAGS := 


all: func.o test

test:test.cpp func.o 
	$(CXX) $(CFLAGS) $(LDFLAGS) $^ -o $@
func.o: func.cpp
	$(CXX) $(CFLAGS) -c $(LDFLAGS) $^ -o $@ 

run: test
	./test

.PHONY: clean

clean:
	-rm -fr test *.o *.stackdump
