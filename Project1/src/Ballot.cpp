#include "Ballot.h"

Ballot::Ballot(std::vector<int> v1) : candidates(v1) {}

void Ballot::incrCurrent() { currBallot++; }

std::vector<int> Ballot::getCandidates() { return candidates; }

int Ballot::getCurrBallotIndex(){
  candidates[currBallot] - 1; // returns index of candidate in actual candidate vector
}
// [   4,  2,  1 ,  3,  0] 
//    i=0  i=1 i=2 i=3  i=4
 //candidates[ballot1.getCandidates().at(ballot1.getCurrent())-1]