CFLAGS = -g 

aprog : string_t.o string_t_main.o
	g++ -o aprog  string_t.o string_t_main.o

string_t.o : string_t.cpp string_t.h
	g++ -c $(CFLAGS)  string_t.cpp

string_t_main.o : string_t_main.cpp string_t.h
	g++ -c $(CFLAGS) string_t_main.cpp
