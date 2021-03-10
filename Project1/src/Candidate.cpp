#include "Candidate.h"

Candidate::Candidate(char p_letter, int votes = 0, std::string c_name)
    : party(p_letter), numVotes(votes), name(c_name) {}

std::string Candidate::getName() { return name; }
char Candidate::getParty() { return party; }
int Candidate::getNumVotes() { return numVotes; }
void Candidate::updateVote(int newVotes) { numVotes = newVotes; }
void Candidate::incrVotes() { numVotes++; }
void Candidate::addBallot(Ballot newBallot) { ballots->push_back(newBallot); }