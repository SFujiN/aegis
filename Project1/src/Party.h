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

    //Adding/Setting Stuff
    void setSeatsWon(int seats);
    void setRemainder(int num);
    void addCandidate(Candidate *candidate);

    private:
    char name;
    int seatsWon;
    int Remainder;
    std::vector<Candidate*> partyMembers;

};

#endif