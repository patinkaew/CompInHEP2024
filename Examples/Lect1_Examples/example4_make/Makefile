SRC = $(wildcard *.cpp)
OBJECTS = $(addsuffix .o $(basename $(SRC)))

all:
	@$(MAKE) compile --no-print-directory
	@$(MAKE) hello --no-print-directory
	@$(MAKE) run --no-print-directory

.cpp.o:
	$(CXX) -c $<

test:
	echo $(OBJECTS)

compile: hello.o


hello: hello.o
	$(CXX) hello.o -o hello

run:
	@./hello

GARBAGE = $(wildcard *.o *~)
clean:
	rm $(GARBAGE)
