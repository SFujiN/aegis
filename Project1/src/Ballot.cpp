#include "Ballot.h"

Ballot(std::vector<Candidate> v1) {
    candidates = v1;
}

Candidate getCandidate() {
    return candidates.at(currBallot);
} 
void incrCurrent() {
    currBallot++;
}

