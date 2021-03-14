objects = main.o VotingSystem.o Candidate.o Ballot.o Party.o
CFLAGS = -g -fsanitize=address -fno-omit-frame-pointer
CXXFLAGS = $(CFLAGS)

Aegis : $(objects)
	g++ $(CXXFLAGS) -o Aegis $(objects)

main.o :

VotingSystem.o :

Candidate.o :

Ballot.o :

Party.o :

.PHONY: clean
clean :
	rm Aegis $(objects)
