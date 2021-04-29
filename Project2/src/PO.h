#ifndef PO_H
#define PO_H

#include "../src/Party.h"
#include "../src/VotingSystem.h"

class PO : public VotingSystem {
  public:
  PO(int candidates);
  void runElection();
  void displayResults();
  void breakTie();
};

#endif