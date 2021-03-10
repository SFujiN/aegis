#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <vector>

#include "Ballot.h"

class Candidate{
  public:
    Candidate(char p_letter, int votes = 0, std::string c_name);
    std::string getName();
    char getParty();
    int getNumVotes();
    void updateVote(int);
    void incrVotes();
    void addBallot(Ballot);

  private:
    char party;
    int numVotes;
    std::string name;
    std::vector<Ballot> *ballots;
};

#endif