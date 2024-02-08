files = $(wildcard *.cpp)
CFLAGS = -std=c++11 -c -O2 -Wall -fPIC -D_REENTRANT
LDFLAGS = -L.

.PHONY: all clean

all: test.out

clean:
	rm -f *.o *.a

Measure2.o: Measure2.cpp Measure2.h
	$(CXX) -c $(CFLAGS) $< -o $@

Measure2.a: Measure2.o
	ar rcs $@ $<

test.o: test.cpp 
	$(CXX) $(CFLAGS) $< -o $@

test: test.o Measure2.a
	$(CXX) $(LDFLAGS) $^ -o $@