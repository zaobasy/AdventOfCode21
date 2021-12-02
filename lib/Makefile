INCLUDE = ../include

all: libAOC21.a

libAOC21.a: *.o
	ar rcs *.o

*.o: %.cpp
	g++ -c -o %.o %.cpp -I$(INCLUDE)


clean:
	rm *.a *.o