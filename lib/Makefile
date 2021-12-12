INCLUDE=$(abspath ../include)

CPPFLAGS= -Wall -std=c++11 -I$(INCLUDE)

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(OBJ:.o=.d)

all: libAOC21.a

libAOC21.a: $(OBJ)
	ar r libAOC21.a $?

%.o: %.cpp
	g++ $(CPPFLAGS) -o $@ -c $<  

clean:
	rm *.a *.o