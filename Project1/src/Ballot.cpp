#include "Ballot.h"

Ballot::Ballot(std::vector<int> v1) : candidates(v1) {}

void Ballot::incrCurrent() { currBallot++; }

std::vector<int> Ballot::getCandidates() { return candidates; }

int Ballot::getCurrBallotIndex() { return currBallot; }
