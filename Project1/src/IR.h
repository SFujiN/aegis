#ifndef IR_H
#define IR_H

#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "Candidate.h"
#include "Ballot.h"
#include "VotingSystem.h"
#include "IR.h"

class IR : public VotingSystem{

public:
IR();

Candidate findWinner();
void elimination();

Candidate breakTie(Candidate a, Candidate b);

private:

int totalBallots;
int numCandidates;
Candidate* elim;



};

#endif