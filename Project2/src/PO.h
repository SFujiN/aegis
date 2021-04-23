#ifndef PO_H
#define PO_H

#include "../src/Party.h"
#include "../src/VotingSystem.h"

class PO : public VotingSystem {
  public:
  PO(int candidates, int ballots);

  void runElection();
  void displayResults();
};

#endif