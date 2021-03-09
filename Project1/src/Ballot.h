#ifndef BALLOT_H
#define BALLOT_H

#include <vector>

#include "Candidate.h"

class Ballot{
    public: 
        // constructor
        Ballot(std::vector<Candidate> *v1);

        // getter methods
        Candidate getCandidate(); 

        // setters methods
        void incrCurrent();

    private:
        std::vector<Candidate> *candidates;
        int currBallot = 0;

};

#endif