INCLUDE = $(abspath ../include)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: libAOC21.a

libAOC21.a: $(OBJ)
	ar -rcs $?

%.o: %.cpp
	pwd
	g++ -Wall -c -o $@ %< -I$(INCLUDE)

clean:
	rm *.a *.o