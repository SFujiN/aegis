#include "Ballot.h"

Ballot(std::vector<Candidate> v1) {
    candidates = v1;
}

Candidate Ballot::getCandidate() {
    return candidates.at(currBallot);
} 
void Ballot::incrCurrent() {
    currBallot++;
}

