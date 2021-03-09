objects = main.o
CFLAGS = -g -fsanitize=address -fno-omit-frame-pointer
CXXFLAGS = $(CFLAGS)

Aegis : $(objects)
	g++ $(CXXFLAGS) -o Aegis $(objects)

main.o :

.PHONY: clean
clean :
	rm Aegis $(objects)
