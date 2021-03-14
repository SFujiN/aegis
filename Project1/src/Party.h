#ifndef PARTY_H
#define PARTY_H
#include <vector>

#include "Candidate.h"

class Party{
    public:
    Party(char p);
    //Getters
    char getPartyName();
    int getNumBallots();
    int getSeatsWon();
    int getRemainder();
    std::vector<Candidate*> getPartyMembers();
    void sortByVotes();

    //Adding/Setting Stuff
    void setSeatsWon(int seats);
    void setRemainder(int num);
    void setNumBallots(int num);
    void addCandidate(Candidate *candidate);

    private:
    int numBallots;
    char name;
    int seatsWon = 0;
    int Remainder = 0;
    std::vector<Candidate*> partyMembers;

};

#endif