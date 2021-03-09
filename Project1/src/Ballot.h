#ifndef BALLOT_H
#define BALLOT_H
#include "Candidate.h"
#include <vector>

class Ballot{
    public: 
        // constructor
        Ballot(std::vector<Candidates> v1);

        // getter methods
        Candidate getCandidate(); 

        // setters methods
        void incrCurrent();

    private:
        std::vector<Candidate> candidates = nullptr;
        int currBallot = 0;

}

#endif BALLOT_H