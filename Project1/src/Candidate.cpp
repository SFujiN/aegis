#include "Candidate.h"

Candidate::Candidate(char p_letter, std::string c_name, int ballots = 0)
    : party(p_letter), name(c_name), numBallots(ballots) {}

std::string Candidate::getName() { return name; }
char Candidate::getParty() { return party; }
int Candidate::getNumBallots() { return numBallots; }
void Candidate::updateBallots(int newBallots) { numBallots = newBallots; }
void Candidate::incrBallots() { numBallots++; }
void Candidate::addBallot(Ballot newBallot) { ballots.push_back(newBallot); }