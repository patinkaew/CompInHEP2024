CFLAGS = -O2 -Wall -fPIC -D_REENTRANT
#LDFLAGS = 

.PHONY: all clean

all: hello

clean:
	rm -f *.o

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

hello: hello.o
	$(CXX) $(LDFLAGS) -O $< -o $@