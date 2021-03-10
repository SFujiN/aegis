#include "Candidate.h"

Candidate::Candidate(char p_letter, int ballots = 0, std::string c_name)
    : party(p_letter), numBallots(ballots), name(c_name) {}

std::string Candidate::getName() { return name; }
char Candidate::getParty() { return party; }
int Candidate::getNumBallots() { return numBallots; }
void Candidate::updateBallots(int newBallots) { numBallots = newBallots; }
void Candidate::incrBallots() { numBallots++; }
void Candidate::addBallot(Ballot newBallot) { ballots->push_back(newBallot); }