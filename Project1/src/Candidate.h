#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <vector>

#include "Ballot.h"

class Candidate{
  public:
    Candidate(char p_letter, std::string c_name, int ballots = 0);
    std::string getName();
    char getParty();
    int getNumBallots();
    void updateBallots(int);
    void incrBallots();
    void addBallot(Ballot);

    bool operator==(const Candidate& rhs) const;

  private:
    char party;
    int numBallots;
    std::string name;
    std::vector<Ballot> ballots;
};

#endif