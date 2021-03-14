#include "Ballot.h"

Ballot::Ballot(std::vector<int> v1) : candidates(v1) {}

void Ballot::incrCurrent() {
  //std::cout << "currBallotBefore" << currBallot << std::endl;
  currBallot++;
  //std::cout << "currBallotAfter" << currBallot << std::endl;
}

std::vector<int> Ballot::getCandidates() { return candidates; }
int Ballot::getCurrBallotIndex() {
  return candidates[currBallot] - 1;  // returns index of candidate in actual candidate vector
}
// [   4,  2,  1 ,  3,  0]
//    i=0  i=1 i=2 i=3  i=4
// candidates[ballot1.getCandidates().at(ballot1.getCurrent())-1]

void Ballot::printBallot() {
  for (int i = 0; i < candidates.size(); i++) {
    std::cout << "candidate[" << i << "]: " << candidates[i] << std::endl;
  }
}

int Ballot::getCurrBallot() { return currBallot; }
