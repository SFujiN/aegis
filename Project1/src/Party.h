#ifndef PARTY_H
#define PARTY_H
#include <vector>
#include "Candidate.h"
#include "Ballot.h"

class Party{
    public:
    //Getters
    int getNumBallots();
    int getSeatsWon();
    int getRemainder();
    std::vector<Candidate> getPartyMembers();

    //Adding/Setting Stuff
    void setNumBallots(int ballots);
    void setSeatsWon(int seats);
    void setRemainder(int num);
    void addCandidate(Candidate candidate);

    private:
    int numBallots;
    int seatsWon;
    int Remainder;
    std::vector<Candidate> partyMembers;

};

#endif PARTY_H