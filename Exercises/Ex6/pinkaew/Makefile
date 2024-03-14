files = $(wildcard *.cc *.cpp)
OBJS = $(addsuffix .o,$(basename $(files)))

OPT = -O -Wall -fPIC

ROOTINC := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --glibs)

INC = -I. $(ROOTINC)

LIBS = -L. $(ROOTLIBS)

.cc.o:
	$(CXX) $(OPT) $(INC) -c $*.cc

.cpp.o:
	$(CXX) $(OPT) $(INC) -c $*.cpp

.o.out:
	$(CXX) *.o $(INC) $(LIBS) -o $@
	
all:
	$(MAKE) random; $(MAKE) plot

random: random_norm.out
	./random_norm.out

plot: plot_norm.out
	./plot_norm.out

clean:
	rm -f *.o *.so $(OBJS)

cleanAll:
	$(MAKE) clean; rm -f *.out

