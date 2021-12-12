INCLUDE=$(abspath ../include)
LIB=../lib/

CPPFLAGS=-Wall -std=c++11 -I$(INCLUDE)
LNFLAGS=-g -L$(LIB) -lAOC21 

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(OBJ:.o=.d)

BINS=Day1 Day2 Day3

all: $(BINS)

%.o: %.cpp
	g++ $(CPPFLAGS) -o $@ -c $< 

Day1: Day1.o
	g++ $(LNFLAGS) -o Day1 Day1.o 

Day2: Day2.o
	g++ $(LNFLAGS) -o Day2 Day2.o

Day3: Day3.o
	g++ $(LNFLAGS) -o Day3 Day3.o

clean:
	rm $(BINS)