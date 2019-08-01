CC=g++
CPP_FLAGS=-g -I. -W -Wall -pedantic -std=c++11 -O0 -Wc++11-extensions

%: %*.cpp 
	$(CC) -o run.out $< $(CPP_FLAGS)
	./run.out
	rm run.out
