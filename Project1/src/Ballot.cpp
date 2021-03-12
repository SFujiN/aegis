#include "Ballot.h"

Ballot::Ballot(std::vector<int> v1) : candidates(v1) {}
void Ballot::incrCurrent() { currBallot++; }
int Ballot::getCurrent() { return currBallot; }
std::vector<int> Ballot::getCandidates() { return candidates; }
int Ballot::getCurrBallotIndex(){
  candidates[currBallot] - 1;
}
 //candidates[ballot1.getCandidates().at(ballot1.getCurrent())-1]