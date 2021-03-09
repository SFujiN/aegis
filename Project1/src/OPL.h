#ifndef OPL_H
#define OPL_H
//TODO: delete these and put in votingSystem
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

#include "Party.h"

class OPL : public VotingSystem {
 public:
  void groupIndependentParties();
  void allocateSeats();
  void findPartyWinners();
  bool sortRemainder(Party first, Party second) {
    return first.getRemainder() < second.getRemainder();
  }
  bool sortNumBallots(Party first, Party second) {
    return first.getNumBallots() < second.getNumBallots();
  }

 private:
  int numSeats;
  int quota;
  std::vector<Party> parties;
  int numCandidates;
};

#endif OPL_H