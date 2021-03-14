#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <vector>

#include "Ballot.h"

class Candidate{
  public:
    Candidate(char p_letter, std::string c_name);
    std::string getName();
    char getParty();
    int getNumBallots();
    void addBallot(Ballot ballot);
    void negateStatus();
    bool operator<(Candidate& r);

  private:
    char party;
    std::string name;
    bool status;
    std::vector<Ballot> ballots;
};

#endif