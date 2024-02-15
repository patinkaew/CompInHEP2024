OBJS = $(addsuffix .o,$(basename $(wildcard src/*.cc)))

CFLAGS = -std=c++11 -c -O2 -Wall -fPIC

INC = -Iinterface

LIBS = -L. -lTrack

.PHONY: all clean

all:
	$(MAKE) libTrack.so
	$(CXX) test.cpp $(INC) $(LIBS) -o test.out

clean:
	rm -f *.o *.so $(OBJS)

libTrack.so: $(OBJS)
	$(CXX) -shared $< -o libTrack.so

.cc.o:
	$(CXX) $(CFLAGS) $< -o $@